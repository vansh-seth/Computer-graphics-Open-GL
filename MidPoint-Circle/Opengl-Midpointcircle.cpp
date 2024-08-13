#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

int centerX, centerY, radius;

void drawAxes() {
    glBegin(GL_LINES);
    glVertex2i(-500, 0);
    glVertex2i(500, 0);
    glVertex2i(0, -500);
    glVertex2i(0, 500);
    glEnd();
}

void midpointCircle(int xk, int yk, int r) {
    int x = 0;
    int y = r;
    int d = 1 - r;

    glBegin(GL_POINTS);
    while (x <= y) {
        if (xk + x >= 0 && yk + y >= 0) glVertex2i(centerX + x, centerY + y);

        if (d < 0) {
            d = d + 2 * x + 3;
        } else {
            d = d + 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(x, y);
    glVertex2i(0, 0);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.5, 0.5);
    drawAxes();
    glColor3f(1.0, 1.0, 1.0);
    midpointCircle(0, 0, radius);
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}

int main(int argc, char** argv) {
    std::cout << "Enter the value of radius: ";
    std::cin >> radius;

    centerX = 0;
    centerY = 0;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Midpoint Circle Algorithm (First Octant)");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
