#include <GL/glut.h>
#include <math.h>

int angle = 0.0;

void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for(int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta) + cx;
        float y = r * sinf(theta) + cy;
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1.0, 1.0, 1.0);

     glPushMatrix();
     glColor3f(1.0, 1.0, 0.0);
      glTranslatef(0, 0, 0);
      drawCircle(0.5, 0.5, 0.1, 50);
     glPopMatrix();

     glPushMatrix();
     glColor3f(0.0, 0.0, 1.0);
      glRotated(0.0f, 0.0, 1.0, .0);
      glRotated(0.0f, 0.0, -1.0, 0.0);
      glTranslatef(0, 0, 0);
      drawCircle(0.8, 0.5, 0.1, 50);
     glPopMatrix();

     glFlush();
}

void init() {
     glClearColor(0.0, 0.0, 0.0, 1.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char**argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);

    glutCreateWindow("solar system");

    glutDisplayFunc(display);
    init();

    glutMainLoop();
    return 0;
}
