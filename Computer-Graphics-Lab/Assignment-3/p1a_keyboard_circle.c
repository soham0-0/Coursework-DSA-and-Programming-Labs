#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

// Screen Constants
const int width = 1240;
const int height = 700;

// Parameters
int X, Y, r;

void myInit(void) { 
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-width, width, -height, height);
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
	bresenhamCircle();
    glFlush();
}

void main(int argc, char** argv) {
    printf("Enter centre x - coordinate: ");
	scanf("%d", &X);
    printf("Enter centre y - coordinate: ");
	scanf("%d", &Y);
    printf("Enter radius: ");
	scanf("%d", &r);
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); glutInitWindowSize(width, height);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Circle From Keyboard");
    glutDisplayFunc(display);
    myInit(); glutMainLoop(); 
}