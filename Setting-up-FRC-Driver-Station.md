---
Title: Setting up FRC Driver Station
category: pages
layout: page
---
FRC Driver Station is software that enables a computer to be utilized as (surprise surprise) a driver station for FRC robots. This software is required to be installed on at least one computer we bring to competitions in order to control our robot.

## Installation
Only computers with Windows are supported. (Unacceptable. Smh National Instruments)

Follow the instructions on [this page](https://docs.wpilib.org/en/stable/docs/zero-to-robot/step-2/frc-game-tools.html#installing-the-frc-game-tools) to install the FRC Game Tools, which includes Driver Station. When you get to the point where it asks you to create an account, just go ahead and create your own. You can trust the company with your personal information.

## Configuration
Go to the Settings tab on the left side of the screen and enter `2530` in the Team Number field. **The robot will not be able to communicate with Driver Station if this is not set.** Also, set the Dashboard Type to `Shuffleboard`.

![](https://user-images.githubusercontent.com/56053273/149267432-5cd354e5-b09d-459b-945e-4ac6dcb6c57b.png)

Once Shuffleboard opens, go to `File > Load layout` and select the `shuffleboard.json` file saved in this year's robot code.

Now connect the drive joystick to your computer and go to the USB tab. **Make sure that the port number shown for the joystick is the same as the port number defined in the robot code.** In this example, if the declaration of the controller is `Joystick stick1 = new Joystick(0);` then you're good to go!

![image](https://user-images.githubusercontent.com/56053273/149868025-7da2a3af-2bee-4ce8-aaf4-47d14b172360.png)