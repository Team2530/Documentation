Subsystems are where methods are created and defined. They're organized by the part of the robot they're for (elevator, LimeLight, shooter, etc.)

### To create a new subsystem:
1. Right-click on the `subsystems` folder.
2. Go to the bottom of the context menu that appears and select "Create a new class/command".
3. In the input box that appears at the top, type/click `Subsystem (New)`.
4. Give it a relevant name.
5. Open `RobotContainer.java` and scroll down to where it says `// --- Subsystems --- \\`.
6. Below the other subsystem declarations, type `private final NAME VARNAME = new NAME();`, where NAME is the file name you gave your subsystem and VARNAME is a new name to reference in code. If applicable, add any required parameters in the parentheses.

### To add methods to a subsystem:
1. Open your subsystem's file.
2. Go to the very bottom of the file (just before the last bracket) and hit enter a couple of times. Then add a new method:
* Type `public`. This will allow the method to be used outside of the subsystem file.
* Type `void` if the method won't return a value. Otherwise, enter the data type you want the method to return.
* Type your method's name, then immediately afterwards, type a set of parentheses. `()`
* Inside the parentheses, add your parameters -- inputs that are passed into the method as premade variables. Like normal variables, you need to provide the data type and a parameter name.
* After the parentheses, type a `{` and press enter. This is where you'll write your method's code. In VSCode, a `}` should automatically appear where it needs to be.

### To call subsystem methods:
These methods shouldn't actually be run within the subsystem files, only defined. That's what [commands](https://github.com/Team2530/Documentation/wiki/Commands) are for.