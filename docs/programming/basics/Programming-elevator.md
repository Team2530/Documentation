---
Title: Programming Elevators (Kraken)
category: pages
layout: default
---

# Step 1: Create your subsystem
Create a new subsystem, named whatever you want. For our example, we'll call it `ElevatorSubsystem`:

```java
package frc.robot.subsystems;

public class ElevatorSubsystem extends profiledPIDSubsystem{ // as we'd like to use PID probably

}
```

# Step 2: Create your motor object(s)
Before we begin, we need to define port Constants. To do so, we make a subclass in our Constants class, named Elevator.

In Constants.java:
```java
public static class Elevator {
    public static final int elevatorOnePort = 10;
    public static final int elevatorTwoPort = 11;
}
```

In ElevatorSubsystem.java:
```java
import com.revrobotics.CANSparkLowLevel.MotorType;
...
...
private final CANSparkFlex elevatorMotorOne = new CANSparkFlex(Constants.Elevator.elevatorOnePort,
            MotorType.kBrushless);

private final CANSparkFlex elevatorMotorTwo = new CANSparkFlex(Constants.Elevator.elevatorTwoPort,
            MotorType.kBrushless);
```

# PID Prep
Since we're using PID, let's create some more constants

In Constants.java:
```java
public static class Elevator{
...
...
    public static class PID {
      public static double kP = 90.0;
      public static double kI = 0.0;
      public static double kD = 4.0;
      public static double MAX_VELOCITY = 1.25;
      public static double MAX_ACCELERATION = 5.0;
    }
}
```

Further, let's add a constructor with some PID!
```java
public ElevatorSubsystem() {
    super(
        new ProfiledPIDController(
            Constants.Elevator.PID.kP,
            Constants.Elevator.PID.kI,
            Constants.Elevator.PID.kD,
            new TrapezoidProfile.Constraints(
                Constants.Elevator.PID.MAX_VELOCITY,
                Constants.Elevator.PID.MAX_ACCELERATION)),
            0.0);
}
```


# Elevator motor/encoder prep

Back to the top of our `ElevatorSubsystem.java` file, we'll make sure we have a working encoder
```java
private final RelativeEncoder elevatorEncoder = elevatorMotorOne.getEncoder();
```

Next, somewhere in our constructor, let's set our position and velocity conversion factors. While we're here, we're going to idle our motors
```java
public ElevatorSubystem(){
    elevatorEncoder.setPositionConversionFactor(1.0 / Constants.Elevator.motorTurnsPerMeter);

    elevatorEncoder.setVelocityConversionFactor(1.0 / Constants.Elevator.motorTurnsPerMeter);

    elevatorMotorOne.setIdleMode(CANSparkFlex.IdleMode.kBrake);
    elevatorMotorTwo.setIdleMode(CANSparkFlex.IdleMode.kBrake);
}
```

