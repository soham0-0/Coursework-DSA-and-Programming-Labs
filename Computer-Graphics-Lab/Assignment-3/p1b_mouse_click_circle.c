#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Screen Constants
const int width = 1240;
const int height = 700;

// Parameters
int X = 0, Y = 0, r = 0;
bool click = false;

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
    glVertex2f(0, -height);
    glVertex2f(0, height);
    glVertex2f(-width, 0);
    glVertex2f(width, 0);
    glEnd();
	glColor3f(0.0f,0.0f,0.0f);
}

void bresenhamCircle() {
	glColor3f(0.0f,0.0f,0.0f);
	int x = 0, y = r;
	float d = 3 - 2 * r;
	plot(x, y);
	while(x <= y){
		if (d < 0) {
			++x;
			d += 2 * x + 1;
		}
		else {
			--y;
			++x;
			d += 2 * (x - y) + 1;
		}
		plot(x, y); plot(x, -y);
		plot(-x, y); plot(-x, -y);
		plot(y, x); plot(-y, x);
		plot(y, -x); plot(-y, -x);
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
        click = false;
    }
    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
        if (!click) {
            X = x;
            Y = y;
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
        } else {
            float dx = x - X, dy = y - Y;
            r = sqrt(dx * dx + dy * dy);
            bresenhamCircle();
        }
        click = !click;
    }
    glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); glutInitWindowSize(width, height);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Circle From Mouse Point");
    glutDisplayFunc(display);
	glutMouseFunc(myMouseFunc);
    myInit(); glutMainLoop(); 
}