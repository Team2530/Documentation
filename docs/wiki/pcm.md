# PCM

!!! warning "This page is not finished!"

    If you are a team member and know more about this topic than what is currently here please contribute that information.

PCM stands for **P**neumatic **C**ontrol **M**odule. It contains all the inputs and outputs required to control pneumatic solanoids and a compressor.

It is controlled by the [[RoboRIO]] over [[CAN]].

## PCM Troubleshooting

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

## Further Reading

- <https://www.firstinspires.org/sites/default/files/uploads/resource_library/frc/technical-resources/frc_pneumatics_manual.pdf>