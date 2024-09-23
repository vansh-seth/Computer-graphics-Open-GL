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


The **Midpoint Ellipse Drawing Algorithm** is used to draw an ellipse using a raster graphics approach. The main idea behind this algorithm is to determine the next pixel position based on the midpoint between two possible candidates. It avoids floating-point calculations by using incremental integer decision parameters, making it computationally efficient.

### Steps of the Algorithm:

An ellipse is defined by the equation:

\[
\frac{x^2}{a^2} + \frac{y^2}{b^2} = 1
\]

Where:
- \(a\) is the semi-major axis (horizontal radius)
- \(b\) is the semi-minor axis (vertical radius)

The ellipse is symmetric, so it's enough to compute points in one quadrant and then mirror them into the other quadrants.

### 1. **Initial Setup**:
   - Set the initial point \((x_0, y_0)\) to \((0, b)\).
   - Decision parameter \(P_1\) for the first region is initialized to:
   
   \[
   P_1 = b^2 - a^2 \cdot b + \frac{1}{4}a^2
   \]
   
   - Draw the first point \((x_0, y_0)\) on the ellipse.

### 2. **Region 1 (where the slope of the curve is greater than or equal to -1)**:
   - Move horizontally to the right and calculate the new decision parameter to determine whether the next pixel should be above or below the current pixel.
   - If \(P_1 < 0\), the midpoint is inside the ellipse, so the next pixel is \((x+1, y)\).
   - If \(P_1 \geq 0\), the midpoint is outside the ellipse, so the next pixel is \((x+1, y-1)\).
   - Update the decision parameter based on the position of the next pixel.

   Continue this process until the boundary condition \(2b^2x \geq 2a^2y\) is met.

### 3. **Region 2 (where the slope of the curve is less than -1)**:
   - In this region, move vertically downward, calculating the new decision parameter to determine the next pixel's position.
   - The decision parameter \(P_2\) for Region 2 is initialized as:
   
   \[
   P_2 = b^2 \cdot (x+0.5)^2 + a^2 \cdot (y-1)^2 - a^2 \cdot b^2
   \]
   
   - If \(P_2 > 0\), the next pixel is \((x, y-1)\).
   - If \(P_2 \leq 0\), the next pixel is \((x+1, y-1)\).

   Continue the process until the entire ellipse is drawn.

### 4. **Symmetry**:
   - The algorithm uses symmetry to plot all four quadrants of the ellipse. After determining the pixel in the first quadrant, reflect it across the axes to fill the other quadrants.

### Advantages:
- The algorithm uses only integer addition, subtraction, and comparison, making it fast.
- It avoids floating-point calculations and divisions, optimizing performance for raster graphics.

### Example:
Let’s say you want to draw an ellipse with semi-major axis \(a = 10\) and semi-minor axis \(b = 5\). The algorithm would start by placing a point at \((0, 5)\) and then iteratively place points to form the ellipse shape, using the decision parameters to choose between potential points based on the midpoint criteria.
