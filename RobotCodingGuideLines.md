---
Title: Robot Coding GuideLines
category: pages
layout: default
---
## Robot Coding GuideLines

# Swerve module

* Speed should be in meters per second, not meters per minute.
* Internally to the SwerveModule class, Swerve module steer position should be in rotations with a range of [-0.5, 0.5). This is the unit the CANCoder and Spark Max use. External to the SwerveModule, use radians [-Pi, Pi).
* Use closed loop on the Spark Max motor controller, not a PIDController on the roboRIO. There are several reason you probably want to do this:
    * You pay big money for smart motor controllers, so use them.
    * On the motor controller the encoder value is read directly, it doesn't have to come over the CAN network first.
    * Motor controller closed loop runs at 1000Hz where the roboRIO only runs at 50hz.
    * Let the motors and encoders handle your offsets and inversions. Configure them once, and let them handle the math.
* Use the CANCoders waitForUpdate() function when getting it's absolute position on startup.
* Set offsets in rotations (avoiding conversion from degrees to radians to rotations.) There was also some math going on to rotate them by pi/2 radians.
* Set CANCoder absolute encoder SensorDirection to CounterClockwise_Positive
* **Set Drive and Steer motor inversion (so positive output is forward drive and counter-clockwise steer)**
* **Correct SwerveDriveKinemetics. Forward is +X, left is +Y**
    * **BR is (-, -)**
    * **FR is (+, -)**
    * **BL is (-, +)**
    * **FL is (+, +)**
* **Correct conversion from CANCoder position to steer motor encoder position. It was incorrectly converting from rotations to radians, but both are rotations.**
* **Return steer position in a Rotation2d object from getSteerPosition() so the units are always clear (and since all uses of the method are creating Rotation2d anyway.)**

# Implement Spark Max configuration best practice:

* **Call restoreFactoryDefaults() before configuring to clear out any existing configuration. This is important so no old values stick around in the settings we are not explicitally configuring.**
* **Call burnFlash() after configuration so the settings persist across power cycle. This is important in case your motor controller has a power glitch during a match, since configuration only happens when the robot program starts.**

# Command

* **It is not good practice to read button values in a command. Use button bindings.**

# Phoenix

* Phonix5 will give the wheel/magnet alignment in driver station. The issue is not easily reproduced, but the most likely way to get it to happen is to restart the robot code (boot the robot, "restart code" from driver station, or deploy the code) and enable the robot as quickly as you can. When the problem occurs, one or more wheels will not point the right direction. Upgrade to to Phoenix 6

# This is our intended drive scheme for the existing Swerve repo:

* **Robot movement to the left is +Y on the field, but -X on the left controller stick.**
* **Robot movement forward is +X on the field, but -Y on the left controller stick.**
* **Robot rotation is +left on the field, but -X on the right controller stick.**
**Based on this scheme, the DriveCommand needed adjustment:**
* **All of the axes need to be inverted.**
* **The correct controller sticks need to be controlling the correct translation components.**
* **Also, never use System.out.println() within the robot loop. It will flood the console to the point of lagging your robot. Use the SmartDashboard/NetworkTables to send the value to the driver station.**

# The following fixes added in DrivetrainSubsystem of exsiting Swerve repo:
* **The NAVX gyro angle needs to be inverted. NavX's getAngle() returns the heading with clockwise positive, which is backwards from WPILib.**
* **For zero the heading, you need to reset odometry. I assume the intent is that the robot's current heading becomes zero, but the robot's estimated translation stays the same.**
