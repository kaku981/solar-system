#include <GL/glut.h>
#include <math.h>

void display();

void drawCircle(float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 0);

    for (int i = 0; i <= segments; i++) {
         float theta = 2.0f * 3.1415926f * float(i) / float(segments);
         float x = radius * cos(theta);
         float y = radius * sin(theta);
         glVertex2f(x, y);
    }
    glEnd();
}

int main(int argc, char**argv) {
    glutInit(&argc, argv);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);

    glutCreateWindow("solar system");

    glutDisplayFunc(display);

    glOrtho(0, 1, 0, 1, -1, 1);

    glutMainLoop();

    return 0;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    glLoadIdentity();

    glTranslatef(0.5f, 0.5f, 0.0f);

    glScalef(0.3f, 0.3f, 1.0f);

    drawCircle(1.0f, 100);
    glFlush();
}
