---
Title: PCM Troubleshooting
category: pages
layout: default
---
# PCM Troubleshooting
As with most troubleshooting, this is mostly common sense.

First, you'll want to see what info you can gather from the device itself. Using the following diagram, check the status LED and try to narrow down the problem. 

| LED       | Strobe                    | Slow                                      | Long              |
| --------- | ------------------------- | ----------------------------------------- | ----------------- |
| Green     | No fault, robot enabled   | Sticky fault                              | N/A               |
| Orange    | N/A                       | Sticky fault                              | N/A               |
| Red       | N/A                       | No CAN communication or solenoid fault    | Compressor Fault  |

Once you have done that (the fastest step), try to launch the diagnostic software Phoenix Tuner, assuming you haven't solved it yet.

- If you can connect over WiFi, great, that's the easiest way. If not, try to find yourself a USB-B to USB-A cable to connect directly to the RoboRio, and select RoboRio over USB from the Phoenix Tuner Diagnostic Server Address dropdown menu. 
- select the PCM from the upper "selected device" dropdown, and go to the Self-Test tab.
- Press Self-Test at the bottom, and interpret the results. (This takes some common sense and reading comprehension.)