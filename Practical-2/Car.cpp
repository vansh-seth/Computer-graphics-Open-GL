#include <GL/glut.h>

float angle = 0.0f;

void drawCar() {
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP); 
        glVertex2f(-0.4f, -0.2f);
        glVertex2f(0.4f, -0.2f);
        glVertex2f(0.4f, 0.1f);
        glVertex2f(-0.4f, 0.1f);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.2f, 0.1f); 
        glVertex2f(0.2f, 0.1f);
        glVertex2f(0.2f, 0.3f);
        glVertex2f(-0.2f, 0.3f);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(0.0f, 0.1f);
        glVertex2f(0.0f, 0.3f);
    glEnd();
    float cx = 0.15f, cy = 0.2f, r = 0.05f;
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 360; i++) {
            float theta = i * 3.14159f / 180.0f;
            glVertex2f(cx + r * cos(theta), cy + r * sin(theta));
        }
    glEnd();
    for (float wx = -0.3f; wx <= 0.3f; wx += 0.2f) {
        glBegin(GL_LINE_LOOP);
            for (int i = 0; i < 360; i++) {
                float theta = i * 3.14159f / 180.0f;
                glVertex2f(wx + 0.05f * cos(theta), -0.25f + 0.05f * sin(theta));
            }
        glEnd();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, 0.0f); 
    glRotatef(angle, 0.0f, 0.0f, 1.0f); 
    drawCar(); 
    glFlush();
}

void update(int value) {
    angle += 2.0f;  
    if (angle > 360) angle -= 360;
    glutPostRedisplay();     
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D Rotating Car");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);   
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0); 
    glutMainLoop();
    return 0;
}
