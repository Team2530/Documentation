---
Title: Code Style Guide
category: pages
order: 1
---
Code is most readable when it's written in a consistent _style_, especially in a team setting. Please keep the following conventions in mind while writing Java for the robot. If there are any you don't understand, refer to the example at the bottom or ask a mentor/lead.
- Use **camel case** for regular variable and method names. Please name them with words or common abbreviations (like PID) if possible.
- Use **all-caps snake case** for constant variable names. Also name these with words or common abbreviations.
- In statements, put **one space** between the reserved word and the parentheses (and the curly bracket if you have one.)
- The first curly bracket of a block **should not go on its own line.**
- The contents of a block should only be **single-indented.**
- Use **one empty line** to separate sections of code and method definitions. Sections include `import`s, the instance variables, the constructor, and then everything below. You can make subsections of these too, but be careful not to make too many.
- Try to keep individual lines of code **under 120 characters.** VS Code has a faint grey line as you scroll right to help indicate this. If you need to shorten a line, try creating "temporary" variables to split up and store individual components.
- Don't forget to remember to **use plenty of comments.** If you think you're using enough comments, you probably need to add more.
- If you can't remember a specific convention or don't understand one yet, just look around the code and **use common sense.** As long as it looks okay, it's probably fine.
- Nesting is bad. If you can avoid it, do so.

You should get in the habit of using `Shift + Alt + F` often - this is a shortcut in VS Code that performs some formatting on your code automatically, such as spacing, bracket placement, and line character limits. This is especially useful when copy-pasting.

Example:
```java
// Imports
import java.example;

// Instance variables
final boolean EXAMPLE_CONSTANT = true;
boolean exampleVariable;

// Constructor
public Example(boolean exampleVariable) {
    this.exampleVariable = exampleVariable;
}

// Other code
if (exampleVariable) {
    doCode();
} else {
    // Remember to use plenty of comments
    doOtherCode();
}

// Method
public void doCode() {
    // This is a "temporary" variable used for splitting up a long line of code
    boolean exampleSplit = exampleVariable.doSomething().doSomethingElse();
    exampleSplit.doOneMoreThingThatMadeThePreviousLineTooLong();
    System.out.println("This is pretty nice code");
}

/**
 * You might also see some comments that look like this.
 * This is called Javadoc. It's responsible for the tooltips VS Code shows when you hover over something.
 * If you have experience with JSDoc, it's basically the same thing.
 */
public void doOtherCode() {
    System.out.println("This is pretty nice code");
} 
```