# How to make a Swerve Drive base

## Programming

This section of the guide will explain how to setup code for a swerve drivebase using YAGSL. YAGSL (**Y**et **A**nother **G**eneric **S**werve **L**ibrary) is a Java library for FRC developed by [3481 BroncBotz](https://www.thebluealliance.com/team/3481). 


Start by watching this introduction video: 

<iframe width="420" height="315"
src="https://www.youtube.com/embed/4Tcyn_oj_G0">
</iframe>

Then, read the documentation from YAGSL: <https://docs.yagsl.com/bringing-up-swerve/preface>. Do what it says, install the required dependencies, figure out the CAN IDs, and write the code.

Now you should know everything you need to know in order to program the swerve drive. 

Here is the swerve code from our 2026 robot, as a reference: <https://github.com/Team2530/RobotCode2026/blob/main/src/main/java/frc/robot/subsystems/SwerveSubsystem.java>.

### Review of 2026 Robot Code

#### Java Boilerplate

The robot swerve subsystem code starts with the package definition as usual, like any Java source file. It is in the package `frc.robot.subsystems`. 

```java title="SwerveSubsystem.java" linenums="1"
package frc.robot.subsystems;
```

After the package definition are the imports. From this you can see that we are using WPILib, Choreo, and YAGSL.

```java title="SwerveSubsystem.java" linenums="3"
import static edu.wpi.first.units.Units.*;

import com.pathplanner.lib.config.PIDConstants;
import com.pathplanner.lib.controllers.PPHolonomicDriveController;
import com.pathplanner.lib.trajectory.PathPlannerTrajectoryState;
import com.pathplanner.lib.util.DriveFeedforwards;

import choreo.trajectory.SwerveSample;
import edu.wpi.first.math.Matrix;
import edu.wpi.first.math.geometry.Pose2d;
import edu.wpi.first.math.geometry.Pose3d;
import edu.wpi.first.math.geometry.Rotation2d;
import edu.wpi.first.math.geometry.Translation2d;
import edu.wpi.first.math.kinematics.ChassisSpeeds;
import edu.wpi.first.math.numbers.N1;
import edu.wpi.first.math.numbers.N3;
import edu.wpi.first.math.system.plant.DCMotor;
import edu.wpi.first.networktables.NetworkTableInstance;
import edu.wpi.first.networktables.StructPublisher;
import edu.wpi.first.units.measure.LinearVelocity;
import edu.wpi.first.units.measure.AngularVelocity;
import edu.wpi.first.wpilibj.RobotBase;
import edu.wpi.first.wpilibj.Timer;
import edu.wpi.first.wpilibj.smartdashboard.Field2d;
import edu.wpi.first.wpilibj.smartdashboard.SendableChooser;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
import edu.wpi.first.wpilibj2.command.Command;
import edu.wpi.first.wpilibj2.command.SubsystemBase;
import edu.wpi.first.wpilibj2.command.sysid.SysIdRoutine;
import frc.robot.Constants.DriveConstants;
import frc.robot.Constants.RobotConstants;
import frc.robot.Constants.ChoreoConstants;
import frc.robot.Robot;
import frc.robot.RobotContainer;
import frc.robot.util.LimelightContainer;
import swervelib.SwerveDrive;
import swervelib.SwerveDriveTest;
import swervelib.encoders.CANCoderSwerve;
import swervelib.imu.Pigeon2Swerve;
import swervelib.math.SwerveMath;
import swervelib.motors.TalonFXSwerve;
import swervelib.parser.PIDFConfig;
import swervelib.parser.SwerveControllerConfiguration;
import swervelib.parser.SwerveDriveConfiguration;
import swervelib.parser.SwerveModuleConfiguration;
import swervelib.parser.SwerveModulePhysicalCharacteristics;
import swervelib.parser.json.modules.AngleConversionFactorsJson;
import swervelib.parser.json.modules.ConversionFactorsJson;
import swervelib.parser.json.modules.DriveConversionFactorsJson;
import swervelib.telemetry.SwerveDriveTelemetry;
import swervelib.telemetry.SwerveDriveTelemetry.TelemetryVerbosity;
```

Then we declare the class.

```java title="SwerveSubsystem.java" linenums="56"
public class SwerveSubsystem extends SubsystemBase {
```

#### Autonomous

After all the boilerplate we have a subclass for autonomous. Most of this is out of the scope of this guide, but you should know that this code is extending a class from [PathPlanner](https://pathplanner.dev/home.html), and has a field that is connected to Networktables for auto selection.

```java title="SwerveSubsystem.java" linenums="58"
   public static class AutonomousController 
            extends PPHolonomicDriveController
    {
        private static StructPublisher<Pose2d> autoPosePublisher = NetworkTableInstance
            .getDefault()
            .getStructTopic("Auto target pose", Pose2d.struct).publish();

        public AutonomousController() {
            super(
                new PIDConstants(
                    ChoreoConstants.PID.Translation.P,
                    ChoreoConstants.PID.Translation.I,
                    ChoreoConstants.PID.Translation.D
                ),
                new PIDConstants(
                    ChoreoConstants.PID.Heading.P,
                    ChoreoConstants.PID.Heading.I,
                    ChoreoConstants.PID.Heading.D
                )
            );
        }

        @Override
        public ChassisSpeeds calculateRobotRelativeSpeeds(
            Pose2d pose,
            PathPlannerTrajectoryState target
        ) {
            ChassisSpeeds speeds = super.calculateRobotRelativeSpeeds(pose,target);

            SmartDashboard.putNumber(
                "Auto/x",
                target.pose.getX()
            );
            SmartDashboard.putNumber(
                "Auto/y",
                target.pose.getY()
            );
            SmartDashboard.putNumber(
                "Auto/vx",
                target.fieldSpeeds.vxMetersPerSecond
            );
            SmartDashboard.putNumber(
                "Auto/vy",
                target.fieldSpeeds.vyMetersPerSecond
            );
            SmartDashboard.putNumber(
                "Auto/heading",
                target.heading.getRotations()
            );
            SmartDashboard.putNumber(
                "Auto/omega",
                target.fieldSpeeds.omegaRadiansPerSecond
            );
            autoPosePublisher.set(
                target.pose
            );

            return speeds;
        }
    }
```

#### YAGSL instance

On line 119 a field of type [`SwerveDrive`](https://yet-another-software-suite.github.io/YAGSL/javadocs/swervelib/SwerveDrive.html) is defined. This is important to note, because [`SwerveDrive`](https://yet-another-software-suite.github.io/YAGSL/javadocs/swervelib/SwerveDrive.html) is the YAGSL class that abstracts away hardware-dependent configuration from the software that controls it. The design goal there is that the code could work on a robot with a different type of Swerve Drive, different motors, etc. Everything specific to our swerve drive is stored in a config, and then that config gets passed to the [`SwerveDrive`](https://yet-another-software-suite.github.io/YAGSL/javadocs/swervelib/SwerveDrive.html) object.

```java title="SwerveSubsystem.java" linenums="119"
private final SwerveDrive swerveDrive;
```

This field is initialized in the class's constructor on line 325. 

```java title="SwerveSubsystem.java" linenums="325"
swerveDrive = new SwerveDrive(
                    driveConfiguration,
                    controllerConfiguration,
                    DriveConstants.MAX_ROBOT_VELOCITY.in(MetersPerSecond),
                    new Pose2d()
            );
```

As you can see, it uses `driveConfiguration` and `controllerConfiguration`. 

#### Gearing

The code for the gearing is next. It uses a [`SendableChooser`](https://github.wpilib.org/allwpilib/docs/release/java/edu/wpi/first/wpilibj/smartdashboard/SendableChooser.html) to add a dropdown in smartdashboard that lets the driver pick between any of these gearings in the enum.

```java title="SwerveSubsystem.java" linenums="125"
private final SendableChooser<SwerveGearing> gearChooser;

    enum SwerveGearing {
        LIGHT(7.03f),
        RIDICULUS(6.03f),
        LUDICRUS(5.27f);

        public final float gearRatio;

        private SwerveGearing(float gearRatio) {
            this.gearRatio = gearRatio;
        }
    }
```

The gearing code picks back up at line 350, where the sendablechooser is setup, the options are added, and the `changeGearing` method is registered.

```java title="SwerveSubsystem.java" linenums="350"
        // register gearshifter with smartdashboard
        gearChooser = new SendableChooser<>();

        gearChooser.addOption(
            SwerveGearing.LIGHT.toString(),
            SwerveGearing.LIGHT
        );
        gearChooser.setDefaultOption(
            SwerveGearing.RIDICULUS.toString(),
            SwerveGearing.RIDICULUS
        );
        gearChooser.addOption(
            SwerveGearing.LUDICRUS.toString(),
            SwerveGearing.LUDICRUS
        );

        gearChooser.onChange(gearing -> changeGearing(gearing));

        SmartDashboard.putData("swerve/Drive Gearing", gearChooser);
```

The changeGearing method looks like this:

```java title="SwerveSubsystem.java" linenums="546"
public void changeGearing(SwerveGearing gearing) {
        swerveDrive.setDriveMotorConversionFactor(
            SwerveMath.calculateMetersPerRotation(
                DriveConstants.Modules.WHEEL_DIAMETER.in(Meters)
                ,
                gearing.gearRatio
            )
        );
    }
```

TODO: conversion factor setup, PID, Swerve Module Character, Swerve module configuration array, 

---

Posing and geometry:
```java title="Imports" 

import edu.wpi.first.math.kinematics.SwerveModulePosition;
import edu.wpi.first.math.kinematics.SwerveDriveOdometry;
import edu.wpi.first.math.geometry.Pose2d;
import edu.wpi.first.wpilibj2.command.SubsystemBase
```

These imports are aboslutly nessasary for the code to work. Without them, you:
    
    1. Can't track the robot's posistion.

    2. Autos wont work.

## Coding Main File and Contructor
If you use a different method, it should still work. Since it will be in our case, we use 
```java
public class SwerveDrive extends SubsystemBase
```
with a 
```java
{
```
End:
```java
public class SwerveDrive extends SubsystemBase
    {
```
at the end where the code of the "defining" end of it goes.
The next part is the Attributes:
    SwerveDriveKinematics kinematics; <- The Drive base
    SwerveDriveOdometry   odometry; <- This is how is knows where it is without "limelights", kinda.
    Gyroscope             gyro; <- Representing a gyroscope.
    SwerveModule[]        swerveModules; <- Representing swerve modules.

Then come the "Contructor" or the compiler of the file.
```java title="File begining"
    public SwerveDrive() 
    {
```

This will be where everthing is defined in the file and where it originates.
Firstly, define the drive base:
```java title="kinematics"
    kinematics = new SwerveDriveKinematics(
            new Translation2d(Units.inchesToMeters(12.5), Units.inchesToMeters(12.5)), // Front Left
            new Translation2d(Units.inchesToMeters(12.5), Units.inchesToMeters(-12.5)), // Front Right
            new Translation2d(Units.inchesToMeters(-12.5), Units.inchesToMeters(12.5)), // Back Left
            new Translation2d(Units.inchesToMeters(-12.5), Units.inchesToMeters(-12.5))  // Back Right
        );
```
Then you need the gyro:
```java title="Gyro"
    gyro = new Gyroscope();
```
Along with the Odometry
Defining the angle and rotation of each motor translating it into a 2D field
```java title="odometry"    
    odometry = new SwerveDriveOdometry(
            kinematics,
            gyro.getAngle(), // returns current gyro reading as a Rotation2d
            new SwerveModulePosition[]{new SwerveModulePosition(), new SwerveModulePosition(), new SwerveModulePosition(), new SwerveModulePosition},
            // Front-Left, Front-Right, Back-Left, Back-Right
            new Pose2d(0,0,new Rotation2d()) // x=0, y=0, heading=0
        );>
```
And close the constructor with a 
```java
}
```
It should look ike this after. 
Change the measurement of the wheels from the center of the robot to match yours or it may not work right:
```java title="Swerve Drive" 
    public SwerveDrive() 
        {
    
        swerveModules = new SwerveModule[4];
        
        kinematics = new SwerveDriveKinematics(
            new Translation2d(Units.inchesToMeters(12.5), Units.inchesToMeters(12.5)), // Front Left
            new Translation2d(Units.inchesToMeters(12.5), Units.inchesToMeters(-12.5)), // Front Right
            new Translation2d(Units.inchesToMeters(-12.5), Units.inchesToMeters(12.5)), // Back Left
            new Translation2d(Units.inchesToMeters(-12.5), Units.inchesToMeters(-12.5))  // Back Right
        );
        
        gyro = new Gyroscope();

        odometry = new SwerveDriveOdometry(
            kinematics,
            gyro.getAngle(),
            new SwerveModulePosition[]{new SwerveModulePosition(), new SwerveModulePosition(), new SwerveModulePosition(), new SwerveModulePosition},
            // Front-Left, Front-Right, Back-Left, Back-Right
            new Pose2d(0,0,new Rotation2d()) // x=0, y=0, heading=0
        );
            
    }
```
## Coding Executor/Function
To make he exectutor or the function of the drive base, you need 
```java title="Executer" 
    public void drive()
        {
```
Within this, make a simple function for the robot to use.
```java title="Executor" 
    // Create test ChassisSpeeds going X = 14in, Y=4in, and spins at 30deg per second.
        ChassisSpeeds testSpeeds = new ChassisSpeeds(Units.inchesToMeters(14), Units.inchesToMeters(4), Units.degreesToRadians(30));
        
        // Get the SwerveModuleStates for each module given the desired speeds.
        SwerveModuleState[] swerveModuleStates = kinematics.toSwerveModuleStates(testSpeeds);
        // Output order is Front-Left, Front-Right, Back-Left, Back-Right
        
        swerveModules[0].setState(swerveModuleStates[0]);
        swerveModules[1].setState(swerveModuleStates[1]);
        swerveModules[2].setState(swerveModuleStates[2]);
        swerveModules[3].setState(swerveModuleStates[3]);
    }
    
    // Fetch the current swerve module positions.
    public SwerveModulePosition[] getCurrentSwerveModulePositions()
    {
        return new SwerveModulePosition[]{
            new SwerveModulePosition(swerveModules[0].getDistance(), swerveModules[0].getAngle()), // Front-Left
            new SwerveModulePosition(swerveModules[1].getDistance(), swerveModules[1].getAngle()), // Front-Right
            new SwerveModulePosition(swerveModules[2].getDistance(), swerveModules[2].getAngle()), // Back-Left
            new SwerveModulePosition(swerveModules[3].getDistance(), swerveModules[3].getAngle())  // Back-Right
        };
    } <- ends function
```
## Coding Periodic Executor
Hopefully you know this but if you don't, it just runs this periodicly for updating what is in this Executor:
```java title="Periodic" 
    public void periodic()
    {
        // Update the odometry every run.
        odometry.update(gyro.getAngle(),  getCurrentSwerveModulePositions());
    }
```
After this, it is custom. There isn't much else to this but yeah.
End the file with a:
```java title="ADD THIS"
}
```
So that it will work, because sometime we forget.

Credits to [Yagsl.com](https://docs.yagsl.com/fundamentals/swerve-drive) for information to make this.
This was also a fun item to add :>
