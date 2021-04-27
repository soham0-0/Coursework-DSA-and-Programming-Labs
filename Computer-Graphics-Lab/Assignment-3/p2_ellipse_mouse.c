#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

// Screen Constants
const int width = 1240;
const int height = 700;

// Parameters
int X = 0, Y = 0, a = 0, b = 0, click = 0;

void myInit(void) { 
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-width/2, width/2 - 1, -height/2, height/2 - 1);
}

void plot(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(x + X, y + Y);
  glEnd();
}

void drawAxes(){
	glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0, -height/2);
    glVertex2f(0, height/2);
    glVertex2f(-width/2, 0);
    glVertex2f(width/2, 0);
    glEnd();
	glColor3f(0.0f,0.0f,0.0f);
}

void drawEllipse() {
	int x_cur = 0, y_cur = b, x_next, y_next;
    float mid_y, p1 = (b * b) - (a * a * b) + 0.25 * a * a;
    float slope = (-2 * x_cur * b * b) / (2 * y_cur * a * a);
    while (slope > -1) {
        glBegin(GL_POINTS);
        glVertex2i(x_cur + X, y_cur + Y);
        glVertex2i(-x_cur + X, y_cur + Y);
        glVertex2i(x_cur + X, -y_cur + Y);
        glVertex2i(-x_cur + X, -y_cur + Y);
        glEnd();
        x_next = x_cur + 1;
        mid_y = y_cur - 0.5;
        if (p1 > 0) y_next = y_cur - 1;
        else y_next = y_cur;
        p1 = p1 + 2 * b * b * (x_cur + 1) + b * b + a * a * ((y_next - 0.5) * (y_next - 0.5) - (y_cur - 0.5) * (y_cur - 0.5));
        x_cur = x_next;
        y_cur = y_next;
        slope = (-2 * x_cur * b * b) / (2 * y_cur * a * a);
    }
    float p2 = p1;
    while (y_cur >= 0) {
        glBegin(GL_POINTS);
        glVertex2i(x_cur + X, y_cur + Y);
        glVertex2i(-x_cur + X, y_cur + Y);
        glVertex2i(x_cur + X, -y_cur + Y);
        glVertex2i(-x_cur + X, -y_cur + Y);
        glEnd();
        y_next = y_cur - 1;
        if (p2 <= 0) x_next = x_cur + 1;
        else x_next = x_cur;
        p2 = p2 - 2 * a * a * (y_cur - 1) + a * a + b * b * ((x_next + 0.5) * (x_next + 0.5) - (x_cur + 0.5) * (x_cur + 0.5));
        x_cur = x_next;
        y_cur = y_next;
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxes();
    glFlush();
}

void myMouseFunc(int button, int state, int x, int y) {
    y = height/2 - y;
    x = x - width/2;
    if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN)) {
        glClear(GL_COLOR_BUFFER_BIT);
        click = 0;
    }
    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
        if (!click) {
            X = x;
            Y = y;
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
        } 
        else if(click == 1) {
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
            float dx = x - X, dy = y - Y;
            b = sqrt(dx * dx + dy * dy);
        }
        else {
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
            float dx = x - X, dy = y - Y;
            a = sqrt(dx * dx + dy * dy);
            drawEllipse();
        }
        click = (click + 1) % 3;
    }
    glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); glutInitWindowSize(width, height);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Ellipse From Mouse Points(center, y distance, x distance)");
    glutDisplayFunc(display);
	glutMouseFunc(myMouseFunc);
    myInit(); glutMainLoop(); 
}