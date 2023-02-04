---
Title: PCM Troubleshooting
category: pages
layout: post
---
As with most troubleshooting, this is mostly common sense.

First, you'll want to see what info you can gather from the device itself. Using the following diagram, try to narrow down the problem. 

Amber indicates a sticky fault, more information of which can be gathered from Pheonix Tuner. Red (as the diagram says) indicates either problems with CAN, or if a solenoid light is on, a solenoid problem.
![PCM Status Light quick reference](https://wpilib.screenstepslive.com/s/currentCS/m/cs_hardware/l/144972-status-light-quick-reference/show_image?image_id=4484910)

Once you have done that (the fastest step), try to launch the diagnostic software Phoenix Tuner, assuming you haven't solved it yet.
- If you can connect over WiFi, great, that's the easiest way. If not, try to find yourself a USB-B to USB-A cable to connect directly to the RoboRio, and select RoboRio over USB from the Phoenix Tuner Diagnostic Server Address dropdown menu. 
- select the PCM from the upper "selected device" dropdown, and go to the Self-Test tab.
- Press Self-Test at the bottom, and interpret the results. (This takes some common sense and reading comprehension.)