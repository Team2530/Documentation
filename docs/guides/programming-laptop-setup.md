# How to setup a programming laptop

!!! tip "Prerequisite: Windows 10/11"

    This guide assumes that you have Windows 10 or Windows 11 installed on the laptop. It is possible to install some of the tools on Linux and Mac, but NI Game Tools supports Windows exclusively, and it is required to be able to control the robot from a laptop.

## List of Software to install

| Program Name | Annual Updates needed | Description                                                              | Download Link |
| ------------ | --------------------- | ------------------------------------------------------------------------ | ------------- |
| Google Chrome | No | Microsoft Edge is not suitable for programming. Any other browser, like Google Chrome, Firefox or Opera GX will work. | <https://www.google.com/chrome/> |
| WPILib       | Yes                   | WPILib is a suite of tools for FRC. Includes VSCode and some other gems. | <https://github.com/wpilibsuite/allwpilib/releases> |
| VSCode Extension Pack for Java | No | This extension by Red Hat has all of the vscode extensions you will need to write code in Java. | Use the extensions tab in VSCode. You can find it by clicking on the icon with four boxes on the left side of the screen or by pressing ++ctrl+shift+x++. |
| NI Game Tools | Yes | This allows you to connect to the robot. Includes Driver's Station and RoboRIO imaging tool. To download the installer file you need to create a free account. Typically one person on the team will do this and then distribute the files to everyone else. | <https://www.ni.com/en/support/downloads/drivers/download.frc-game-tools.html> |
| Git for Windows | No | This program contains Git Bash, a tool for interacting with git repositories on the command line. | <https://github.com/git-for-windows/git/releases/tag/v2.49.0.windows.1> |
| PathPlanner | Yes | PathPlanner is a tool for designing autonomous routes. You should install this from the windows store to get automatic updates. | <https://apps.microsoft.com/detail/9nqbkb5dw909?ocid=webpdpshare> |
| Phoenix Tuner | Yes | Phonenix tuner allows for debugging and configuration of CTRE devices. | <https://apps.microsoft.com/detail/9nvv4pwdw27z?ocid=webpdpshare> |
| REV Hardware Client | Yes | Allows for managament of REV devices like the PDH. | <https://docs.revrobotics.com/rev-hardware-client> |
| Cloudflare WARP | Maybe? | This is a VPN that allows you to bypass the internet restrictions at Kellogg. This is needed because they block important websites/protocols that our team uses like Discord and SSH. | <https://docs.revrobotics.com/rev-hardware-client> |

### List of software not to install

- Discord - use the web version available at <https://discord.com/app> instead.
- Games or other applications that aren't robotics-related

## Automated Python script

This script has been used in the past to automate the process of onboarding new team laptops. It removes old software, installs new software, collect system information and then sets the desktop wallpaper to a random image out of a folder.

```py title="laptop-setup.py"
################################################
#####  TEAM 2530 LAPTOP ONBOARDING SCRIPT  #####
################################################

import platform, json, zipfile, sys, socket, re, psutil, uuid, shutil, subprocess, os, random, ctypes

# 0: Get admin perms

def run_as_admin(argv=None, debug=False):
    shell32 = ctypes.windll.shell32
    if argv is None and shell32.IsUserAnAdmin():
        return True

    if argv is None:
        argv = sys.argv
    if hasattr(sys, '_MEIPASS'):
        # Support pyinstaller wrapped program.
        arguments = map(str, argv[1:])
    else:
        arguments = map(str, argv)
    argument_line = u' '.join(arguments)
    executable = str(sys.executable)
    if debug:
        print('Command line: ', executable, argument_line)
    ret = shell32.ShellExecuteW(None, u"runas", executable, argument_line, None, 1)
    if int(ret) <= 32:
        return False
    return None


ret = run_as_admin()
if ret is True:
    print("Access granted")
elif ret is None:
    exit(0)
else:
    print ('Error(ret=%d): cannot elevate privilege.' % (ret, ))
    exit(0)


#####################################
### 1: Collect system information ###
#####################################

print("[01] - Collect system information")

def get_system_info():
    info = {}
    info["platform"] = platform.system()
    info["release"] = platform.release()
    info["version"] = platform.version()
    info["arch"] = platform.machine()
    info["hostname"] = socket.gethostname()
    info["mac"] = ":".join(re.findall("..", "%012x" % uuid.getnode()))
    info["processor"] = platform.processor()
    info["ram"] = str(round(psutil.virtual_memory().total / (1024.0 ** 3))) + "GB"

    disk_usage = psutil.disk_usage("C:\\")
    info["disk_used"] = disk_usage.used
    info["disk_total"] = disk_usage.total

    return info

system_info = get_system_info()
with open(f"laptop_info\\{system_info['disk_used']}.json", "w") as fp:
    fp.write(json.dumps(system_info))

#####################################
### 2: Delete old tools           ###
#####################################

print("[02] - Delete old tools")

try:
    shutil.rmtree("C:\\Users\\Public\\wpilib")
except FileNotFoundError:
    pass

#####################################
### 3: Install new tools          ###
#####################################

print("[03] - Install new tools")

# WPILib
subprocess.Popen(".\\wpilib_installer\\WPILibInstaller.exe", cwd=".\\wpilib_installer")

# REV Hardware client
subprocess.Popen(".\\REV-Hardware-Client-Setup-1.6.6.exe")

# Git for windows
subprocess.Popen(".\\Git-2.47.1-64-bit.exe")

# Marktext
subprocess.Popen(".\\marktext-setup.exe")


#####################################
### 4: Configuration              ###
#####################################

print("[04] - System Configuration")

image = random.choice(os.listdir(".\\wallpapers"))

shutil.copy(f".\\wallpapers\\{image}", os.path.expanduser("~\\Documents\\"))

image_path = os.path.expanduser(f"~\\Documents\\{image}")

ctypes.windll.user32.SystemParametersInfoW(20, 0, image_path, 0)
```

If you want to use this script, you will need to do these things:

1. Find a USB with enough space for all of the installer files and wallpapers
2. Download installers for everything onto the USB
3. Update the paths to all of the installer files and add any new installers that you want.
4. Find or create team desktop wallpapers and put them in a folder on the USB called `wallpapers`.
5. Plug in the USB to each computer and run the script.
