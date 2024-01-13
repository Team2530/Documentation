---
Title: Updating the RoboRIO
category: pages
layout: default
---
# Updating the RoboRIO

Here's the general overview:
1. Follow the instructions on [this page](https://docs.wpilib.org/en/stable/docs/zero-to-robot/step-2/frc-game-tools.html#installing-the-frc-game-tools) to install the FRC Game Tools, which includes the RoboRIO Imaging software. (If your computer already has FRC Driver Station, it has this software too.)
2. Find your local friendly RoboRIO connector cable. 
3. Connect the USB end to your computer.
4. Connect the other end to the appropriate port on the RoboRIO.
5. Right-click on the software and select "Run as Administrator" (not always needed, but could solve problems.)
6. After launching, the roboRIO Imaging Tool will scan for available roboRIOs and indicate any found in the top left box. The bottom left box will show information and settings for the roboRIO currently selected. The right hand pane contains controls for modifying the roboRIO settings:
   - Edit Startup Settings - This option is used when you want to configure the startup settings of the roboRIO (the settings in the right pane), without imaging the roboRIO.
   - Format Target - This option is used when you want to load a new image on the roboRIO (or reflash the existing image). This is the most common option.
   - Update Firmware - This option is used to update the roboRIO firmware.
7. Have patience. (This could be the hardest step)

You can also follow the instructions provided on [the WPILib documentation.](https://docs.wpilib.org/en/stable/docs/zero-to-robot/step-3/imaging-your-roborio.html)