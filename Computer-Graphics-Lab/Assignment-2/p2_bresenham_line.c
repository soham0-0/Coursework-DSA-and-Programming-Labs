#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

// Screen Constants
const int width = 1240;
const int height = 700;

// Parameters
int m, x_1, y_1, x_2, y_2;

void myInit(void) { 
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-width, width, -height, height);
}

int round_num(float f) {
    return floor(f + 0.5);
}

void drawPixel(float x, float y) {
    int xT = round_num(x)*m;
    int yT = round_num(y)*m;
    glBegin(GL_POLYGON);
    glVertex2d(xT, yT);
    glVertex2d(xT, yT + m);
    glVertex2d(xT + m, yT + m);
    glVertex2d(xT + m, yT);
    glEnd();
}

void drawGrid(){
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    
    int t = m;
    for(; t <= width; t += m) {
        glVertex2f(t, height);
        glVertex2f(t, -height);
        glVertex2f(-t, height);
        glVertex2f(-t, -height);
    }
    
    t = m;
    for(; t <= height; t += m) {
        glVertex2f(-width, t);
        glVertex2f(width, t);
        glVertex2f(-width, -t);
        glVertex2f(width, -t);
    }
    
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(0, -height);
    glVertex2f(0, height);
    glVertex2f(-width, 0);
    glVertex2f(width, 0);
    glEnd();
}

void bresenhamLine() {
    glColor3f(0.0f,0.0f,0.0f);

    int dx = x_2 - x_1, dy = y_2 - y_1, x = x_1, y = y_1, p = 2*dy - dx; 
    while(x < x_2) {  
        if(p >= 0) {  
            ++y;  
            p += 2*dy - 2*dx;  
            drawPixel(x, y);  
        }  
        else {  
            drawPixel(x, y);  
            p += 2*dy;
        }  
        ++x;  
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    bresenhamLine();
    glFlush();
}

void main(int argc, char** argv) {
    printf("Enter pixel size (m): ");
    scanf("%d", &m);
    printf("Enter point 1 (x1 y1): ");
    scanf("%d %d", &x_1, &y_1);
    printf("Enter point 2 (x2 y2): ");
    scanf("%d %d", &x_2, &y_2);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); glutInitWindowSize(width, height);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Bresenham's Line Drawing");
    glutDisplayFunc(display);
    myInit(); glutMainLoop(); 
}