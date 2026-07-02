#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void display();
void reshape(int, int);
void timer(int);

void init() {
     glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char**argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Window 1");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(1000, timer, 0);
    init();

    glutMainLoop();

}

float x_position = 0.0;
int state = 1;

void display() {
     glClear(GL_COLOR_BUFFER_BIT);
     glLoadIdentity();

     glTranslatef(0.0, 0.0, x_position);

     glBegin(GL_POLYGON);

     glColor3f(1.0, 0.0, 0.0);
     glVertex3f(-1.0, 1.0, 0.0);
     glVertex3f(-1.0, -1.0, 0.0);
     glVertex3f(1.0, -1.0, 0.0);
     glVertex3f(1.0, 1.0, 0.0);

     glEnd();

     glutSwapBuffers();
}

void reshape(int w, int h) {
     glViewport(0, 0, (GLsizei)w, (GLsizei)h);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective(60, 1, 2.0, 50.0);
     glMatrixMode(GL_MODELVIEW);
}

void timer(int) {
     glutPostRedisplay();
     glutTimerFunc(1000/60, timer, 0);

     switch(state) {
     case 1:
         if(x_position < -5)
             x_position += 0.30;
         else
             state = -1;
         break;
     case -1:
         if(x_position > -15)
             x_position -= 0.30;
         else
             state = 1;
         break;
     }
}
