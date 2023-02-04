Programming motors is the most fundamental programming task in FIRST, as motors control all robot movement. Motors are typically hooked up to _motor controllers_, which allow programmatic control of motor speed and direction.

You should have already followed the **Installing programs** articles at this point. If not, [go back to Home](https://github.com/Team2530/Documentation/wiki) and do those first. If you skipped installing the CTRE Phoenix library, make sure you go back and do that now.

First, determine what subsystem you're working in. If you're adding a new component to the robot, create a new subsystem.

We have a couple different flavors of motor controllers. Make sure you know which one you're programming for before you get started.

## Programming the Talon SRX
[Full documentation here](https://store.ctr-electronics.com/content/api/java/html/classcom_1_1ctre_1_1phoenix_1_1motorcontrol_1_1can_1_1_w_p_i___talon_s_r_x.html)

Start by doing `import com.ctre.phoenix.motorcontrol.can.WPI_TalonSRX;`, then define the motor controller by typing `private static WPI_TalonSRX MOTORNAME = new WPI_TalonSRX(PORT);` at the top of the subsystem's class, where `MOTORNAME` is what you want to name the motor and `PORT` is the port that the motor is connected to. (For `PORT`, it's best to store this value as a constant.)

Set the speed of the motor by using `MOTORNAME.set(SPEED)`, where `NAME` is the name of the motor and `SPEED` is a double-type value between -1 and 1.

## Programming the Talon FX
[Full documentation here](https://store.ctr-electronics.com/content/api/java/html/classcom_1_1ctre_1_1phoenix_1_1motorcontrol_1_1can_1_1_w_p_i___talon_f_x.html)

Start by doing `import com.ctre.phoenix.motorcontrol.can.WPI_TalonFX;`, then define the motor controller by typing `private static WPI_TalonFX MOTORNAME = new WPI_TalonFX(PORT);` at the top of the subsystem's class, where `MOTORNAME` is what you want to name the motor and `PORT` is the port that the motor is connected to. (For `PORT`, it's best to store this value as a constant.)

Set the speed of the motor by using `MOTORNAME.set(SPEED)`, where `NAME` is the name of the motor and `SPEED` is a double-type value between -1 and 1.

If you need to rotate the motor a specific amount, use `setSelectedSensorPosition(getSelectedSensorPosition() + (ANGLE / 360 * Constants.ENCODER_TICKS_PER_REVOLUTION), 0, TIMEOUT);` where `ANGLE` is the amount of degrees to turn the motor and `TIMEOUT` is the number of milliseconds for stall detection. You can use this with a try-catch to detect if it takes longer than this, as it will throw an error.

## Programming the Victor SPX
[Full documentation here](https://store.ctr-electronics.com/content/api/java/html/classcom_1_1ctre_1_1phoenix_1_1motorcontrol_1_1can_1_1_w_p_i___victor_s_p_x.html)

Start by doing `import com.ctre.phoenix.motorcontrol.can.WPI_VictorSPX;`, then define the motor controller by typing `private static WPI_VictorSPX MOTORNAME = new WPI_VictorSPX(PORT);` at the top of the subsystem's class, where `MOTORNAME` is what you want to name the motor and `PORT` is the port that the motor is connected to. (For `PORT`, it's best to store this value as a constant.)

Set the speed of the motor by using `MOTORNAME.set(SPEED)`, where `NAME` is the name of the motor and `SPEED` is a double-type value between -1 and 1.