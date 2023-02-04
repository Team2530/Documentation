---
Title: Setting up version control
category: pages
layout: default
---

# Setting up VCS

We use version control software to manage and store our robot code. GitHub is a cloud version control system where we store our code and documentation. Everyone on the team can download, edit, and upload code here. It's indescribably helpful to also have companion software on your computer, which downloads and uploads code automatically to make editing with VS Code more convenient.

## Setting up GitHub
Before you begin, create a [GitHub](https://github.com) account. Use whatever email or name, it really doesn't matter too much. Just keep it school-appropriate.

Find out who has admin access to the team's GitHub and ask to join. You can't do anything programming-related without being a part of the [Team2530 Organization.](https://www.github.com/Team2530) You need to be a part of it to edit code or make documentation.

While they get on that, you can set up your version control software of choice.

## Setting up a companion program on a Windows, macOS, or Linux computer (recommended)
There are multiple different GitHub companion programs available, and it shouldn't matter which one you use. However, beginners should use GitKraken, since the team is the best acquainted with it.

### GitKraken
GitKraken is a third-party software offered by Axosoft. Although there are many premium features, there are many useful integrations that are offered for free.
- If it's not already installed, download it at [their website](https://www.gitkraken.com/) and run the installer.
- If it is already installed, go to File > Sign into a Different Account.
- Click "Sign in with Github". (Make sure you're actually signed in to GitHub on your browser first.)
- A webpage will open requesting access to your GitHub account. Click "Authenticate".
- When the authentication is finished, the page will show a success message.

You're not done! You need to clone (download) the robot code to your computer in order to edit it on VS Code. (You'll need to be a part of the Team2530 Organization first.)
- Go to File > Clone Repo and select "Github.com".
- Under "Where to clone to", click the Browse button and select a location on your computer. (It doesn't matter where -- though it might be a good idea to put it somewhere you'll remember.)
- Under "Repository to clone", select "RobotCodeYYYY" (where "YYYY" is the current season.)
 - Hit "Clone the repo!"

### GitHub Desktop
GitHub Desktop is a first-party software from GitHub Inc. itself. It's essentially a simpler version of GitKraken, albeit without some of the integrations.
- If it's not already installed, download it at [their website](https://desktop.github.com/) and run the installer.
- If it is already installed, go to File > Options...
- Click "Sign out", then "Sign in". (Make sure you're actually signed in to GitHub on your browser first.)
- A webpage will open requesting access to your GitHub account. Click "Authenticate".
- You should be automatically redirected back to GitHub Desktop.

You're not done! You need to clone (download) the robot code to your computer in order to edit it on VS Code. (You'll need to be a part of the Team2530 Organization first.)
- Go to File > Clone repository...
- Select "Team2530/RobotCodeYYYY" (where "YYYY" is the current season) from the list that appears.
- Under "Local path", click the Choose button and select a location on your computer. (It doesn't matter where -- though it might be a good idea to put it somewhere you'll remember.)
 - Hit the Clone button!

### Git Extension for VS Code
This is the most convenient method, but it may require some knowledge of Git commands. The VS Code extension is included with the WPILib package you installed earlier, so if Git is installed on your computer, you should be able to start using it right away. (If Git isn't installed, a notification should appear that prompts you to download it.) Controls are accessible via the Source Control tab on the left toolbar of VS Code.

## Using the Source Control tab on the web version (not recommended)
If you're using the web version of VS Code on a Chromebook or another device, you can simply use the Source Control tab on the left side of the screen. Since it's directly integrated with GitHub, you should be able to use it without any setup.