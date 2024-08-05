# Basics of OpenGL: Drawing Shapes

This document provides an introduction to the basics of drawing shapes in OpenGL. It includes theoretical explanations of how to draw a line, rectangle, and pentagon, as well as the differences between `glut.h` and `graphics.h`, and the differences between `glClear()` and `glFlush()`.

## Drawing Shapes in OpenGL

OpenGL (Open Graphics Library) is a cross-language, cross-platform API for rendering 2D and 3D vector graphics. It provides a set of commands for rendering basic geometric shapes, among other things. Here’s a theoretical overview of how to draw some basic shapes in OpenGL:

### Drawing a Line

In OpenGL, a line is defined by two points. The `glBegin(GL_LINES)` function is used to specify that we are going to draw lines, and `glVertex2f(x, y)` specifies the coordinates of each endpoint. OpenGL will draw a straight line between these points.

### Drawing a Rectangle

A rectangle in OpenGL can be drawn using four points (vertices). The `glBegin(GL_QUADS)` function is used to specify that we are going to draw quadrilaterals. Each pair of `glVertex2f(x, y)` calls defines a corner of the rectangle. OpenGL will connect these points in the order they are specified to form the rectangle.

### Drawing a Pentagon

A pentagon is a five-sided polygon. To draw a pentagon, you can use the `glBegin(GL_POLYGON)` function and specify five vertices using `glVertex2f(x, y)`. The vertices should be calculated based on the desired size and position of the pentagon, often using trigonometric functions to ensure they are evenly spaced around a circle.

## Differences Between `glut.h` and `graphics.h`

### `glut.h`

- **Platform**: Part of the OpenGL Utility Toolkit, designed for creating OpenGL programs that are portable across different platforms (Windows, Linux, macOS).
- **Features**: Provides functions for window management, handling input devices (keyboard, mouse), and other utilities that simplify the creation of OpenGL applications.
- **Usage**: Widely used in modern OpenGL applications for its portability and ease of use. Suitable for educational purposes, prototyping, and simple applications.

### `graphics.h`

- **Platform**: Part of the Borland Graphics Interface (BGI) library, which was used primarily in DOS-based systems.
- **Features**: Offers basic functions for drawing shapes, handling text, and performing simple image manipulations. Limited to simple 2D graphics and lacks the advanced capabilities of modern graphics libraries.
- **Usage**: Largely obsolete and replaced by more advanced and platform-independent libraries like OpenGL, SDL, and others. Mostly found in legacy code and educational resources for learning basic graphics concepts.

## Differences Between `glClear()` and `glFlush()`

### `glClear()`

- **Function**: Clears buffers to preset values. Typically used to clear the color buffer, depth buffer, or stencil buffer at the beginning of each frame to prepare for rendering the next frame.
- **Usage**: Essential for setting up a clean slate for drawing the next frame. Often called at the start of the display function to clear the screen.
- **Syntax**: `glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);`
- **Effect**: Ensures that the contents of the specified buffers are reset to their default values (e.g., the color buffer is cleared to the background color).

### `glFlush()`

- **Function**: Forces the execution of OpenGL commands in finite time. Ensures that all previously issued OpenGL commands are executed as quickly as possible.
- **Usage**: Useful in environments where OpenGL commands are buffered (e.g., networked applications) and you want to ensure that all commands have been processed. Often used at the end of the rendering function to ensure that all drawing commands have been completed.
- **Syntax**: `glFlush();`
- **Effect**: Guarantees that all previous OpenGL commands will be completed in a finite amount of time. It does not wait for the commands to finish, it just ensures they will be processed.

