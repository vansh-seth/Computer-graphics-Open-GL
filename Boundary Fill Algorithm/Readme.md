# Boundary Fill Algorithm with OpenGL
## Overview

This project implements the Boundary Fill Algorithm using OpenGL for simple 2D graphics rendering. The Boundary Fill Algorithm is used to fill a contiguous area with a specified color, bounded by a particular edge or boundary color. The application draws a triangle on the screen and allows the user to fill the triangle with a chosen color by clicking inside it.

## Algorithm Steps

1. **Initialization:**
   - Set up the OpenGL environment with a white background.
   - Configure the projection matrix to use orthographic projection.

2. **Draw the Boundary:**
   - A triangle is drawn using OpenGL's `GL_LINE_LOOP`. The vertices of the triangle are defined as:
     - (150, 100)
     - (300, 300)
     - (450, 100)

3. **Handle Mouse Clicks:**
   - On a mouse click (left button), capture the mouse position and invert the y-coordinate (to match the OpenGL coordinate system).
   - Define the boundary color (`bCol`) and fill color (`color`).

4. **Boundary Fill Algorithm:**
   - The `bound_it` function performs the boundary fill operation recursively:
     - Check the color of the current pixel.
     - If the pixel color is not the boundary color and not the fill color, change it to the fill color and recursively apply the fill to adjacent pixels.
     - The recursive calls expand the fill region to neighboring pixels in all four directions (right, left, up, down).

5. **Display Function:**
   - The `world` function sets up the initial scene by clearing the color buffer and drawing the triangle.

6. **Main Loop:**
   - Initialize the GLUT library, set up the display and mouse callback functions, and enter the GLUT event processing loop.

## Conclusion

This implementation demonstrates a basic usage of the Boundary Fill Algorithm for filling shapes within a graphical window using OpenGL. The code showcases how to handle mouse events for interactive graphical applications and how to apply recursive algorithms for region filling. The example provided fills a triangle with a specified color when clicked, showcasing the functionality of boundary-based region filling.
