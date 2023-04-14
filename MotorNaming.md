---
Title: Motor Naming Conventions
category: pages
layout: default
---

# Motor Naming Conventions

The motor naming conventions are as follows...

1. Start at the front right side of the robot move in a clockwise fashion, naming every motor that you come across (starting with 1)
2. Once you have named all motors in the same level, move upwards on the robot, using the same clockwise motion and naming conventions. 


*If the O's are drive motors, and the plus is a motor above the rest of the robot, the motor numbers would be as follows:*

## Tank Drive Example

```
  [-------]
 [   +++   ]
 [O       O]
 [O       O]
 [         ]
  [-------]

Motors would be named as follows:

  [-------]
 [   675   ]
 [4       1]
 [3       2]
 [         ]
  [-------]
```

## Swerve Drive Example

```
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