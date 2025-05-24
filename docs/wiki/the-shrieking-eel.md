# The Shrieking Eel

The Shrieking Eel was our robot for the 2024-25 season [[Reefscape]].

![A CAD rendering of the robot](../assets/images/shrieking-eel.png)

## Design

### Frame and Drivetrain

The Eel is a [[Swerve Drive]] robot. We use Mk4i modules with an L2 gearing in order to accelerate quickly for short cycle times. The drive motors are [[Kraken x60]]s, and the steering motors are [[NEO 1.1]]s. We 3D-printed wheel well guards to protect the drive train from dirt and debris. The wheels are [Black Neoprene Billet wheels](https://www.swervedrivespecialties.com/products/billet-wheel-4d-x-1-5w-bearing-bore) from [[Swerve Drive Specialties]], with an outside diameter (OD) of 4" and a width of 1.5". We use [[CANCoder]]s to measure the absolute rotation of the wheels.

![A view of a single swerve module](../assets/images/shrieking-eel-swerve-module.png)

![SDS Black Neoprene Billet Wheel](../assets/images/sds-billet-wheels.png)

The frame perimeter is 29.5"x29.5". The baseplate is made of 3mm polycarbonate instead of HDPE for weight reasons, inspectability and frame rigidity. It is dropped by 0.75" with a aluminum blocks between the swerve module plate and the frame. Lowering the baseplate prevents bumps on the field and also reduces the risk of high-centering[^1] on algae gamepieces. The rails on the frame are made of [[8020|80/20]] #1020, with aluminum blocks to lower the [[Center of Gravity|CG]]. [[Eye bolts]] were added in the drop blocks to add carrying straps.

![A top-down view of the drivetrain](../assets/images/shrieking-eel-drive-train.png)

[^1]: [High-centering](https://en.wiktionary.org/wiki/high-center) means to "become stranded with all wheels off the ground" according to Wiktionary.

### Bumpers

This year's game manual introduced changes to bumper requirements, and we went through a lengthy design process to make them more sophisticated than ever.

Each set of bumpers (4 pieces in total, 2 red and 2 blue) takes the form of two U-shaped halves that form a rectangle.

!!! warning "Not finished"

    This section is a work in progress. An exploded view would be very nice, and it has been said that the backer components might not be made out of oak plywood anymore due to weight reduction.

Backer components are made of oak plywood, and have a height of 5in and a thickness of 0.7 inches.

The foam has two layers instead of three for shock reduction and simplicity. The inner layer is made of 2” Polyethylene (PE) Foam 1.7#/cuft from Foam Factory, <Foambymail.com>. The outer layer is made of 1" EVA Floor tiles (self measured density 4.3#/cuft:  Prosource Extra Thick EVA Foam Interlocking Tiles (Amazon)).

The red/blue cloth covers on the bumpers are made of Seattle Fabrics' 1000D Cordura Nylon. The numbers "2530" were printed as vinyl stickers. Comic sans was chosen as a font after a short survey.

These components were used for the brackets and mounts:  

- Corner Brackets: 2" Aluminum L channel 2" bracket
- Plummer Industries Vertical Mounts for frame attachment
- Through bolt X 2 through the 80/20 frame on each long side of U bumper for stabilization

### Elevator

Our robot has a 2-stage cascade elevator with an arm/wrist mechanism on the top. The elevator is made of 1/16” thick 2x1 box tubes. It uses a [Billet Elevator Bearing Block](https://www.swervedrivespecialties.com/products/billet-elevator-bearing-block) by [[Swerve Drive Specialties|SDS]] for the bearing, and the rigging is #25 roller chain for the first stage and [[Dyneema rope]] from [[Thriftybot]] for the second. The elevator is driven by Kraken motors, and there are constant force springs that cancel some of the weight to allow it to accelerate quickly.

!!! todo "explain what the dyneema rope and #25 roller chain are used for." 

!!! todo "annotate the photo of the elevator, and add a photo of the elevator when it is extended"

!!! todo "try to add a wikilink or footnote for an explanation of how constant force springs are used here"

![A CAD render of the Elevator](../assets/images/shrieking-eel-elevator.png)

### Arm

The arm is attached by a joint to the second stage of the elevator. A [[NEO Vortex]] controls that joint, with a [[MAXPlanetary Gearbox]] and some other gears with an overall reduction of 96:1.

![A CAD render of the joint connecting the arm to the elevator](../assets/images/shrieking-eel-arm-joint.png)

The arm itself is made of 2x2 [[MAXTube]] from [[REV]].

### Wrist

At the end of the arm, there is a wrist with 2 [[Degrees of Freedom|DOF]] (pitch and roll). It is powered by two [[Neo 550]]s. One of the motors is located further back on the arm and controls the roll of the wrist, and the other is on the wrist and controls the pitch.

![A CAD render of the wrist](../assets/images/shrieking-eel-wrist.png)

### Coral Manipulator

The coral manipulator is mounted to the end of the wrist. It is shaped like a dust pan and uses two sets of compliant wheels powered by a [[Falcon 500]]. The wheels grip the inside of a coral gamepiece against the dustpan to intake it, and can be reversed to release the coral over the reef.

![A CAD render of the coral manipulator](../assets/images/shrieking-eel-coral-intake.png)

### Climber

### Algae Manipulators

### Sponsor Boards

### Electronics

### Vision System

## Links

- [Onshape CAD Model](https://cad.onshape.com/documents/fa9a0365dfdf7e376f93f1b4/w/36bfb0cc9de95ef5933791e3/e/700ba3cf920578fe61d3ec24)
- [2025 Technical Manual](https://docs.google.com/presentation/d/1bto5VCYEVELLXvQ6iPSqBrLyz7rDSPktWtszlaASRLY/edit?usp=sharing)
