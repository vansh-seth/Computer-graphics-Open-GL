# Midpoint Ellipse Drawing Algorithm

This program demonstrates the Midpoint Ellipse Drawing Algorithm using OpenGL in C++. It allows the user to input the center coordinates of the ellipse and the lengths of its semi-major and semi-minor axes. The algorithm then plots the ellipse on the screen.

## Features

- User-defined center and axes for the ellipse.
- Implements the Midpoint Ellipse Drawing Algorithm to render the ellipse.
- Uses OpenGL and GLUT for rendering graphics.

## Prerequisites

To compile and run this program, you need to have the following:

- C++ compiler (e.g., g++)
- OpenGL and GLUT libraries installed on your system

## Installation

### On Linux

1. Install OpenGL and GLUT (if not already installed):
    ```bash
    sudo apt-get update
    sudo apt-get install freeglut3-dev
    ```

2. Save the provided code in a file named `ellipse.cpp`.

3. Compile the code using g++:
    ```bash
    g++ ellipse.cpp -o ellipse -lGL -lGLU -lglut
    ```
    

### On Windows

1. Install an IDE like Code::Blocks or Visual Studio that supports OpenGL.
2. Configure the IDE to use OpenGL and GLUT.
3. Copy the provided code into a new project.
4. Build and run the project from the IDE.

## Usage

1. Upon running the program, you will be prompted to enter the center coordinates of the ellipse:

    ```
    Enter Center Of Ellipse

    x = 
    y = 
    ```

2. Next, you will be prompted to enter the lengths of the semi-major and semi-minor axes:

    ```
    Enter a Semi Major Axis: 
    Enter a Semi Minor Axis: 
    ```

3. After entering the values, an ellipse based on the input will be displayed in a window.

## Code Explanation

- **ellipseMidPoint()**: This function implements the Midpoint Ellipse Drawing Algorithm. It calculates the points of the ellipse and uses the `setPixel()` function to plot them.
- **setPixel(GLint x, GLint y)**: This function sets a pixel at the specified `(x, y)` coordinates using OpenGL's `glVertex2i` function.
- **myinit()**: This function initializes the OpenGL environment, sets the background color, and defines the projection matrix.
- **display()**: This function clears the screen, sets the color and size of points, and calls `ellipseMidPoint()` to draw the ellipse.



