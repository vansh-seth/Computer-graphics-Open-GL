### README.md

# 2D Transformations and Rotation in Computer Graphics (OpenGL)

This project demonstrates basic **2D transformations** (translation, scaling, rotation) and **2D rotation** (clockwise and anticlockwise) using OpenGL in C++. The program features interactive controls for applying these transformations to a triangle rendered on the screen.

---

## Features

### 1. **2D Transformations**
- **Translation**: Move the triangle up, down, left, or right.
- **Scaling**: Increase or decrease the size of the triangle.
- **Rotation**: Rotate the triangle clockwise or anticlockwise.

### 2. **2D Rotation Only**
- Separate implementation focusing solely on clockwise and anticlockwise rotations.

---

## Controls

### **For 2D Transformations**
| Key | Action                           |
|-----|----------------------------------|
| `W` | Move the triangle up             |
| `S` | Move the triangle down           |
| `A` | Move the triangle left           |
| `D` | Move the triangle right          |
| `R` | Rotate the triangle clockwise    |
| `E` | Rotate the triangle anticlockwise|
| `+` | Increase the size of the triangle|
| `-` | Decrease the size of the triangle|
| `ESC` | Exit the program               |

### **For 2D Rotation**
| Key | Action                           |
|-----|----------------------------------|
| `R` | Rotate the triangle clockwise    |
| `E` | Rotate the triangle anticlockwise|
| `ESC` | Exit the program               |

---

## Prerequisites

- Install OpenGL and GLUT libraries on your system.

### Installation on Ubuntu
```bash
sudo apt-get update
sudo apt-get install freeglut3-dev
```

### Installation on Windows
- Download and set up the [OpenGL and GLUT](https://www.opengl.org/resources/libraries/glut/) libraries in your compiler environment (e.g., Code::Blocks, Visual Studio).

---

## Compilation and Execution

### For Linux/Mac
1. Save the desired code (`transformations.cpp` or `rotation.cpp`) into a file.
2. Compile using the following command:
   ```bash
   g++ filename.cpp -lGL -lGLU -lglut -o output_name
   ```
3. Run the program:
   ```bash
   ./output_name
   ```

### For Windows
1. Save the code in your IDE.
2. Link the OpenGL libraries (e.g., `glut32.lib`, `opengl32.lib`) in your project settings.
3. Build and run the program.

---

## Screenshots

### Initial Triangle
![Initial Triangle](https://via.placeholder.com/400x300.png?text=Initial+Triangle)

### After Rotation
![Rotated Triangle](https://via.placeholder.com/400x300.png?text=Rotated+Triangle)

---

## How It Works

### **Transformations**
1. **Translation**: Adds the translation factor (`translateX`, `translateY`) to the vertex coordinates.
2. **Scaling**: Multiplies the vertex coordinates by scaling factors (`scaleX`, `scaleY`).
3. **Rotation**: Applies the 2D rotation formula:
   \[
   x' = x \cos(\theta) - y \sin(\theta)
   \]
   \[
   y' = x \sin(\theta) + y \cos(\theta)
   \]

### **Rotation Only**
- Implements just the rotation logic with an adjustable angle, updated interactively through keyboard inputs.

---

## License

This project is open-source and available under the MIT License.

