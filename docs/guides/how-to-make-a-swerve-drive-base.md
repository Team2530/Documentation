# How to make a Swerve Drive base

## Creation
                                                Change to be your last folder \/, ext other \/
Hopefully you made your file from a folder and have this <package frc.robot.subsystems.(other folder[Not needed]);>
To make a Swerve Drive Base you need a few imports:
Findumentals:
```java title="Imports" 
import edu.wpi.first.math.kinematics.SwerveDriveKinematics;
import edu.wpi.first.math.geometry.Translation2d;
import edu.wpi.first.math.util.Units;
import edu.wpi.first.math.kinematics.SwerveModuleState;
```
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
If you use a different method, it should still work. Since it will be in our case, we use <public class SwerveDrive extends SubsystemBase> with a <{> at the end where the code of the "defining" end of it goes.
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
And close the constructor with a <}>
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
    <// Create test ChassisSpeeds going X = 14in, Y=4in, and spins at 30deg per second.
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

Credits to [Yagsl.com]<https://docs.yagsl.com/fundamentals/swerve-drive> for information to make this.