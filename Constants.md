---
Title: Constants
category: pages
layout: default
---

# Constants

Constants are values that will stay the same **while the robot runs**, such as wheel sizes and motor ports. They're a useful way to change specific aspects of the robot without being familiar with the code for those components, which makes them essential in a team setting. They're all stored in `Constants.java` to make it even more convenient.

## Changing constants
This is pretty much just common sense.
1. Open `Constants.java`.
2. Find the constant you want to edit. The provided sections should help you.
3. Change its value.

## Adding constants
This is also pretty simple.
1. Open `Constants.java`.
2. Locate the section your constant should go in. (You can create one if needed -- just copy the heading from another section.)
3. At the bottom of the section, type `public static final TYPE NAME = VALUE;`, where `TYPE` is the [data type](https://www.w3schools.com/java/java_data_types.asp), `NAME` is whatever you want to name your constant, and `VALUE` is the value of your constant.

## Using constants
1. Open the file you want to use the constant in.
2. In the imports area, type `import frc.robot.Constants.NAME;`, where `NAME` is the name of the constant.
3. Whenever you need the constant's value, simply type the constant's name.

Alternatively, you can just import all of the constants right away by typing `import frc.robot.Constants`. Then, just type `Constants.` before typing your constant's name. Whether or not you do this is up to personal preference.

***

If you've read every article up to this point, you've learned the basics of FRC programming! All that's left is putting it into practice with specific components of the robot. Get started by learning about [programming motors](https://github.com/Team2530/Documentation/wiki/Programming-motors). For any components not documented in this wiki, you should be able to figure out how to program them by either looking at current/previous years' programming of them or looking up the official documentation.