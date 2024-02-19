---
Title: Setting up VSCode
category: pages
layout: default
---

# Setting up VSCode

Visual Studio Code (VS Code) is the software that replaced Eclipse as the primary IDE for FIRST in 2019. The WPILib version adds features to aid in development of FIRST robots. We use this software to write our robot code.

## Installation on Windows, macOS, and Linux (recommended)
It's important to use the version that matches up with the season to ensure that everyone can use the same features and to avoid unnecessary bugs across Java versions. (For example, during the 2022 season, FRC VS Code 2022 should be used.)

Follow [these instructions](https://docs.wpilib.org/en/latest/docs/zero-to-robot/step-2/wpilib-setup.html) to install the WPILib version of VS Code, which includes the latest version of Java.

Once you're done with that, we recommend that you install the Better Comments extension. This allows us to make "special" comments that are colored differently and are more attention-grabbing. To install this:

1. Open VS Code and click on the Extensions tab in the toolbar on the very left of the screen.
2. Search "Better Comments" and click on the one that says "Aaron Bond".
3. On the description page that pops up, click "Install".

## Updating
Several updates are made available throughout the build season, which contain important fixes. These updates are often required to be installed come competition time. Luckily, WPILib made it easy to update:

1. Press the WPILib button in the top-right corner of the screen.
2. Start typing "Check for WPILib Updates" and select the top option that appears.
3. Click "Online" in the prompt that appears. If there's an update, just wait for it to do its thing.

***

## Using the web version for Chromebooks or other devices (not recommended)
If you don't have access to a computer at home that runs Windows, macOS, or Linux, you can use the web version of VS Code integrated with GitHub. We generally don't recommend this since you won't have any autocomplete functionality, error reporting, or library support, and you won't be able to build and deploy to the robot. However, it's an effective way to get some programming done if you only have access to a Chromebook.

1. Open the repository you want to edit on github.com.
2. Press the `.` (period) key on your keyboard.
3. Once the web editor has loaded, create a bookmark so you can quickly access it later.

This editor auto-saves your changes to your browser, so you don't need to worry about needing to commit or losing your changes when you close the tab or shut the lid on your Chromebook.