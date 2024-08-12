Here's the revised version of the `README.md` with the algorithm steps added and the "Compilation and Execution" section removed:

---

# Bresenham Line Algorithm with OpenGL

This project demonstrates the Bresenham line drawing algorithm using OpenGL and GLUT. It draws a line between two points on a 2D plane based on user input.

## Overview

The Bresenham line algorithm is an efficient way to determine which points in a grid-based system should be plotted to form a straight line between two given points. This project uses OpenGL to visualize the algorithm by drawing the line in a graphical window.

## Requirements

- OpenGL
- GLUT (OpenGL Utility Toolkit)
- A C++ compiler (e.g., g++, clang++)

## Algorithm Steps

1. **Calculate the Differences**:
   - Compute the differences `dx = x2 - x1` and `dy = y2 - y1`.

2. **Determine Step Directions**:
   - Determine the step directions `sx` and `sy` based on the signs of `dx` and `dy`.

3. **Initialize Decision Parameter**:
   - Set the initial decision parameter `p = 2*dy - dx` if `dx > dy`, or `p = 2*dx - dy` if `dy > dx`.

4. **Iterate Over the Line**:
   - For each point from the start to the end:
     - Plot the current point.
     - Update the decision parameter `p`:
       - If `p` is less than 0, move horizontally or vertically and update `p` based on the major axis.
       - If `p` is greater than or equal to 0, move diagonally and update `p` accordingly.

5. **Repeat**:
   - Continue the process until the endpoint `(x2, y2)` is reached.

## How It Works

1. **Initialization**:
   - `init()` sets up the OpenGL environment, including the clear color and orthographic projection.

2. **Bresenham Line Algorithm**:
   - `bresenham_line(int x1, int y1, int x2, int y2)` computes the points along a straight line between `(x1, y1)` and `(x2, y2)` using integer arithmetic for efficiency.
   - The algorithm calculates the difference in x (`dx`) and y (`dy`), as well as the step direction (`sx` and `sy`). It then iterates through the points to determine which ones should be drawn.

3. **Rendering**:
   - `bresenham_spoke()` clears the color buffer and draws the line using `bresenham_line()`. The line is drawn in blue with a point size of 2.

4. **Launcher**:
   - `launcher(int argc, char** argv)` initializes GLUT, sets the display mode, creates a window, and starts the main loop.

## Example

To draw a line from `(10, 20)` to `(100, 200)`, input:
```
10 20 100 200
```

A window will open displaying the line based on the provided coordinates.

## Conclusion

The Bresenham line algorithm is a fundamental technique in computer graphics for drawing straight lines on a raster display. This project demonstrates the algorithm's practical implementation using OpenGL and GLUT, offering a visual representation of how the algorithm works.

By running the provided code, users can interactively input coordinates and see the result of the Bresenham line drawing algorithm in action. This project not only illustrates the efficiency of Bresenham's approach but also serves as a starting point for further exploration into computer graphics and algorithm optimization.

---

This version includes the steps of the Bresenham line algorithm while removing the compilation and execution details as requested.
