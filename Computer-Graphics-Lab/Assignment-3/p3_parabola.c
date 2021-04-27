#include <GL/glut.h>
#include <math.h>
#include <unistd.h>
#include <stdbool.h>

// Screen Constants
const int width = 1240;
const int height = 700;

// Parameters
int X = 0, Y = 0;
bool click = false;

void myInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.35, 0.45);
    glEnable(GL_POINT_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, width, 0.0, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void drawPoint(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void drawParabola(int cx, int cy, int a, int d) {
    int x = 0, y = 0, sx = 1, sy = 1, lt;
    if (d == 0) {
    if (a < 0) {
        sx = -1;
        lt = cx;
    } else
        lt = width - cx;
    int p = 1 - 2 * a;
    a = abs(a);
    while (y < 2 * a) {
        drawPoint(cx + sx * x, cy + y);
        drawPoint(cx + sx * x, cy - y);
        if (p > 0) {
            p -= 4 * a;
            x++;
        }
        y++;
        p += 2 * y + 3;
    }
    p = y * (y + 1) - (4 * a * (x - 1));
    while (lt--) {
        drawPoint(cx + sx * x, cy + y);
        drawPoint(cx + sx * x, cy - y);
        if (p > 0) {
            p += 2 * y;
            y++;
        }
        x++;
        p -= 4 * a;
    }
    } else {
    if (a < 0)
        sy = -1;
    }
}

void myMouseFunc(int button, int state, int x, int y) {
    y = glutGet(GLUT_WINDOW_HEIGHT) - y;
    if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN)) {
        glClear(GL_COLOR_BUFFER_BIT);
        click = false;
    }
    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
        if (!click) {
            X = x;
            Y = y;
            drawPoint(x, y);
        } else if (click % 2 == 1) {
            if (abs(y) > abs(x)) {
                drawPoint(X, y);
                drawParabola(X, Y, y - Y, 1);
            } else {
                drawPoint(x, Y);
                drawParabola(X, Y, x - X, 0);
            }
        }
        click = !click;
    }
    glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(width, height);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Parabola Drawing Algorithm");
  glutDisplayFunc(display);
  glutMouseFunc(myMouseFunc);
  myInit();
  glutMainLoop();
  return 0;
}