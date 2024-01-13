# Setting up for a new season

WPILib releases a new major version of their software every season, and it's important to update our software and migrate to the corresponding year's project after kickoff to avoid various issues.

## Update WPILib
**This needs to be done on ALL computers (except Chromebooks) to avoid compatibility issues.**

Follow the instructions on [this page](https://docs.wpilib.org/en/stable/docs/zero-to-robot/step-2/wpilib-setup.html) to install the latest version of WPILib. Make sure to select the "Everything" mode, "Install for this User," and "Download for this computer only" (or whatever equivalent/similar options appear in future installers.)

***

**The following steps only need to be completed once per season. If the RobotCode20XX repository (with the current year) already exists and has robot code in it, chances are that someone has already done this and you don't need to. All you have to do at this point is clone the new repository to your computer.**

## Update the RoboRIO
[View the instructions here.](./Updating-the-RoboRIO)

## Configure a new project

## Step 1: Create and clone a new repo
Create a new GitHub repository titled `RobotCode20XX` in our Team 2530 organization. (If you don't have permission, someone else who does will need to do it for you. Or, if you were entrusted with setting everything up, you could probably get someone to give you admin privileges.) Clone this repository onto your computer, preferably somewhere you won't forget.

## Step 2: Create or import a project
**This only needs to be done on ONE computer and then published to GitHub.**

At this point, you need to decide if you want to reuse the previous year's robot code (which is what we usually do) or start an entirely new project. Remember that even if you start an entirely new project, you can still copy as much code as you want from other projects, but it will be more tedious than just importing an old project.
### Reusing the previous year's code
1. If you haven't already, clone the _previous year's code_ onto your computer.
2. Open that folder in VSCode.
3. You should get a prompt to import the old project into the new version of WPILib. (If not, there's an "Import a WPILib 20XX Gradle project" command in the Command Palette.) Select `OK`.
4. Change "Project Name" to `RobotCode20XX`, change "Base Folder" to the folder you cloned your repo into, and uncheck "Create a new folder?" (yes, it's highly recommended, but we know what we're doing.)
5. Hit that Import Project button! (You'll see a lot of red, and the code won't build -- you'll still need to complete step 3)
### Starting an entirely new project
1. Open any file in VSCode.
2. Click on the WPILib icon in the upper-right corner.
3. Type "Create a new project" and select the option that appears.
4. Select the `Template` project type, enter `RobotCode20XX` for the project name, and enter `2530` for the team number.
5. Click the "Generate Project" button!

## Step 3: Add the libraries to the project
**This only needs to be done on ONE computer and then published to GitHub.** Note that this is a separate process from installing the libraries *to your computer* -- this needs to be done every time we create a new WPILib project.

1. Open any file in VS Code.
2. Click on the WPILib icon in the upper-right corner.
3. Type "Manage Vendor Libraries" and select the option that appears.
4. Select "Install new libraries (offline)".
5. Select "CTRE-Phoenix" and "KauaiLabs_navX_FRC", then click OK. (If you don't see one or both of these, make sure that the [CTRE Phoenix](./Setting-up-the-CTRE-Phoenix-library) and [navX](./Setting-up-the-navX-library) libraries are installed on your computer.)
6. Once the installation is finished, you'll be prompted to build the robot code -- go ahead and confirm. If you imported a project, the errors might linger for a minute, but as long as the robot code builds successfully, you're good to go.

## Step 4: Push the changes to GitHub
If you followed the steps in order, you should be able to simply push your changes to your `RobotCode20XX` repository.

After these steps have been completed, for the rest of the season, all you have to do to set up another computer is:
- install the latest version of WPILib
- clone the new repository
