#include <GL/glut.h>

// Variables for translation and scaling
float translateX = 0.0f, translateY = 0.0f, translateZ = -7.0f;
float scaleX = 1.0f, scaleY = 1.0f, scaleZ = 1.0f;

// Initialize the OpenGL environment
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color to black
    glEnable(GL_DEPTH_TEST);          // Enable depth testing for 3D
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color and depth buffers

    glMatrixMode(GL_MODELVIEW); // Switch to the modelview matrix
    glLoadIdentity();           // Reset the modelview matrix

    // Apply translation
    glTranslatef(translateX, translateY, translateZ);

    // Apply scaling
    glScalef(scaleX, scaleY, scaleZ);

    // Draw a cube
    glBegin(GL_QUADS);

    // Front face
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    // Back face
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Left face
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    // Right face
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Top face
    glColor3f(0.0f, 1.0f, 1.0f); // Cyan
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Bottom face
    glColor3f(1.0f, 0.0f, 1.0f); // Magenta
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    glEnd();

    glutSwapBuffers(); // Swap buffers for double buffering
}

// Reshape callback function
void reshape(int width, int height) {
    if (height == 0) height = 1; // Prevent divide by zero

    float aspect = (float)width / height;

    glViewport(0, 0, width, height); // Set the viewport to cover the new window

    glMatrixMode(GL_PROJECTION); // Switch to the projection matrix
    glLoadIdentity(); // Reset the projection matrix
    gluPerspective(45.0, aspect, 0.1, 100.0); // Set the perspective projection
}

// Keyboard callback function
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': // Move up
            translateY += 0.1f;
            break;
        case 's': // Move down
            translateY -= 0.1f;
            break;
        case 'a': // Move left
            translateX -= 0.1f;
            break;
        case 'd': // Move right
            translateX += 0.1f;
            break;
        case 'q': // Move forward
            translateZ += 0.1f;
            break;
        case 'e': // Move backward
            translateZ -= 0.1f;
            break;
        case 'i': // Scale up in Y-axis
            scaleY += 0.1f;
            break;
        case 'k': // Scale down in Y-axis
            scaleY -= 0.1f;
            break;
        case 'j': // Scale up in X-axis
            scaleX += 0.1f;
            break;
        case 'l': // Scale down in X-axis
            scaleX -= 0.1f;
            break;
        case 'u': // Scale up in Z-axis
            scaleZ += 0.1f;
            break;
        case 'o': // Scale down in Z-axis
            scaleZ -= 0.1f;
            break;
        case 27: // ESC key to exit
            exit(0);
    }
    glutPostRedisplay(); // Redraw the scene with updated transformations
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Set display mode
    glutInitWindowSize(800, 600); // Set window size
    glutCreateWindow("3D Translation and Scaling with Keyboard"); // Create window with title

    init(); // Initialize the OpenGL environment
    glutDisplayFunc(display); // Register display callback function
    glutReshapeFunc(reshape); // Register reshape callback function
    glutKeyboardFunc(keyboard); // Register keyboard callback function

    glutMainLoop(); // Enter the event-processing loop

    return 0;
}
