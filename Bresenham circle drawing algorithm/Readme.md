# OpenGL Circle Drawing Example

This is a simple OpenGL program written in C++ that demonstrates how to draw a circle using the OpenGL Utility Toolkit (GLUT).

## Description

The program sets up a 2D coordinate system and draws a circle at the center of the screen with a specified radius. The circle is rendered using `GL_LINE_LOOP`, which connects a series of points calculated using trigonometric functions.

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

## Code Explanation

- **drawCircle(float xc, float yc, float radius):** This function draws a circle centered at `(xc, yc)` with the specified `radius`. It uses the parametric equation of a circle and OpenGL's `GL_LINE_LOOP` to render it.

- **display():** This is the display callback function. It clears the window, resets transformations, sets the drawing color, and calls `drawCircle` to render the circle.

- **init():** This function sets up the OpenGL environment, including the background color, drawing color, point size, and coordinate system using an orthographic projection.

- **main():** The entry point of the program. It initializes GLUT, creates the window, and enters the main event loop.

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

## License

This project is open-source and available under the MIT License. Feel free to modify and distribute as needed.

```

This `README.md` file provides a clear explanation of the program, its functionality, how to compile and run it, and other relevant details.
