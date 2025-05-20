# Gradle

Gradle is a tool used to simplify the management of all the vendor dependencies we use in our code.

## Usage

For the most part, you shouldn't need to interact much with Gradle's command line interface ([[CLI]]) or configuration files. [[WPILib]]'s [[VSCode]] extension handles everything for you.

## Files

### build.gradle

This file is written in a language called [[Groovy]], which is a superset[^1] of [[Java]].

This document is taken from our [2024 season robot code](https://github.com/Team2530/RobotCode2024/blob/main/build.gradle) and has been annotated with explanations of everything. Click on the plus signs to read the annotations.

```groovy title="build.gradle"
plugins /* (1)! */ {
    id "java"
    id "edu.wpi.first.GradleRIO" version "2024.1.1" // (2)!
}

java { // (3)!
    sourceCompatibility = JavaVersion.VERSION_17
    targetCompatibility = JavaVersion.VERSION_17
}

def ROBOT_MAIN_CLASS = "frc.robot.Main" // (4)!

// Define my targets (RoboRIO) and artifacts (deployable files)
// This is added by GradleRIO's backing project DeployUtils.
deploy {
    targets {
        roborio(getTargetTypeClass('RoboRIO')) {
            // Team number is loaded either from the .wpilib/wpilib_preferences.json
            // or from command line. If not found an exception will be thrown.
            // You can use getTeamOrDefault(team) instead of getTeamNumber if you
            // want to store a team number in this file.
            team = project.frc.getTeamNumber()
            debug = project.frc.getDebugOrDefault(false)

            artifacts {
                // First part is artifact name, 2nd is artifact type
                // getTargetTypeClass is a shortcut to get the class type using a string

                frcJava(getArtifactTypeClass('FRCJavaArtifact')) {
                }

                // Static files artifact
                frcStaticFileDeploy(getArtifactTypeClass('FileTreeArtifact')) {
                    files = project.fileTree('src/main/deploy')
                    directory = '/home/lvuser/deploy'
                }
            }
        }
    }
}

def deployArtifact = deploy.targets.roborio.artifacts.frcJava

// Set to true to use debug for JNI.
wpi.java.debugJni = false

// Set this to true to enable desktop support.
def includeDesktopSupport = false

// Defining my dependencies. In this case, WPILib (+ friends), and vendor libraries.
// Also defines JUnit 5.
dependencies /* (5)! */ {
    implementation wpi.java.deps.wpilib()
    implementation wpi.java.vendor.java()

    roborioDebug wpi.java.deps.wpilibJniDebug(wpi.platforms.roborio)
    roborioDebug wpi.java.vendor.jniDebug(wpi.platforms.roborio)

    roborioRelease wpi.java.deps.wpilibJniRelease(wpi.platforms.roborio)
    roborioRelease wpi.java.vendor.jniRelease(wpi.platforms.roborio)

    nativeDebug wpi.java.deps.wpilibJniDebug(wpi.platforms.desktop)
    nativeDebug wpi.java.vendor.jniDebug(wpi.platforms.desktop)
    simulationDebug wpi.sim.enableDebug()

    nativeRelease wpi.java.deps.wpilibJniRelease(wpi.platforms.desktop)
    nativeRelease wpi.java.vendor.jniRelease(wpi.platforms.desktop)
    simulationRelease wpi.sim.enableRelease()
}

test {
    useJUnitPlatform()
    systemProperty 'junit.jupiter.extensions.autodetection.enabled', 'true'
}

// Simulation configuration (e.g. environment variables).
wpi.sim.addGui().defaultEnabled = true
wpi.sim.addDriverstation()

// Setting up my Jar File. In this case, adding all libraries into the main jar ('fat jar')
// in order to make them all available at runtime. Also adding the manifest so WPILib
// knows where to look for our Robot Class.
jar {
    from { configurations.runtimeClasspath.collect { it.isDirectory() ? it : zipTree(it) } }
    from sourceSets.main.allSource
    manifest edu.wpi.first.gradlerio.GradleRIOPlugin.javaManifest(ROBOT_MAIN_CLASS)
    duplicatesStrategy = DuplicatesStrategy.INCLUDE
}

// Configure jar and deploy tasks
deployArtifact.jarTask = jar
wpi.java.configureExecutableTasks(jar)
wpi.java.configureTestTasks(test)

// Configure string concat to always inline compile
tasks.withType(JavaCompile) {
    options.compilerArgs.add '-XDstringConcat=inline'
}
```

1.  This block, aptly named `plugins`, lists some [Gradle Plugins](https://docs.gradle.org/current/userguide/plugins.html) that the robot code project uses.
2.  This line adds the [GradleRIO plugin](https://github.com/wpilibsuite/GradleRIO), which is used to simplify the build script.
3.  This section can contain settings and options that are part of Java. Right now, it is only being used to set the source (input) and target (output) compatibility to support Java 17.
4.  This specifies the main class of our robot code. Please don't ever change this, as doing so will cause build failures.
5.  This is typically where a Gradle project would list all of its libraries that it uses. We don't do it this way because of [[WPILib]]'s VendorDeps system, but we could add things here if we wanted to.

[^1]: It is a version of the Java programming language with some added features. They look very different though, and the experience of writing them is also different. To learn more about it, check out the [official groovy website](https://groovy-lang.org/) and [documentation](https://groovy-lang.org/documentation.html).

### gradlew, gradlew.bat

These are executable text files written in bash and batch for use on Linux/MacOS and Windows systems, respectively. We don't need to use these when we build our robot code projects because [[WPILib]]'s [[VSCode]] extension does it for us when you ask it to Build your robot code.

### settings.gradle

This is another file written in Groovy that allows you to configure project settings. You shouldn't ever need to use it.

### gradle/wrapper

This folder contains the jar file for Gradle--the actual code that the `gradlew` and `gradlew.bat` runs. There shouldn't ever be a need to modify these manually.