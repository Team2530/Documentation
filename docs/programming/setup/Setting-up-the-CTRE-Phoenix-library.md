---
Title: Setting up the CTRE Phoenix library
category: pages
layout: default
---

# Setting up the CTRE Phoenix library

The CTRE Phoenix library is required to program our CTRE motors. In this article, we'll focus on the library, but the installer also comes with Phoenix Tuner, which is explained [here](https://team2530.github.io/Documentation/electronics/Phoenix-Tuner-Use/).

## Computer installation
CTRE Phoenix Framework only supports Windows, macOS, and Linux. If you're using a Chromebook or another device, you can still edit code, but you won't be able to build and deploy to the robot.
Make sure that you have administrator privileges on your computer before starting.

1. Download the latest release of the **CTRE Phoenix Framework** from [this page](https://github.com/CrossTheRoadElec/Phoenix-Releases/releases).
2. Run the installer that you downloaded. Make sure that the C++/Java option is selected -- you don't need to worry about the other options.
3. Close the installer when it's finished installing.

## VSCode installation
To make sure that everything is up and running, check if the vendor library is installed:

1. Open any file in VSCode.
2. Click on the WPILib icon in the upper-right corner.
3. Type "Manage Vendor Libraries" and select the option that appears.
4. Select "Manage current libraries".
5. Check to see that "CTRE-Phoenix" is in the list. If it is, you can click outside of the prompt to close it.

If, for whatever reason, you don't see "CTRE-Phoenix" in the list, first make sure that the robot has been [set up for the season](./Setting-up-for-a-new-season).

***

Learn how to program motors with the library in the [Programming motors](https://team2530.github.io/Documentation/programming/basics/Programming-motors/) article.