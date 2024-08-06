#include <iostream>
#include <GL/glut.h>
#include <cmath>

using namespace std;

int x, y, x2, y2; // Global variables to store line coordinates

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 320, 0, 240);
}

void bresenham_line(int x1, int y1, int x2, int y2) {
    glPointSize(2.0);
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    glBegin(GL_POINTS);
    while (true) {
        glVertex2i(x1, y1);
        if (x1 == x2 && y1 == y2) break;
        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
    glEnd();
    glFlush();
}

void bresenham_spoke() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    bresenham_line(x, y, x2, y2); // Draw the user-defined line
}

void launcher(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Bresenham Line Algorithm");
    glutDisplayFunc(bresenham_spoke);
    init();
    glutMainLoop();
}

int main(int argc, char** argv) {
    cout << "Enter the values in the order x, y, x2, y2\n";
    cin >> x >> y >> x2 >> y2;
    launcher(argc, argv);
    return 0;
}
