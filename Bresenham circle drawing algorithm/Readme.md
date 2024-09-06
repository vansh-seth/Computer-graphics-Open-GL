# OpenGL Circle Drawing Example
This is a simple OpenGL program written in C++ that demonstrates how to draw a circle using the OpenGL Utility Toolkit (GLUT).

## Overview

The program creates a window using GLUT and draws a circle at the center of the window using basic OpenGL functions. The circle is rendered using `GL_LINE_LOOP`, which connects a series of points on the circumference calculated using trigonometric functions. The program is designed to be a basic example of 2D graphics programming with OpenGL.

## Algorithm Steps

1. **Initialize the GLUT Library:**
   - Initialize the GLUT library with `glutInit`.
   - Set the display mode to single buffer and RGB color with `glutInitDisplayMode`.

2. **Set Up the Window:**
   - Define the window size and position using `glutInitWindowSize` and `glutInitWindowPosition`.
   - Create the window with `glutCreateWindow`.

3. **Initialize OpenGL State:**
   - Set the background color to black using `glClearColor`.
   - Set the drawing color to white using `glColor3f`.
   - Define the coordinate system with `gluOrtho2D`.

4. **Draw the Circle:**
   - Use the `drawCircle` function to calculate points on the circumference using the parametric equation of a circle.
   - Draw the circle using `glBegin(GL_LINE_LOOP)` and `glVertex2f`.

5. **Display the Circle:**
   - Clear the window with `glClear`.
   - Reset transformations with `glLoadIdentity`.
   - Set the color and call `drawCircle` to render the circle.

6. **Enter the Main Loop:**
   - Enter the GLUT event processing loop with `glutMainLoop`.

## Explanation

### Circle Drawing Logic

The circle is drawn using the parametric equation:

\[ x = r \cdot \cos(\theta) \]
\[ y = r \cdot \sin(\theta) \]

Where:
- \( r \) is the radius of the circle.
- \( \theta \) is the angle that varies from 0 to 360 degrees.

The program iterates through 360 degrees, calculating the corresponding x and y coordinates for each point on the circumference. These points are then connected using `GL_LINE_LOOP` to form the circle.

### OpenGL Setup

The `init` function configures the OpenGL environment:
- **Background Color:** Set to black (`glClearColor(0.0, 0.0, 0.0, 0.0)`).
- **Drawing Color:** Set to white (`glColor3f(1.0, 1.0, 1.0)`).
- **Projection:** The `gluOrtho2D` function sets up a 2D orthographic viewing region where the x and y coordinates range from -1 to 1.

## Conclusion

This OpenGL program serves as a fundamental example of how to set up a basic 2D graphics environment and render simple shapes like a circle. It demonstrates essential concepts such as initializing GLUT, setting up an orthographic projection, and using trigonometric functions to draw shapes. This example can be extended to include more complex shapes and interactive graphics.

## Prerequisites

To compile and run this program, you need to have the following libraries installed:

- OpenGL
- GLUT (OpenGL Utility Toolkit)
- GLU (OpenGL Utility Library)

On Linux, you can install these libraries using the following command:

```bash
sudo apt-get install freeglut3-dev
```

On Windows, you may need to download and configure these libraries manually or use an IDE like Visual Studio, which can handle these dependencies.

## How to Compile and Run

### On Linux

To compile the program, use the following command:

```bash
g++ -o OpenGLCircle main.cpp -lGL -lGLU -lglut -lm
```

Then run the program using:

```bash
./OpenGLCircle
```

### On Windows

If you're using Visual Studio:

1. Create a new empty project.
2. Add the source code (`main.cpp`) to the project.
3. Link the necessary OpenGL libraries (`opengl32.lib`, `glu32.lib`, `glut32.lib`).
4. Build and run the project.

## Output

When you run the program, a window will appear with a black background and a white circle drawn at the center.
