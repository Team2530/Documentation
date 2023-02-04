---
Title: Getting Started with the Robot
category: pages
order: 1
---

In this article, you will learn how to make edits to the robot's code and get the updated code onto the robot.

You should have already followed the **Installing programs** articles at this point. If not, [go back to Home](https://github.com/Team2530/Documentation/wiki) and do those first.

## Editing code

Before editing, it's always a good idea to **pull** the latest version of the code from GitHub. Clicking the Pull button in your version control software will download the latest version of the code to your computer. (If you already have it open in VSCode, any changes are reflected immediately.)

In VSCode, open the folder you saved the repo to -- hopefully you remember where that is! In the folder view, navigate to src > main > java > frc > robot. You'll see something like this:

📁 commands  
📁 libraries  
📁 subsystems  
📄 Constants.java  
📄 Main.java  
📄 Robot.java  
📄 RobotContainer.java

You don't need to be familiar with all of this yet, but in case you're curious, here's what each file and folder is for:
* `Main.java` just starts the program -- you'll probably never need to touch it.
* `Robot.java` controls what **automatically** happens. There are different "methods" that run at different times, such as when the robot starts, while the robot is running, and during different phases of the FRC game, such as before/during autonomous and teleop. However, besides what's already there, programmers should only add things like diagnostics and logging.
* `RobotContainer.java` controls everything that the robot actually does. This is where joysticks and buttons are hooked up to their corresponding code. The code run during autonomous and teleop is also hooked up here.
* `Constants.java` stores things that won't change **while the robot runs**, such as wheel sizes and motor ports. This makes them easy to change while the robot isn't running if needed.
* Most of the robot's functionality is programmed out within _subsystems_, which are stored in the `subsystems` folder.
* To actually carry out this functionality, _commands_ are used, which are stored in the `commands` folder.
* _Libraries_ are like addons for Java, and they're stored in the `libraries` folder. You've already installed the CTRE Phoenix library, but that's actually a _vendor library_, so it won't show up in this folder. You probably won't need to touch this unless you're adding a new library.

Don't get overwhelmed by all of this -- we're going to take it one step at a time in the following articles. To get started, let's hook up a command to a button in `RobotContainer.java`:
1. Open the `RobotContainer.java` file in VSCode.
2. Scroll down to the "Joysticks and Buttons" section -- we're going to add a new button.
3. At the bottom of the "Joystick buttons" area, type `private final JoystickButton Button999 = new JoystickButton(stick1, 999);`. This creates a new button object -- if there were a button with the ID "999" on the joystick, this object would be used to detect its presses.
4. Scroll down to the line that has `private void configureButtonBindings()` in it -- we're going to hook up an example command to the button.
5. Inside the curly brackets, there are a bunch of lines that start with "Button". Create a new line below these and type `Button999.whenPressed(new ExampleCommand(ExampleSubsystem));`. Since this is just practice, this code won't do anything, but it's the same structure used when actually adding a real button. You'll learn more about this in the following articles.

## Sending code
It's great to have some cool code, but it doesn't do any good just sitting on your computer. We want everyone to be able to access it, but more importantly, we want it running on the robot!

### Pushing to GitHub
To push your code to the GitHub repository using GitKraken:
- Save (Ctrl + S) whatever you're working on in VSCode.
- Whenever you work on something experimental, incomplete, or untested (or just want to save your progress so you can edit at home), you'll make a new branch by clicking the Branch button. Since what we're doing is just practice, do this now. (To switch back to another branch, double-click the branch you want to switch to.)
- Click the "View changes" button in the right panel of GitKraken, then click "Stage all changes."
- Add a (helpful) summary of the changes you made in the commit message, then click the "Commit changes" button.
- At this point, your "commit" is only saved on your computer. Make sure you click the Push button to upload your changes so that everyone can see them! (You'll see a little 2530 icon in the branch label if the commit is uploaded.)
- This shouldn't happen with this tutorial since you're not merging any branches, but if your software ever alerts you of a merge conflict, STOP! Do not proceed or try to resolve the issue. Ask a lead for help.

If you're using a different program, the process is generally the same.

### Deploying to the robot
To deploy your code to the actual robot: (the robot has to be physically in the same building as you for this to work)
1. In VSCode, select the input box at the top with the little WPILib logo in it.
2. Type "Build Code" and select the option that appears. This makes a robot-ready version of the code for you.
3. Ensure that the robot is on (if it's not, with permission, turn the robot on) and connect your computer to the RoboRIO's Wi-Fi network. It will say "No internet" -- that's supposed to happen, since you're connected directly to the robot, not the Internet.
4. In the same input box, type "Deploy Code" and select the option that appears. This actually SENDS the code that you built in Step 2. Nothing will change if you forget this step!

***

If you've finished this article, great work! The next step is to learn more about [subsystems](https://github.com/Team2530/Documentation/wiki/Subsystems).