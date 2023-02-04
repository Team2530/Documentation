---
Title: Setting up the Raspberry Pi
category: pages
layout: post
---
This page will explain how to set up the Pixy with the Raspberry Pi.

### Powering The Pi
Plug in the jumper wires into pins 4 and 6, with the red wire into 4 and the black wire into 6. Make sure to give the Raspberry Pi at LEAST 2 amps at 5 volts. Anything lower, and you might experience unnatural behavior of the Pi and a possible unexpected shutdown. Also, make sure to NOT give it 12 volts through the pins as this will instantly burn out the Pi. It will be dead forever. 
![Raspberry Pi GPIO](https://www.bigmessowires.com/wp-content/uploads/2018/05/Raspberry-GPIO.jpg)

### Enabling WiFi on the Pi
First you need to edit the blacklist file. Use ```sudo nano /etc/modprode.d/raspi-blacklist.conf```. Make sure your file system is set to read and write. For this use ```sudo mount -o rw, remount /```. After you have opened the file, comment out every line of code by typing a ```#``` at the beginning of every line. After that is done, use Ctrl+X to exit. When it asks, press ```y```, and press enter. After you are in the CLI, reboot the Pi by typing ```sudo reboot```

### Connecting the Pixy
Even simpler, just take the USB Micro-B to USB-A cable that came bundled with the Pixy2Cam and plug it in to one of the USB ports on the Raspberry Pi. You will need to install some other software to make it actually have an image feed working and things like that which will be talked about later in this guide. 



## Software
Setting up the software for the Raspberry Pi is very straightforward. Instructions on how to do that can be found [here](https://wpilib.screenstepslive.com/s/currentCS/m/85074/l/1027241-using-the-raspberry-pi-for-frc).

#### The Raspberry Pi should be located at 10.25.30.5, a static IP. If it isn't, fix that.

Setting up the Pixy2 on the software side is a little more complicated. Instructions for installing pixymon on linux can be found [here](https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:installing_pixymon_on_linux). For Mac OS X [here](https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:install_pixymon_on_mac), and for Windows click [here](https://github.com/charmedlabs/pixy2/raw/master/releases/pixymon_windows/pixymon_v2_windows-3.0.24.exe). This is a direct download link however. Just run the exe and you should be up and running in no time. 

Instructions for installing libpixyusb on linux can be found [here](https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:building_the_libpixyusb_example_on_linux). To build the python code examples, click [here](http://www.cmucam.org/projects/cmucam5/wiki/Building_libpixyusb_as_a_Python_module_on_Linux) for the tutorial.