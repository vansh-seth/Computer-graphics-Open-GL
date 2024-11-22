#include <GL/glut.h>
#include <math.h>

float triangle[3][2] = {
    {0.0, 0.5},  // Vertex 1
    {-0.5, -0.5}, // Vertex 2
    {0.5, -0.5}   // Vertex 3
};

float transformedTriangle[3][2];
float angle = 0.0;      // Rotation angle
float scaleX = 1.0, scaleY = 1.0; // Scaling factors
float translateX = 0.0, translateY = 0.0; // Translation factors

void applyTransformations() {
    for (int i = 0; i < 3; i++) {
        // Apply scaling
        float x = triangle[i][0] * scaleX;
        float y = triangle[i][1] * scaleY;

        // Apply rotation
        float rotatedX = x * cos(angle) - y * sin(angle);
        float rotatedY = x * sin(angle) + y * cos(angle);

        // Apply translation
        transformedTriangle[i][0] = rotatedX + translateX;
        transformedTriangle[i][1] = rotatedY + translateY;
    }
}

void drawTriangle() {
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++) {
        glVertex2f(transformedTriangle[i][0], transformedTriangle[i][1]);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    applyTransformations();
    glColor3f(1.0, 0.0, 0.0); // Set color to red
    drawTriangle();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': translateY += 0.1; break; // Move up
        case 's': translateY -= 0.1; break; // Move down
        case 'a': translateX -= 0.1; break; // Move left
        case 'd': translateX += 0.1; break; // Move right
        case 'r': angle += 0.1; break;      // Rotate clockwise
        case 'e': angle -= 0.1; break;      // Rotate counter-clockwise
        case '+': scaleX += 0.1; scaleY += 0.1; break; // Increase size
        case '-': scaleX -= 0.1; scaleY -= 0.1; break; // Decrease size
        case 27: exit(0); // ESC to exit
    }
    glutPostRedisplay();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set coordinate system
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D Transformations");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
