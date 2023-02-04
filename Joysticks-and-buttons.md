---
Title: Joysticks and Buttons
category: pages
order: 1
---

You already learned the basics of button mapping in the [getting started article](https://github.com/Team2530/Documentation/wiki/Getting-started-with-the-robot), but this article goes more into the specifics of our controllers.

## Types of controllers
There are two different flavors of controllers, and the drive team tends to use both of them every year.

### Joystick
![[image of one of our joysticks]](https://images-na.ssl-images-amazon.com/images/I/414X2Z0A7TL._SY450_.jpg)

This is a large joystick that's used with the whole hand. It has a solid rubber base that prevents it from slipping around on the drive station. There are also various buttons on it which allow various actions to be performed quickly. This is typically used by the **driver**, who pilots the robot around the field. We have two of these available for use -- when we only use one, we call it **single-stick drive** or **arcade drive**, and when we use both, we call it **dual-stick drive** or **tank drive**.

### Xbox Controller
<img src="https://i.pinimg.com/originals/dc/4c/03/dc4c035665fe971d23b573594aff1d3d.jpg" width="500">

We also use a transparent Xbox One controller that can glow because we're fancy and epic gamer. In all seriousness, it's held with two hands and has a lot of buttons available for use. It's typically used by the **operator**, who manages the robot's internal systems such as the intake, revolver, shooter, etc. We just have one, but it's worth noting that it includes 2 joysticks and a D-pad, which is a more limited joystick.

## Using the controllers
Some notes on axis/buttons:
* Throttle is axis 3 (Joystick, used for powerfactor)
* Joystick buttons’ numbers are written on the button
* Most axises return between -1 and 1
* Triggers return between 0 and 1 or -1 and 0 (xbox)
* Joystick has 12 buttons each
* Xbox has 10 buttons, but only first 6 commonly used

Here are some external resources on each controller type:  
https://first.wpi.edu/FRC/roborio/beta/docs/java/edu/wpi/first/wpilibj/Joystick.html  
https://first.wpi.edu/FRC/roborio/beta/docs/java/edu/wpi/first/wpilibj/XboxController.html