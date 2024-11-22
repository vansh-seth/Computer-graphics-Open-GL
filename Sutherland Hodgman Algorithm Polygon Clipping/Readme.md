# Sutherland Hodgman Algorithm Polygon Clipping

This project implements a polygon clipping tool using OpenGL in C++. The application allows users to draw a polygon interactively, define a rectangular clipping window, and clip the polygon using the Sutherland-Hodgman Polygon Clipping algorithm.

---

## Features
- **Interactive Polygon Drawing**: Draw a polygon by clicking points on the window.
- **Define Clipping Window**: Use the mouse to drag and set a rectangular clipping region.
- **Polygon Clipping**: Clip the drawn polygon to the defined rectangle using the Sutherland-Hodgman algorithm.
- **Keyboard Controls**:
  - Press `d` to finalize the polygon drawing.
  - Press `c` to apply the clipping algorithm and display the result.

---

## Prerequisites
- **OpenGL**: Make sure you have OpenGL installed on your system.
- **GLUT Library**: The code uses GLUT for window management and event handling.

---

## How to Build and Run

### Linux/MacOS
1. Install OpenGL and GLUT:
   ```bash
   sudo apt-get install freeglut3 freeglut3-dev
   ```
   For MacOS, use:
   ```bash
   brew install freeglut
   ```

2. Compile the program:
   ```bash
   g++ -o polygon_clipping polygon_clipping.cpp -lGL -lGLU -lglut
   ```

3. Run the program:
   ```bash
   ./polygon_clipping
   ```

### Windows
1. Install OpenGL and GLUT libraries (commonly included in development tools such as Visual Studio or MinGW).
2. Compile using your preferred IDE or command-line compiler:
   ```bash
   g++ -o polygon_clipping polygon_clipping.cpp -lopengl32 -lglu32 -lfreeglut
   ```
3. Run the generated executable.

---

## Usage
1. **Draw a Polygon**:
   - Use the left mouse button to add vertices to the polygon.
   - Press `d` to finalize the drawing.

2. **Define a Clipping Window**:
   - Click and drag with the mouse to set the clipping rectangle's bounds.

3. **Clip the Polygon**:
   - Press `c` to clip the polygon to the defined window.

4. **View Results**:
   - The clipped polygon is displayed in red inside the clipping rectangle.

---

## Code Structure
- **Initialization**:
  - `init()`: Sets up the OpenGL environment.
- **Polygon and Window Drawing**:
  - `mouse()`: Handles vertex placement for the polygon.
  - `drag_start()` and `drag_end()`: Used to define the rectangular clipping window.
- **Clipping Algorithm**:
  - `SHPC()`: Implements the Sutherland-Hodgman Polygon Clipping algorithm.
- **Rendering**:
  - `drawPolygon()`: Draws the input polygon.
  - `redraw()`: Displays the clipped polygon.

---

## Notes
- Ensure that all dependencies are installed and linked correctly during compilation.
- The program assumes a fixed 2D viewport size of 640x480.

---

## License
This project is licensed under the MIT License. Feel free to use, modify, and distribute the code.

---

## Acknowledgments
- Inspired by the Sutherland-Hodgman Polygon Clipping algorithm for 2D graphics.
- Built using OpenGL and GLUT for interactive rendering and event handling.
