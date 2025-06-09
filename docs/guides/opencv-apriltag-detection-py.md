# Detecting apriltags with OpenCV and Python

!!! warning "This guide isn't finished yet!"

    It has all the setup instructions, but aside from that has nothing written yet.

This guide will show you how to use [[Python]] and [[OpenCV]] to detect [[Apriltag|Apriltags]].

## Image sources

You can detect apriltags in any type of image, or use a camera. For this guide I'll use an image from the University of Michigan that includes several apriltags of the 36H11 family.

![](https://april.eecs.umich.edu/media/apriltag/apriltagrobots_overlay.jpg)

## Instructions

1. Setup environment & install OpenCV

    This step will be different depending on what operating system you are on, but all systems generally follow this pattern:

    1. Ensure Python is installed
    2. Install a text editor or [[IDE]]
    3. Install opencv and the apriltag library

    === "Linux"

        Linux is the easiest operating system to use for this guide, so if you already have it installed that is perfect.

        Python should be installed by default on most Linux distributions. You can ensure it is installed by typing `python3` into your terminal. If it fails and you are using debian/ubuntu-based distros, you can use this command to install Python: `sudo apt install python3`. If you are using some other distribution of Linux then you should see if there is a `python` or `python3` package available to be installed.

        If you don't know how to use vim, [[VSCodium]] is a good second choice for an editor. You can install it via snap with this command: `snap install codium --classic`, or by manually installing the `.deb` (or `.rpm`, `.AppImage`, etc.) from [the GitHub releases page](https://github.com/VSCodium/vscodium/releases).

        The apriltag project requires cmake to be installed. You can install it by running `sudo apt install cmake` on Ubuntu/Debian-based distributions.

        The last thing you will need is to install OpenCV and the apriltag library. You can do this by running `pip3 install opencv-python apriltag` in your terminal.

    === "Windows"

        Download python from <https://www.python.org/downloads/windows/>, and then install it. 

        If you are on a team laptop, [[VSCode]] should be installed already and you shouldn't need to install an IDE. If this is not the case, then you should install WPILib to get the full suite of FRC software (including WPILib VSCode). 

        To install the cv2 and apriltag packages on Windows, you can refer to [this guide](https://packaging.python.org/en/latest/tutorials/installing-packages/) which explains how to explain python packages. The package names are `opencv-python` and `apriltag`.

    === "Mac OS"

        You can download Python from here: <https://www.python.org/downloads/macos/>.

        For an IDE, [[VSCode]] is an option. Otherwise, you can download the latest `.dmg` release of VSCodium: <https://github.com/VSCodium/vscodium/releases>.

        To install the packages on Mac, just run `pip3 install opencv-python apriltag`.

    === "Chromebook"

        You will likely have a hard time trying to follow along this guide using a chromebook, especially if it is a school-issued one. The development environment is very slow and takes a long time to run your code. If possible, switch to a different device.

        A [Jupyter Lite Notebook](https://jupyter.org/try-jupyter/lab/) might work in the future. Try creating a new notebook with Pyodide and then running this script to install everything you need:

        ```python title="JupyterLite Setup Script" hl_lines="4"
        import micropip

        await micropip.install("opencv-python")
        await micropip.install("apriltag") # This does not work
        ```

        As of the writing of this guide, the [apriltag package](https://pypi.org/project/apriltag/) cannot be installed within Pyodide.

2. Setup project structure

    After installing everything that is required, create a new folder. I suggest somewhere in the `Documents` folder, but it is up to you. Create a file in your new project folder called `main.py`. This is where all of our [[Python]] code will go.

    If you are going to use the image from the University of Michigan, you should also download it to the same folder and call it `image.jpg`.

3. Setup the IDE

    Open the new `main.py` file in your text editor or IDE. Put this text in there:

    ```python title="main.py"
    print("hello world")
    ```

    Now, try to run it.

    === "VSCode / VSCodium"

        On VSCode or VSCodium you can open a terminal window by pressing ++ctrl+j++. Then, type `python3 main.py` to run your program.
    
    === "Vim"

        In Vim, you can type `<CMD>terminal<CR>` (this is the same as ++colon+t+e+r+m+i+n+a+l+enter++) to open a terminal window. 

        It will probably not go where you want it to, so you can type `<C-w>r` to flip the windows. (This means ++ctrl+w++, then ++r++)

    !!! tip "Don't retype everything every time"

        If you are using the terminal to run your script, you can use the up arrow ( ++up++ ) to skip all the typing after you've run your program once.