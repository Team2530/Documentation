# Motor

!!! warning "This page is not finished!"

    If you are a team member and know more about this topic than what is currently here please contribute that information.

## Legal FRC Motors

As of 2025, this is the list of all legal FRC motors. This was found in the 2025 [[Game Manual]].

| Motor Name | Part Numbers Available |
| ---------- | ---------------------- |
| AndyMark 9015 | am-0912 AndyMark 9015 |
| AndyMark NeveRest | am-3104 |
| AndyMark PG | am-2161 (alt. PN am-2765) am-2194 (alt. PN am-2766) |
| AndyMark RedLine Motor | am-3775 am-3775a |
| AndyMark Snow Blower Motor | am-2235 am-2235a |
| Banebots | am-3830 M7-RS775-18 RS775WC-8514 M5 – RS550-12 RS550VC-7527 RS550 |
| CIM | FR801-001 M4-R0062-12 AM802-001A 217-2000 PM25R-44F-1005 PM25R-45F-1004 PM25R-45F-1003 PMR25R-45F-1003 PMR25R-44F-1005 am-0255 |
| CTR Electronics Minion | 24-777378 WCP-1691 |
| CTR Electronics/VEX Robotics Falcon 500 | 217-6515 am-6515 19-708850 am-6515_Short |
| Current/former KOP automotive motors | Denso AE235100-0160 Denso 5-163800-RC1 Denso 262100-3030 Denso 262100-3040 Bosch 6 004 RA3 194-06 Johnson Electric JE-PLG-149 Johnson Electric  |JE-PLG-410
| Nidec Dynamo BLDC Motor | am-3740 DM3012-1063 |
| Playing with Fusion Venom | BDC-10001 |
| REV Robotics HD Hex | REV-41-1291 |
| REV Robotics NEO Brushless | REV-21-1650 (v1.0 or v1.1) am-4258 am-4258a |
| REV Robotics NEO 550 | REV-21-1651 am-4259 |
| REV Robotics NEO Vortex | REV-21-1652 am-5275 |
| VEX BAG | 217-3351 |
| VEX Mini-CIM | 217-3371 |
| West Coast Products Kraken x44 | WCP-0941 |
| West Coast Products Kraken x60 | WCP-0940 am-5274 |
| West Coast Products RS775 Pro | 217-4347 |


## Motor Naming Conventions

The motor naming conventions are as follows...

1. Start at the front center side of the robot move in a clockwise fashion, naming every motor that you come across (starting with 1). 
2. Once you have named all motors on the same level, move upwards on the robot, using the same clockwise motion and naming conventions. 


*If the O's are drive motors, and the pluses are motors above the rest of the robot, the motor numbers would be as follows:*

### Tank Drive Example

```text
  [-------]
 [   +++   ]
 [O       O]
 [O     + O]
 [         ]
  [-------]

Motors would be named as follows:

  [-------]
 [   856   ]
 [4       1]
 [3     7 2]
 [         ]
  [-------]

```

The motor in the middle of the robot gets named first on that layer as you start in the front center of the robot, and move in the same clockwise fashion to name the rest.

### Swerve Drive Example

```text
  O-------O
 O         O
 [  +      ]
 [    +    ]
 O         O
  O-------O

Motors would be named as follows:

  8-------1
 7         2
 [ 10      ]
 [    9    ]
 6         3
  5-------4
```


## Sources & Further Reading

- <https://frcdesign.org/learning-course/stage1/1B/motors/>
- <https://frcdesign.org/learning-course/stage1/1B/torque-speed/>
- <https://www.chiefdelphi.com/uploads/default/original/3X/d/2/d2495ff57e402e93bb479171750bb6b05ec8e594.pdf>