#include<GL/glu.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include <math.h>

void drawCircle(float xc, float yc, float radius)
{
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i <= 360; i++)
    {
        float angle = i * 2.0f * M_PI / 360.0f;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(xc + x, yc + y);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(1.0, 1.0, 1.0); 
    drawCircle(0.0, 0.0, 0.5);  

    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);  
    glColor3f(1.0, 1.0, 1.0);  
    glPointSize(1.0); 
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); 
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Circle");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
