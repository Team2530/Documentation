Phoenix Tuner is a pretty simple piece of software. It's mostly automatic.

You'll need to [install the CTRE Phoenix Framework](https://github.com/Team2530/Documentation/wiki/Setting-up-CTRE-Phoenix-Framework) to get Phoenix Tuner.

## Initial Setup (Robot)

1. Connect the laptop to the RoboRIO via a USB-A to USB-B cable. USB-A end goes in the laptop, USB-B in the RoboRIO.
2. Launch Phoenix Tuner
3. Read through the text at the top of the tab labeled "Robot Controller Install."
4. Follow its instructions, and wait until it's done.
5. The diagnostic server is now installed, and Phoenix tuner can now be used.
6. To start viewing CAN devices, it needs to know where to look; Put either the team number or the IP of the RoboRIO (usually 10.25.30.2) into the Diagnostic Server Address box on the Robot Controller Install tab. It will autoconnect and start displaying CAN devices, of which the list will continually update. No need to manually refresh.

## General Use

- The most common application of the software is for clearing sticky faults.
  - Go to the CAN Devices tab 
  - Click the CAN device you want to test
  - Switch to the Self-Test tab
  - Press Self-Test at the bottom to get the diagnostic readout
  - Interpret the cause, then press Blink at the bottom to clear it

- Another use of Phoenix Tuner is updating the firmware of the PDP, PCM, and motor controllers. 
  - [Download the latest version of the firmware.](https://store.ctr-electronics.com/talon-srx/#product_tabs_technical_resources)
  - On the Can Device page, the bottom has a section for upgrading the firmware.
  - All you have to do is select the CAN device you wish to upgrade
  - Select the firmware file using the [...] box
  - On the file explorer sidebar, there should be a section with the Phoenix Tuner icon and name
  - It contains some subfolders, which each contain different firmware files
  - Find and select the firmware files for the device you are trying to update
  - Press the Update Device button, or select "Update all _______ Devices" to do all of them, one after another, all at once.

## Problems we have encountered in the past

- Upon first connection of CAN wires, the motor controllers all got assigned the same ID of 0 on the CAN bus.
  - The solution was simple, click the slot for the duplicates, and change the ID over and over again until each controller has its own ID
  - Be cautious, however, as this changes which is which in the code, and could cause problems if, say, the back left motor was previously coded as ID 4, and now appears as ID 2 to the robot. 