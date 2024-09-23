# Cohen-Sutherland Line Clipping Algorithm

## Overview

This project implements the **Cohen-Sutherland Line Clipping Algorithm** using **OpenGL** in C++. The algorithm is used to clip lines to a rectangular clipping window. If a line is entirely outside the window, it is rejected, and if partially outside, it is clipped to fit within the boundaries. The graphical interface is created using the **GLUT** library, with user input for line coordinates.

### Features:
- Input two points to define a line.
- The line will be clipped according to the boundaries of a predefined rectangular window.
- Real-time display of the clipping process when the user presses the 'c' key.

## Algorithm Steps

1. **Initialization**:  
   Set up the OpenGL window and define the clipping boundaries for the rectangular window (`xmin, ymin, xmax, ymax`).
   
2. **Region Code Generation**:  
   For each endpoint of the line, compute the **region code** based on its position relative to the rectangular window. The region code determines whether the point is inside or outside the clipping boundary:
   - Bit 1: Left of the window
   - Bit 2: Right of the window
   - Bit 3: Below the window
   - Bit 4: Above the window

3. **Bitwise AND Operation**:  
   Compare the region codes of both points:
   - If both points share an outside region (bitwise AND != 0), the line is **entirely outside** and rejected.
   - If the bitwise OR operation results in zero, the line is **entirely inside** the window.

4. **Clipping**:  
   If the line is partially outside:
   - Determine the intersection of the line with the clipping window.
   - Clip the line to the boundary where it intersects.

5. **Recursion**:  
   The algorithm repeatedly checks and clips the line until it is either fully inside or rejected.

6. **User Interaction**:  
   The user presses the `c` key to start the clipping process. The program will then redraw the line after clipping or reject it.

## Usage

### Compilation
Ensure that you have the GLUT and OpenGL libraries installed. Compile the code using the following command:

```bash
g++ -o clipping clipping.cpp -lGL -lGLU -lglut
```

### Running
After compiling, run the program:

```bash
./clipping
```

Input the line coordinates when prompted:
```
Enter line co-ordinates: x1 y1 x2 y2
```

Press the `c` key to clip the line to the window. The window will display the original rectangle and the clipped line.

### Controls
- Press `c` to clip the line.
- The green rectangle represents the clipping window.
- The red line represents the input line and its final clipped version.

## Conclusion

This implementation demonstrates the Cohen-Sutherland Line Clipping Algorithm, efficiently clipping a line within a defined rectangular area. The algorithm uses bitwise operations to optimize the process of determining whether to clip, accept, or reject a line. It highlights the basic principles of line clipping in computer graphics and how region codes simplify handling different cases of line visibility. 

---

You can customize the document based on additional details or changes to the program.
