---
Title: Robot Code Debugging
category: pages
layout: default
---
## Robot Code Debugging

* Are the all 8 motor and all 4 CANCoder ID's correct? If not, fix IDs in the code.
* Do all 8 motors turn in the right direction when positive power is applied? If not, fix motor inversion in the code.
* Are all 4 CANCoders in phase with the motors, meaning when the CANCoder value goes up, the motor's encoder value goes up. If not, fix the sensorDirection in the code.
* Does the robot move in the correct direction using an XBox controller? If not, correct the controller axis/inversions to get it right.
* Does the steering go to it's target position based on XBox controller input? If not, you may need to tune the steer/azimuth motor PID.
  
# Now that you know driving behavior is correct, start at the beginning for vision:

* Is the correct type of Limelight pipeline active (Apriltag 3d targetting)
* Does the limelight see targets properly? If not, tune the gains and thresholds
* Is the limelight returning good data for the target, is it properly calculating the distance and rotation of the target? If not, make sure your target is the correct size, etc.
* Look in Shuffleboard or OutlineViewer and understand what the target values are telling you, then verify in the code that you're using those values.
* If the targetting data looks good, break down the robot motion into it's three parts and test them individually:
* **X (forward backward motion) - hard code the Y and Z speeds to zero in AprilTagFollowCommand. Move the target closer and farther away from the camera. The "drive" motors should run faster when the target is far away, and slower at the target gets closer. When the target is at your distance setpoint (36-inches) the robot should stop. When the target is closer than the setpoint, the drive motors should run backwards. Fix any coding errors and tune your X PID.**
* **Y (side to side) - hard code X and Z speeds to zero in AprilTagFollowCommand. Move the target left and right of the camera. The robot should strafe to keep the target centered on the camera. Fix any coding errors and tune your Y PID.**
* **Z (rotation) - hard code X and Y speeds to zero in AprilTagFollowCommand. Hold the target in front of the camera, then rotate it. The robot should rotate to make it's angle match the targets. This one is a little harder to do alone because it will tend to turn the target out of camera view, but you can do it. Fix and coding errors and tune your Z PID.**
