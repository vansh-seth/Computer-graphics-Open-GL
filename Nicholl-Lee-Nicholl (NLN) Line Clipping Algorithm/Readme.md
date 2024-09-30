# Nicholl-Lee-Nicholl (NLN) Line Clipping Algorithm using OpenGL

## Overview
The **Nicholl-Lee-Nicholl (NLN) Line Clipping Algorithm** is an efficient algorithm used to clip lines against a rectangular window. Compared to other line clipping algorithms like Cohen-Sutherland, NLN offers a significant performance boost, particularly for lines that are mostly inside the clipping region, as it minimizes the number of intersection calculations required.

In this project, we implement the NLN line clipping algorithm using **OpenGL** and **GLUT**. The algorithm clips lines that are drawn outside a rectangular clipping window and only displays the visible parts of the lines within the clipping area.

## Algorithm Steps
The Nicholl-Lee-Nicholl line clipping algorithm works based on a set of simple but effective rules:

1. **Outcode Computation:**
   - Each point is assigned a 4-bit outcode that determines its position relative to the clipping rectangle.
   - There are four possible boundaries: Left, Right, Bottom, and Top. Each boundary is assigned a bit.
   
2. **Trivial Acceptance:**
   - If both endpoints of a line have an outcode of `0000`, the line is completely inside the clipping region and is drawn as-is.

3. **Trivial Rejection:**
   - If both endpoints have a non-zero outcode and share the same region outside the clipping window, the line is trivially rejected (no intersection with the window).
   
4. **Clipping Against Edges:**
   - If the line cannot be trivially accepted or rejected, it is clipped against the corresponding edge (top, bottom, left, or right) using interpolation.

5. **Iterative Clipping:**
   - The algorithm repeatedly clips the line against the clipping window boundaries until the line is either accepted (completely inside) or rejected (completely outside).

### Steps in the Code:
- `computeOutcode`: Computes the outcode for a given point (x, y) to determine its position relative to the clipping rectangle.
- `NLN_LineClipping`: Implements the NLN line clipping algorithm to process lines and clip them within the rectangular clipping window.
- `drawClippingWindow`: Draws the red rectangular clipping window.
- `display`: Sets up the scene, draws original lines (blue), and their clipped portions (green).

## How to Compile and Run
To run the Nicholl-Lee-Nicholl line clipping algorithm, follow these steps:

### Requirements
- OpenGL
- GLUT

### Compilation
You can compile the C++ code using the following command (make sure OpenGL and GLUT are properly installed):

```bash
g++ -o nln_clipping nln_clipping.cpp -lGL -lGLU -lglut

