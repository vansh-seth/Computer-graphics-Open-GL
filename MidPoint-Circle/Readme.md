# Midpoint Circle Drawing Algorithm

The Midpoint Circle Drawing Algorithm is an efficient algorithm for rasterizing circles in computer graphics. It minimizes computational complexity and is widely used in graphics applications and systems.

## Overview

The Midpoint Circle Drawing Algorithm is used to draw a circle by determining which pixels to plot to best approximate the shape of the circle. By leveraging integer arithmetic, it avoids the complexity of floating-point operations and is computationally efficient. The algorithm relies on symmetry and a decision parameter to decide the best pixels to draw, ensuring that the circle appears smooth and round on raster displays.

## Algorithm

1. **Initialization**:
   - Set the initial point `(x, y)` on the circle to `(r, 0)`, where `r` is the radius.
   - Compute the initial decision parameter `P = 1 - r`.

2. **Plot Initial Points**:
   - Plot the initial point `(x + x_centre, y + y_centre)`.

3. **Iterate and Update**:
   - Increment `y` by 1.
   - Update the decision parameter `P` based on its value:
     - If `P <= 0`, the new decision parameter is `P = P + 2*y + 1`.
     - If `P > 0`, decrement `x` by 1 and update `P` to `P + 2*y - 2*x + 1`.
   - Continue until `x < y`.

4. **Plot Symmetric Points**:
   - For each computed `(x, y)`, plot the points in all eight octants of the circle.

## How It Works

The algorithm efficiently determines the circle's pixels by following these steps:

1. **Starting Point**:
   - Begin with the point `(x = r, y = 0)` and plot this initial point along with its symmetric counterparts in all octants.

2. **Decision Parameter**:
   - The decision parameter `P` helps decide whether to move the circle's boundary pixel horizontally or diagonally.
   - When `P <= 0`, the boundary pixel is chosen to be directly east, and the decision parameter is updated accordingly.
   - When `P > 0`, the boundary pixel is chosen diagonally southeast, which requires both `x` and `y` adjustments.

3. **Symmetry**:
   - Exploit the circle's symmetry by plotting the symmetric points across all eight octants to minimize calculations and avoid redundant plotting.

4. **Termination**:
   - The process continues until `x` is less than `y`, ensuring that all necessary pixels are plotted.

Here's the provided C++ code for the Midpoint Circle Drawing Algorithm:

```cpp
#include <iostream>
using namespace std;

void midPointCircleDraw(int x_centre, int y_centre, int r)
{
    int x = r, y = 0;
    int P = 1 - r;
    cout << "(" << x + x_centre << ", " << y + y_centre << ") ";
    while (x != y)
    {
        y++;
        if (P <= 0)
        {
            P = P + 2 * y + 1;
        }
        else
        {
            x--;
            P = P + 2 * y - 2 * x + 1;
        }

        if (x < y)
            break;
        cout << "(" << x + x_centre << ", " << y + y_centre << ") ";
    }
}

int main()
{
    midPointCircleDraw(0, 0, 10);
}
```

## Conclusion

The Midpoint Circle Drawing Algorithm is a robust and efficient method for circle rasterization, suitable for real-time graphics applications. By using integer arithmetic and symmetry, it simplifies calculations and improves performance, making it a valuable tool in graphics programming. This algorithm ensures accurate and visually pleasing circles on raster displays with minimal computational overhead.

