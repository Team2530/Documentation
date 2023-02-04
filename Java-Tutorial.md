Hello! Welcome to Team 2530's Java Tutorial! This is a basic overview of Java programming in general, and more in depth tutorials can be found [here](https://www.w3schools.com/java/). Again, this tutorial will cover the basics of Java programming, but it is recommended that you do some exploring and work on your own.

Throughout this Tutorial, a bit of code will be referenced which runs [Langton's Ant](https://en.wikipedia.org/wiki/Langton%27s_ant).

The code below is the entire program. It is recommended that you put this code into some sort of editor so you can see what is going on. One that requires an account to be made, but has several nice features is [Replit](https://replit.com).

```java
class Main {
  public static final String ANSI_RED = "\u001B[31m";
  public static final String ANSI_RESET = "\u001B[0m";
  public static final String ANSI_BLACK = "\u001B[30m";
  public static void main(String[] args) {
    int matrixSize = 75;
    int direction = 1;
    int realAntX = matrixSize / 2;
    int realAntY = matrixSize / 2;
    int[] antNew = {0 , 0};
    int matrix[][] = makeMatrix(matrixSize);
    
    // moves before the ant stops
    int ticks = 11000;

    
    System.out.println();
    printMatrix(matrix , matrixSize);
    matrix[matrixSize / 2][matrixSize / 2] = 1;
    System.out.println();
    int iterations = 0;

    while(ticks > iterations){
      // return new position of ant
      System.out.println(direction);
      antNew = moveAnt(realAntX, realAntY, direction);
      realAntX = antNew[0];
      realAntY = antNew[1];
      // determine the direction we want the ant to go
      direction = direction(direction, matrix, realAntX, realAntY);
      // set the matrix to the opposite number
      matrix[realAntX][realAntY] = matrixGet(realAntX, realAntY, matrix);
      iterations += 1;
  }
  System.out.println();
  printMatrix(matrix , matrixSize);
}

  public static int[][] makeMatrix(int size){
    return new int[size][size];
  }
  public static void printMatrix(int[][] m, int size){
    for(int i = 0; i < size  ; i++) {
      System.out.println();
      for(int a = 0; a < size ; a++){
        if(m[i][a] == 1) {
          System.out.print(ANSI_RED + m[i][a] + ANSI_RESET +  " ");
        } else {
          System.out.print(ANSI_BLACK + m[i][a] + ANSI_RESET + " ");
        }
        
      }
    }
  }
  public static int[] moveAnt(int antx, int anty, int dir){
    if(dir == 1){
      anty += 1;
    } else if (dir == 3){
      anty -= 1;
    }
    if (dir == 2){
      antx += 1;
    } else if (dir == 4){
      antx -= 1;
    }
    int[] newAnt = {antx, anty};
    return newAnt;
  }


  public static int direction(int dir, int[][] m , int antx, int anty){
    if (m[antx][anty] == 1){
      dir += 1;
    } else if (m[antx][anty] == 0){
      dir -= 1;
    }
    if(dir > 4) {
      dir = 1;
    } else if(dir < 1) {
      dir = 4;
    }
    return dir;
  }
  public static int matrixGet(int antx, int anty, int[][] m){
    if(m[antx][anty] == 1){
      return 0;
    } else if (m[antx][anty] == 0){
      return 1;
    }
    return 200;
  }
}
```

This may seem like a lot, but don't worry, It will be broken down into little parts that will make sense in the end.


# Java Variables

One thing you may have noticed is that each variable, or name that holds a specific value, has a specific keyword before it. Each of these have there own uses. 
```java
int apples = 5;
String bananas = "yellow";
boolean perhaps = true;
double x = 1.5;
int[][] matrix = {{1,3},{2,7}}
```
`int` is used to define numbers without a decimal, so things like 2530 or 517.

`String` defines a collection of characters.

`boolean` defines a logic operator of either true or false.

`double` defines a number with a decimal point such as 12.34 or 97.5602

Note that each uses `=` as an assignment operator, which defines the value of whatever name you gave your variable.

There are also slightly more complex things like int[] or int[][] which represent an array and a matrix respectively. Note that when using arrays or matrices, they don't always have to be numbers, they can also be characters and strings.

`int[]` defines an array of numbers. An array is basically a list of numbers which can be used to make things more compact and minimize the number of variables that are used.

`int[][]` defines a matrix which can be used to store values, in this case, integers in a specific place in 2D. So, if you have the matrix below and want the 7, you would ask for int[][]'s name (which is matrix in the above example) at the position that you want. Note that in many programming languages, the first number or element is called "0". Java Matrices are named row (x wise) then by column (y wise).
```
1  3

2  7

matrix[1][1] returns 7
```

Try creating and getting values from your own matrices! Remember that this tutorial is here to help guide you, and a lot can be learned from writing and refining simple code.

# Java Syntax and Printing

You also may notice the use of `System.out.println();` and the `;`

Java uses the semicolon to distinguish between lines, so don't forget to use it on nearly every line (Unless the line ends with `{`, but don't worry about those yet)

`System.out.println()` allows the programmer to get feedback about what the program is doing and can be useful for debugging programs and verify that everything is running smoothly.

There are various ways to use `System.out.println()` and the main ones you should know are printing strings and numbers. The third example will print the String, a space, and the number at the end.

You will also notice the use of `//`. This is the Java version of comments which can be used to write notes in your code. Anything written on the same line as these will be ignored by the program when executing. It is very helpful to comment out your code so others get a general "map" of what is happening, especially if it is hard to understand.

```java
System.out.println("This will print a string"); // prints the string
System.out.println(number); // prints the value of number
System.out.println("Your Number is:" + " " + number); prints a string, a space, and the value of number
```

# Java Statements and Loops

Many things in Java use If and For statements, and they make your code run much smoother.

Note that all of the Statements and Loops don't use a `;` at the end of the line, but rather a `{`. Anything contained within the boundaries of the end bracket will be run in the loop.

## If Statements

The Java If statement will run the code inside of it if and only if certain conditions are met. If you want to do something like move the robot only if it has turned first, you would do something like

```java
if(robot.hasTurned == true){
 robot.moveForward;
} else {
 robot.stop;
}
```

Real code won't look exactly as it does above, but you can start to see what is happening.

Note that the `if` statement uses `==` as a comparing operation. Because one `=` is the assignment operator, the `==` is used to compare two sides of the statement. The code above is saying that **if and only if** the robot has turned, it should move forward. If for whatever reason it hasn't accomplished that task, the else statement provides the alternative, the robot has to stop. You may also use `else if` statement to provide another statement if the first one isn't met.

```java
if(robot.hasTurned == true){
 robot.moveForward;
} else if(robot.isTurning) {
 robot.keepTurning;
} else {
 robot.stop;
}
```

This code is fundamentally the same as before, just with one added twist, if the robot is currently turning, it should keep turning. The `else if` statement provides another option if the first one isn't met instead of the first `if` being the one to handle everything.

## For Loops

For loops are for repeated tasks in a simple sense. A `for` loop will got through a block of code exactly how many times you specify it to, so in our case, it is used to print out all of the values in our matrix.

```java
for(int i = 0; i < 5; i++){
 int a += 1;
}
```

Assuming that our variable a starts at 0, the end result of "a" will be 5. The first argument is your starting variable; it can be whatever name you would like. It needs to have a value, but it can be something that is defined earlier in the code. The second argument it how long it should run for. Read this as "while i is less than 5" to make it easier to understand. The last argument is what should be done with your variable that you passed in at the start. You can increase it by using `++` or decrease by using `--`.

Also note the use of `+=`. This will increment whatever value you put into the statement by whatever follows it. It is just shorthand and means the same thing as `a = a + 1;`. You can also do `-=` for the same thing except decreasing.

## While Loops

While Loops are very useful as they run a given block of code until a certain condition is met.

Note that the syntax looks similar to that of the `if` statement.

```java
int a = 0;
while(a < 5){
System.out.println("a is:" + " " + a);
a+= 1;
}
```

If you run this code, notice that it only prints up to `a is: 4`. This is because now that "a" is actually five, it isn't less than 5 and the loop ends. If you wanted to get to 5, you would need to change the `<` operator to a `<=` operator.

# Java Methods

Methods are a great way to write reusable code. Methods have specific deceleration, so pay close attention to how they are made. 

Lets say you want a method to make the robot go forward

```java
public static void driveForward(){
 if(robot.isMoving){
  robot.stop;
 }
 robot.goForward;
}
```

The start of the method is defined as `public`. This means just what you probably think it does; it can be accessed from anywhere in the file and in others.

`void` means that the method isn't expected to return any number, string, boolean, array, etc. If you wanted to return one of the previously mentioned items, you simply need to replace void with one of the types such as `int` or `boolean`.

Everything inside of the method `driveForward()` will be run each time it is called. You can put `if`, `for`, and `while` loops inside of methods.

You may also need to pass in parameters to a method which is done simply by putting the type you are passing and a name to be referenced as inside the method.

```java
public int multiply(int a, int b){
 System.out.println(a * b);
 return a * b;
}
```

If you call `multiply(5, 10)`, the method would spit out 50 as its result. Use `return` whenever you have what you need to return, but after a value is returned, none of the following code in the method will be run.


# Explaining Langton's Ant

You know now much of everything you need to know about programming in Java. Don't worry if some things still don't make sense; it takes a while and some playing around with code until things will really start to make sense. Once again, if you are stuck or there is something you need to know more about, you can search it up or look at the [W3 Schools Tutorial](https://www.w3schools.com/java).

```java
class Main {
  public static final String ANSI_RED = "\u001B[31m";
  public static final String ANSI_RESET = "\u001B[0m";
  public static final String ANSI_BLACK = "\u001B[30m";
  public static void main(String[] args) {
    int matrixSize = 75;
    int direction = 1;
    int realAntX = matrixSize / 2;
    int realAntY = matrixSize / 2;
    int[] antNew = {0 , 0};
    int matrix[][] = makeMatrix(matrixSize);
```

The code starts off with the declaration of our class as well as some variables that we will be using throughout the rest of the program. The strings are the beginning are for making colors print in the console. The line `public static void main(String[] args) {` is simply Java's way of telling what gets run and what is other things. `makeMatrix()` is also called which returns an `int[][]` to serve as the matrix for the ant.


```java
    // moves before the ant stops
    int ticks = 11000;

    
    System.out.println();
    printMatrix(matrix , matrixSize);
    matrix[matrixSize / 2][matrixSize / 2] = 1;
    System.out.println();
    int iterations = 0;
```

More setup code is performed like printing the matrix with the method `printMatrix(matrix, matrixSize)`. When trying to print an actual matrix with `System.out.println()`, you will get something like `[[I@2ff4acd0`. To fix this so you can see the actual values of each of the indices in the matrix, we use a for loop to go through all of the elements.

```java
 while(ticks > iterations){
      // return new position of ant
      System.out.println(direction);
      antNew = moveAnt(realAntX, realAntY, direction);
      realAntX = antNew[0];
      realAntY = antNew[1];
      // determine the direction we want the ant to go
      direction = direction(direction, matrix, realAntX, realAntY);
      // set the matrix to the opposite number
      matrix[realAntX][realAntY] = matrixGet(realAntX, realAntY, matrix);
      iterations += 1;
  }
  System.out.println();
  printMatrix(matrix , matrixSize);
}
```

This is the main chunk of the code that isn't the methods below. The while loop runs for as many times as specified by the value of ticks set earlier. Each of the methods will be explained below, so don't worry about those just yet. The position of the ant is stored into temporary values. Once the loop is done running, a blank print puts a space to make it look nice, and then the final matrix is printed.

```java
  public static int[][] makeMatrix(int size){
    return new int[size][size];
  }
  public static void printMatrix(int[][] m, int size){
    for(int i = 0; i < size  ; i++) {
      System.out.println();
      for(int a = 0; a < size ; a++){
        if(m[i][a] == 1) {
          System.out.print(ANSI_RED + m[i][a] + ANSI_RESET +  " ");
        } else {
          System.out.print(ANSI_BLACK + m[i][a] + ANSI_RESET + " ");
        }
        
      }
    }
  }
```
`makeMatrix(int size)` is really simple, but even simple methods make the code read easier

`printMatrix(int[][] m, int size)` takes the matrix and its size into account. The two for loops work together to loop through the whole matrix. The first loop finishes a line, and the second prints a black "0" or a red "1". If you think about how the loops work together, the second runs for a whole line, and when that is finished, the first one adds one to its value, thus looping to the next line.

```java
  public static int[] moveAnt(int antx, int anty, int dir){
    if(dir == 1){
      anty += 1;
    } else if (dir == 3){
      anty -= 1;
    }
    if (dir == 2){
      antx += 1;
    } else if (dir == 4){
      antx -= 1;
    }
    int[] newAnt = {antx, anty};
    return newAnt;
  }
```

`moveAnt(int antx, int anty, int dir)` uses the ant's direction to determine what needs to happen to the ant's position. Depending on the variable `dir` a different value is added to the ants position. At the end, an array is returned to update the real ants position to that calculated in the method.

```java
  public static int direction(int dir, int[][] m , int antx, int anty){
    if (m[antx][anty] == 1){
      dir += 1;
    } else if (m[antx][anty] == 0){
      dir -= 1;
    }
    if(dir > 4) {
      dir = 1;
    } else if(dir < 1) {
      dir = 4;
    }
    return dir;
  }
```

If you didn't look at the page on [Langton's Ant](https://en.wikipedia.org/wiki/Langton%27s_ant), it is recommended. Basically, if the square is "on", the ant travels clockwise, and if the square is "off", the ant travels counterclockwise. The square is then inverted to be the opposite state of what it was. The first two if statements determine which direction that the ant needs to go, and the others make sure `dir` stays between 1 and 4. 

```java
  public static int matrixGet(int antx, int anty, int[][] m){
    if(m[antx][anty] == 1){
      return 0;
    } else if (m[antx][anty] == 0){
      return 1;
    }
    return 200;
  }
}
```

`matrixGet(int antx, int anty, int[][] m)` gets the opposite value of what the ant is currently sitting on so it can be set in the `while` loop.

Now that you know what each method does, it will probably make more sense about what is happening in the while loop.

```java
 while(ticks > iterations){
      // return new position of ant
      System.out.println(direction);
      antNew = moveAnt(realAntX, realAntY, direction);
      realAntX = antNew[0];
      realAntY = antNew[1];
      // determine the direction we want the ant to go
      direction = direction(direction, matrix, realAntX, realAntY);
      // set the matrix to the opposite number
      matrix[realAntX][realAntY] = matrixGet(realAntX, realAntY, matrix);
      iterations += 1;
  }
  System.out.println();
  printMatrix(matrix , matrixSize);
}
```

Hopefully you found this tutorial helpful! There is a lot that has been left out of this tutorial, so if you need extra help, make a quick search on the interwebs. Many programmers use the Internet all the time to see how other people have accomplished the same tasks, and I implore you to take a look at how others approached making Langton's Ant. 

Remember that to really get good at Java Programming takes a lot of time, and don't be afraid of failing! Good luck in your Java adventure!