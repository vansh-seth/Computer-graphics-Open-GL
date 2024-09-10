#include <GL/glut.h>
#include <cmath>
const int WIDTH = 800;
const int HEIGHT = 600;
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
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);  
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.8f, -0.6f);
    glVertex2f(0.8f, -0.6f);
    glVertex2f(0.8f, 0.6f);
    glVertex2f(-0.8f, 0.6f);
    glEnd();
    float side = 1.0f;  
    float height = side * sqrt(3.0f) / 2.0f; 
    float radius = side * sqrt(3.0f) / 6.0f; 

    glColor3f(0.0f, 1.0f, 0.0f);  
    glBegin(GL_LINE_LOOP);
    glVertex2f(-side / 2.0f, -height / 3.0f);
    glVertex2f(side / 2.0f, -height / 3.0f);
    glVertex2f(0.0f, 2.0f * height / 3.0f);
    glEnd();

    // Draw the circle inside the triangle
    glColor3f(0.0f, 0.0f, 1.0f);  // Blue color
    drawCircle(0.0f, 0.0f, radius, 100);

    glFlush();
}
void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); 
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circle inside Triangle inside Rectangle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
