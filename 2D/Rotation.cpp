#include <GL/glut.h>
#include <math.h>

float triangle[3][2] = {
    {0.0, 0.5},  // Vertex 1
    {-0.5, -0.5}, // Vertex 2
    {0.5, -0.5}   // Vertex 3
};

float angle = 0.0; // Rotation angle (in radians)

void applyRotation(float angle) {
    float rotatedTriangle[3][2];
    for (int i = 0; i < 3; i++) {
        // Apply rotation formula
        rotatedTriangle[i][0] = triangle[i][0] * cos(angle) - triangle[i][1] * sin(angle);
        rotatedTriangle[i][1] = triangle[i][0] * sin(angle) + triangle[i][1] * cos(angle);
    }

    // Draw the rotated triangle
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++) {
        glVertex2f(rotatedTriangle[i][0], rotatedTriangle[i][1]);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0); // Set triangle color to green

    applyRotation(angle);

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'r': angle += 0.1; break; // Rotate clockwise (increment angle)
        case 'e': angle -= 0.1; break; // Rotate anticlockwise (decrement angle)
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
    glutCreateWindow("2D Rotation");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
