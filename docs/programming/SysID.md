
# SysID 



https://docs.wpilib.org/en/stable/docs/software/pathplanning/system-identification/introduction.html


### Objective
The objective of this was to create a predictive model for the voltage-speed relation in Mostly Dead
To do this, we used a WPI Lib application, inputting various mechanical details about the robot (ports, encoder specifics, etc.)
WPILib then ran diagnostics on the robot, and measured the distance traveled, and other various factors about the system we were 		tracking (energy loss, including via friction)

### Learning:
We learned how to calculate voltage, and how it functions on Mostly Dead. We also learned the methodology, so that we could apply it to other robots (only differential drive ones)
We also learned everything else in this document
The constants.java file was not accurate to the physical ports of the robot

### Troubleshooting:
If SysID isn't functioning, restart it.
Ensure driver station is running

### Data (constants acquired):
Static friction constant: .098141
Velocity: .056505
Acceleration: .0090187


