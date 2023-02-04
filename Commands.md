---
Title: Commands
category: pages
layout: default
---

# Commands

Commands are where the methods created in the subsystems are actually run. They're named with a short summary of what they do.

### To create a new command:
1. Right-click on the `commands` folder.
2. Go to the bottom of the context menu that appears and select "Create a new class/command".
3. In the input box that appears at the top, type/click `Command (New)`.
4. Give it a relevant name.

### To add subsystem methods to a command:
1. You're going to need to `import` your subsystem methods before you can call them. In the command file, beneath the other `import`s, type `import frc.robot.subsystems.NAME;`, where `NAME` is the file name of your subsystem.
2. Now just call the methods from your subsystems inside the proper area of the command file.
* To call a method, type `NAME(PARAMETERS);`, where `NAME` is the method name and `PARAMETERS` are the inputs you defined the method to need.
* The `initialize()` area will only run once -- when the command is called.
* The `execute()` area will run repeatedly after the command has been called.
* The `end()` area will run when the command is stopped.
* The `isFinished()` area constantly evaluates the conditional after `return`, and when it's true, `end()` is run.

### To call commands:
You're not quite done yet! Commands don't just start doing things magically! The final step is to actually run the command.
1. Locate the place where you want to run your command.
* If you're running the command in `RobotContainer.java`, you don't need to `import` the command, as it's already hooked up to do that. If you're running it somewhere else, beneath the other `import`s, type `import frc.robot.commands.NAME;`, where `NAME` is the name of the command.
* A common scenario is hooking up your command to a joystick button. To do this, open `RobotContainer.java` (no need to `import`) and scroll down to the "Joysticks and Buttons" section. At the bottom of the "Joystick buttons" area, type `private final JoystickButton ButtonBUTTON = new JoystickButton(CONTROLLER, BUTTON);`, where `CONTROLLER` is the name of the controller and `BUTTON` is the ID of the button you want to link to (Google the controller if you're not sure what this is). Now scroll down to the `configureButtonBindings()` area and type `ButtonBUTTON`. If you want the command to run only once, type `.whenPressed();` -- otherwise, type `.whileHeld();`. Type Step 2 inside the parentheses.
2. Type `new NAME()`, where `NAME` is the command's file name.

### About instant commands
If you only need to do a simple task (such as running a single method when a button is pressed) you don't have to go through the process of setting up an actual command. You can instead directly call those methods from the subsystem. Instead of typing `new NAME()`, type `() -> VARNAME.FUNCNAME()`, where `VARNAME` is the name of the subsystem's **variable** and `FUNCNAME` is the name of the method in the subsystem you want to run. If you want to pass parameters, you have to put them inside the first set of parentheses.

***

If you've made it this far, you've learned almost all the basics of FRC programming! The final step before putting it into practice is learning more about [constants](https://github.com/Team2530/Documentation/wiki/Constants).