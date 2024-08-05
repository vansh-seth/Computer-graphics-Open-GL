
# DDA Line Algorithm in OpenGL

This repository contains an implementation of the DDA (Digital Differential Analyzer) Line Algorithm using OpenGL. The DDA algorithm is a simple and efficient way to draw a straight line between two points on a computer screen.

## Overview

The DDA Line Algorithm is a method used in computer graphics to draw a straight line between two points. It works by calculating intermediate points along the line at regular intervals using floating-point arithmetic. The algorithm increments one coordinate at a time, either x or y, depending on the slope of the line, and calculates the corresponding other coordinate using the line equation.

### Algorithm Steps

1. Calculate the differences `dx` and `dy` between the end points.
2. Determine the number of steps required to draw the line.
3. Calculate the increment values for x and y coordinates.
4. Initialize the starting point.
5. Incrementally calculate and plot the points along the line.

### Key Features

- Efficient and simple to implement.
- Works well for lines with gentle slopes.
- Uses floating-point arithmetic for precision.

## Implementation

### Prerequisites

To compile and run this example, you need to have OpenGL and GLUT installed. On most systems, you can install the necessary libraries using your package manager. For example, on Ubuntu:

```bash
sudo apt-get install freeglut3-dev
```

### Code Explanation

The following code demonstrates the implementation of the DDA Line Algorithm in OpenGL.

```c
#include <GL/glut.h>
#include <math.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

void setPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void DDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps;
    float xIncrement, yIncrement, x = x1, y = y1;

    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    xIncrement = dx / (float) steps;
    yIncrement = dy / (float) steps;

    setPixel(round(x), round(y));

    for (int k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        setPixel(round(x), round(y));
    }
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    DDA(100, 100, 700, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
```

### Explanation

1. **Initialization**:
   - `init()` sets up the display window with a white background and black drawing color.
   - `gluOrtho2D(0.0, 800.0, 0.0, 600.0)` sets the coordinate system.

2. **Set Pixel**:
   - `setPixel(int x, int y)` plots a point at the given coordinates.

3. **DDA Algorithm**:
   - `DDA(int x1, int y1, int x2, int y2)` calculates and plots the points along the line using the DDA algorithm.

4. **Display Function**:
   - `display()` clears the screen and calls the `DDA` function to draw a line from (100, 100) to (700, 500).

5. **Main Function**:
   - Sets up the GLUT environment and enters the main loop.

## Conclusion

The DDA Line Algorithm is a fundamental technique in computer graphics for drawing lines. This implementation in OpenGL demonstrates how to use the algorithm to plot points and render a line on the screen. By understanding and using the DDA algorithm, you can gain a deeper appreciation of the underlying principles of computer graphics.
