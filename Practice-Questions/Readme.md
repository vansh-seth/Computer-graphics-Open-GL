#include <GL/glut.h>
#include <cmath>

// Constants for the window size
const int WIDTH = 800;
const int HEIGHT = 600;

// Function to draw a circle
void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; ++i) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float dx = r * cosf(theta);
        float dy = r * sinf(theta);
        glVertex2f(dx + cx, dy + cy);
    }
    glEnd();
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the rectangle
    glColor3f(1.0f, 0.0f, 0.0f);  // Red color
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.8f, -0.6f);
    glVertex2f(0.8f, -0.6f);
    glVertex2f(0.8f, 0.6f);
    glVertex2f(-0.8f, 0.6f);
    glEnd();

    // Draw the circle inside the rectangle
    float circle_radius = 0.4f;  // Radius of the circle
    glColor3f(0.0f, 1.0f, 0.0f);  // Green color
    drawCircle(0.0f, 0.0f, circle_radius, 100);

    // Draw the equilateral triangle inside the circle
    float side_length = circle_radius * sqrt(3.0f); // Side length of the equilateral triangle
    float height = side_length * sqrt(3.0f) / 2.0f; // Height of the equilateral triangle

    glColor3f(0.0f, 0.0f, 1.0f);  // Blue color
    glBegin(GL_LINE_LOOP);
    glVertex2f(-side_length / 2.0f, -height / 3.0f);
    glVertex2f(side_length / 2.0f, -height / 3.0f);
    glVertex2f(0.0f, 2.0f * height / 3.0f);
    glEnd();

    glFlush();
}

// Initialization function
void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set the coordinate system
    glMatrixMode(GL_MODELVIEW);
}

// Main function
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Triangle inside Circle inside Rectangle");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
