
# Flood Fill Algorithm

## Overview

The Flood Fill algorithm is used to determine the area connected to a given node in a multi-dimensional array. It is commonly employed in graphics applications, such as paint programs, where it fills a connected region with a specific color.

In this implementation, the Flood Fill algorithm is applied using OpenGL to fill a polygon with a selected color when the user clicks inside it.

## Algorithm Steps

1. **Initialization**:
    - Set up the OpenGL environment and define the window size and position.
    - Clear the window and draw a polygon on the screen.

2. **Mouse Interaction**:
    - Capture mouse click events to identify the starting point for the Flood Fill.
    - On a mouse click, read the color of the clicked pixel.

3. **Flood Fill Algorithm**:
    - Recursively check if the current pixel's color matches the target (initial) color.
    - If it matches, fill the pixel with the desired fill color.
    - Move to the neighboring pixels (up, down, left, right) and repeat the process.

4. **Rendering**:
    - The filled area is rendered in real-time as the algorithm progresses.

## Explanation

### Code Breakdown

- **`init()`**: This function initializes the OpenGL environment, setting up the background color and defining the 2D orthographic projection.
  
- **`flood_it(int x, int y, const float* fillColor, const float* ic)`**: This is the core function implementing the Flood Fill algorithm. It checks the current pixel's color and fills it if it matches the initial color, then recursively calls itself on neighboring pixels.

- **`mouse(int btn, int state, int x, int y)`**: Handles mouse click events. When the left mouse button is pressed, it triggers the Flood Fill starting from the clicked point.

- **`world()`**: This function draws the initial polygon on the screen, which will be filled using the Flood Fill algorithm.

- **`main()`**: The entry point of the program, setting up the GLUT environment and starting the main loop.

### How It Works

- When you click inside the polygon, the program captures the pixel's coordinates and color. It then starts the Flood Fill process, replacing the polygon's color with the selected fill color.
  
- The algorithm works recursively, ensuring that all connected pixels of the same color are filled, creating a visually pleasing fill effect within the polygon.

## Conclusion

This implementation of the Flood Fill algorithm using OpenGL in C++ demonstrates how a simple yet powerful algorithm can be used to fill connected regions in a graphical application. The recursive nature of the algorithm ensures that all areas within the specified region are filled, making it an essential tool in graphics programming.

By following the steps and explanations provided, you can understand how the Flood Fill algorithm operates and how it can be applied in different scenarios. This example provides a foundation for further exploration into more complex graphics algorithms and techniques.

--- 

You can use this `README.md` file to explain the code and its functionality to anyone who may come across your project.
