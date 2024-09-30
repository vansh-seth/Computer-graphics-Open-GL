# Nicholl-Lee-Nicholl (NLN) Line Clipping Algorithm with OpenGL

## Overview
The **Nicholl-Lee-Nicholl (NLN) Line Clipping Algorithm** is a computational geometry algorithm used to clip line segments against a rectangular window. It efficiently handles lines by reducing unnecessary comparisons, making it faster than traditional algorithms like Cohen-Sutherland for certain cases. This repository contains an implementation of the NLN line clipping algorithm using OpenGL and GLUT to visualize the clipping process.

In this project:
- Blue lines represent the original un-clipped lines.
- Green lines represent the line segments after clipping within the defined rectangular region.
- The red rectangle is the clipping window.

## Algorithm Steps
The Nicholl-Lee-Nicholl algorithm operates on the following principles:

1. **Compute Outcodes**: 
   - An outcode is calculated for each endpoint of the line segment. The outcode represents the position of the point relative to the rectangular clipping window (left, right, top, bottom).
   
2. **Trivial Acceptance**:
   - If both endpoints of a line segment have an outcode of 0, the line lies completely within the window, and no clipping is necessary.

3. **Trivial Rejection**:
   - If both endpoints have a common non-zero outcode (both are outside on the same side of the window), the line lies entirely outside the clipping window, and the line can be rejected.

4. **Clipping**:
   - If the line cannot be trivially accepted or rejected, it is clipped against the window edges one by one. The algorithm calculates the intersection points using parametric equations and replaces the outside endpoint with the new clipped point.

5. **Repeat**:
   - This process is repeated until the line is either fully accepted or rejected.

## How to Run

### Requirements
You will need to install:
- OpenGL
- GLUT library

### Compilation and Execution

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/nln-line-clipping.git
   cd nln-line-clipping
   ```

2. Compile the program using `g++`:
   ```bash
   g++ -o nln_clipping nln_clipping.cpp -lGL -lGLU -lglut
   ```

3. Run the executable:
   ```bash
   ./nln_clipping
   ```

### Expected Output
- The program will open a 500x500 window.
- A red rectangle represents the clipping window.
- Blue lines represent the original lines.
- Green lines represent the clipped parts of those lines inside the rectangle.

## Code Structure

- `computeOutcode(x, y)`: Computes the outcode of a point relative to the clipping window.
- `NLN_LineClipping(x1, y1, x2, y2)`: Clips the line segment `(x1, y1)` to `(x2, y2)` using the NLN algorithm and draws the clipped line if necessary.
- `drawClippingWindow()`: Renders the rectangular clipping window.
- `display()`: Handles the OpenGL rendering of the original and clipped lines.

## Conclusion
The Nicholl-Lee-Nicholl line clipping algorithm is a more efficient alternative to other clipping algorithms for rectangular windows. By reducing unnecessary checks and handling multiple cases simultaneously, it provides a fast solution for clipping lines in computer graphics. This OpenGL-based implementation offers a visual demonstration of how lines are clipped against a rectangular window using this algorithm.
