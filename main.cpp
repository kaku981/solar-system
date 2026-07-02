#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void display();
void reshape(int, int);

void init() {
     glClearColor(0.0, 0.0, 0.0, 1.0);
     
}

int main(int argc, char**argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Window 1");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();

    glutMainLoop();

}

void display() {
     glClear(GL_COLOR_BUFFER_BIT);
     glLoadIdentity();

     glBegin(GL_POLYGON);

     glVertex2f(0.0, 5.0);
     glVertex2f(4.0, -3.0);
     glVertex2f(-4.0, -3.0);
     glVertex2f(5.0, -2.0);

     glEnd();

     glFlush();
}

void reshape(int w, int h) {
     glViewport(0, 0, (GLsizei)w, (GLsizei)h);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-10, 10, -10, 10);
     glMatrixMode(GL_MODELVIEW);
}
