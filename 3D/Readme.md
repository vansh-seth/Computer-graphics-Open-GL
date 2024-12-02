# 3D Translation and Scaling

## Overview

This project demonstrates fundamental operations in 3D computer graphics: **Translation** and **Scaling**. These transformations are crucial in manipulating objects within a 3D space, allowing changes in position and size while preserving shape and orientation. 

The project includes:

- Implementation of translation and scaling algorithms.
- Visualization of the transformations applied to 3D objects.
- Analysis of the effects of transformations on object coordinates.

## Algorithms

### 1. **3D Translation**

Translation in 3D involves moving an object from one location to another without altering its size, shape, or orientation.

#### Mathematical Representation:
Given a point \(P(x, y, z)\) and a translation vector \(T(tx, ty, tz)\), the new point \(P'(x', y', z')\) after translation is:

\[
x' = x + tx
\]
\[
y' = y + ty
\]
\[
z' = z + tz
\]

#### Steps:
1. Define the 3D object coordinates.
2. Specify the translation vector.
3. Add the respective translation values to each coordinate of the object.
4. Output the new coordinates.

---

### 2. **3D Scaling**

Scaling alters the size of an object in the 3D space. Uniform scaling changes the size uniformly across all axes, while non-uniform scaling allows different scaling factors for each axis.

#### Mathematical Representation:
Given a point \(P(x, y, z)\) and scaling factors \(S(sx, sy, sz)\), the new point \(P'(x', y', z')\) after scaling is:

\[
x' = x \cdot sx
\]
\[
y' = y \cdot sy
\]
\[
z' = z \cdot sz
\]

#### Steps:
1. Define the 3D object coordinates.
2. Specify the scaling factors for each axis.
3. Multiply each coordinate of the object by its corresponding scaling factor.
4. Output the new coordinates.

---

## Implementation

### Tools and Libraries
- **Programming Language**: Python (or any other language of your choice).
- **Visualization**: Matplotlib (for Python) or Three.js (for web-based visualization).

### Example Usage
```python
# Python example for translation
object_points = [(1, 2, 3), (4, 5, 6), (7, 8, 9)]
translation_vector = (3, -2, 5)

translated_points = translate_3d(object_points, translation_vector)
print(translated_points)
```

## Conclusion

This project highlights the importance of 3D transformations in graphics and simulations. By understanding and implementing these fundamental operations, users can control object positioning and scaling, forming a basis for more complex transformations like rotations and reflections. 

These concepts are essential in fields like computer graphics, game development, virtual reality, and simulations.

---

### Future Scope
- Extend the project to include **3D Rotation** and **Shearing**.
- Integrate with a graphical interface for interactive transformations.
- Implement transformation pipelines for rendering scenes.

### **README.md**

---

## **3D Rotation Overview**

3D rotation is a fundamental operation in computer graphics and 3D modeling, used to manipulate objects by changing their orientation in 3D space. The rotation occurs about one of the three principal axes: X, Y, or Z. It can also be performed around an arbitrary axis.

Rotations are represented using homogeneous transformation matrices, enabling a compact and efficient way to apply transformations.

---

## **Algorithm Steps**

### **Input**:
- 3D object coordinates.
- Rotation angle (\( \theta \)).
- Axis of rotation (X, Y, or Z).

### **Steps**:

1. **Initialize Object Coordinates**:  
   Represent the object as a set of 3D points.

2. **Choose Rotation Axis**:  
   Decide whether to rotate about the X, Y, or Z axis. For an arbitrary axis, normalize the axis vector.

3. **Construct the Rotation Matrix**:
   - **X-axis**:
     \[
     R_x = \begin{bmatrix}
     1 & 0 & 0 & 0 \\
     0 & \cos\theta & -\sin\theta & 0 \\
     0 & \sin\theta & \cos\theta & 0 \\
     0 & 0 & 0 & 1
     \end{bmatrix}
     \]
   - **Y-axis**:
     \[
     R_y = \begin{bmatrix}
     \cos\theta & 0 & \sin\theta & 0 \\
     0 & 1 & 0 & 0 \\
     -\sin\theta & 0 & \cos\theta & 0 \\
     0 & 0 & 0 & 1
     \end{bmatrix}
     \]
   - **Z-axis**:
     \[
     R_z = \begin{bmatrix}
     \cos\theta & -\sin\theta & 0 & 0 \\
     \sin\theta & \cos\theta & 0 & 0 \\
     0 & 0 & 1 & 0 \\
     0 & 0 & 0 & 1
     \end{bmatrix}
     \]

4. **Apply Transformation**:  
   Multiply the object's coordinate matrix by the rotation matrix.

5. **Update Object**:  
   Save the transformed coordinates to update the object's orientation.

6. **Render Object**:  
   Visualize the rotated object.

---

## **Conclusion**

3D rotation is a key transformation in computer graphics, enabling realistic visualization and manipulation of objects in space. Mastery of rotation matrices allows developers to build dynamic and interactive 3D applications efficiently.
