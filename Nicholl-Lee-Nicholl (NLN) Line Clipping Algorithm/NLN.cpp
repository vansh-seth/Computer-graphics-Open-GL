#include <GL/glut.h>
#include <iostream>

using namespace std;

#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

// Define the clipping window boundaries
float x_min = 100, y_min = 100, x_max = 400, y_max = 400;

// Function to compute the outcode for a point (x, y)
int computeOutcode(float x, float y) {
    int code = 0;
    if (x < x_min) code |= LEFT;
    else if (x > x_max) code |= RIGHT;
    if (y < y_min) code |= BOTTOM;
    else if (y > y_max) code |= TOP;
    return code;
}

// Nicholl-Lee-Nicholl line clipping algorithm
void NLN_LineClipping(float x1, float y1, float x2, float y2) {
    int outcode1 = computeOutcode(x1, y1);
    int outcode2 = computeOutcode(x2, y2);
    bool accept = false;

    while (true) {
        if (!(outcode1 | outcode2)) {  // Trivial accept
            accept = true;
            break;
        } else if (outcode1 & outcode2) {  // Trivial reject
            break;
        } else {
            float x, y;
            int outcodeOut = outcode1 ? outcode1 : outcode2;

            if (outcodeOut & TOP) {  // Clip against top edge
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            } else if (outcodeOut & BOTTOM) {  // Clip against bottom edge
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            } else if (outcodeOut & RIGHT) {  // Clip against right edge
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            } else if (outcodeOut & LEFT) {  // Clip against left edge
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            if (outcodeOut == outcode1) {
                x1 = x;
                y1 = y;
                outcode1 = computeOutcode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                outcode2 = computeOutcode(x2, y2);
            }
        }
    }

    if (accept) {
        // Draw the clipped line
        glColor3f(0.0, 1.0, 0.0);  // Green color for the clipped line
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    }
}

// Function to draw the clipping window
void drawClippingWindow() {
    glColor3f(1.0, 0.0, 0.0);  // Red color for the clipping window
    glBegin(GL_LINE_LOOP);
    glVertex2f(x_min, y_min);
    glVertex2f(x_max, y_min);
    glVertex2f(x_max, y_max);
    glVertex2f(x_min, y_max);
    glEnd();
}

// Display function to render the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw the clipping window
    drawClippingWindow();

    // Example lines
    float lines[][4] = {
        {50, 150, 350, 350},
        {200, 50, 300, 450},
        {120, 120, 400, 400},
        {150, 300, 450, 200}
    };

    for (int i = 0; i < 4; i++) {
        float x1 = lines[i][0], y1 = lines[i][1];
        float x2 = lines[i][2], y2 = lines[i][3];

        // Draw the original lines (in blue)
        glColor3f(0.0, 0.0, 1.0);  // Blue color for original lines
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();

        // Perform NLN Line Clipping
        NLN_LineClipping(x1, y1, x2, y2);
    }

    glFlush();
}

// Initialization function
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    gluOrtho2D(0, 500, 0, 500);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Nicholl-Lee-Nicholl Line Clipping");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

