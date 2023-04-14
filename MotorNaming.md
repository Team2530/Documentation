---
Title: Motor Naming Conventions
category: pages
layout: default
---

# Motor Naming Conventions

The motor naming conventions are as follows...

1. Start at the front center side of the robot move in a clockwise fashion, naming every motor that you come across (starting with 1). 
2. Once you have named all motors in the same level, move upwards on the robot, using the same clockwise motion and naming conventions. 


*If the O's are drive motors, and the pluses are motors above the rest of the robot, the motor numbers would be as follows:*

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
 [   756   ]
 [4       1]
 [3       2]
 [         ]
  [-------]

```

The motor in the middle of the robot gets named first on that layer as you start in the front center of the robot, and move in the same clockwise fashion to name the rest.

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