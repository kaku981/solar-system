#include <GL/glut.h>
#include <math.h>

float x_position = -10.0;
int state = 1;

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
     drawCircle(0.5, 0.5, 0.9, 50);

     glutSwapBuffers();
}

void init() {
     glClearColor(0.0, 0.0, 0.0, 1.0);
      glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void reshape(int w, int h) {
     glViewport(0, 0, (GLsizei)w, (GLsizei)h);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-10, 10, -10, 10);
     glMatrixMode(GL_MODELVIEW);
}

void timer(int) {
     glutPostRedisplay();
     glutTimerFunc(1000/60, timer, 0);

     switch(state) {
     case 1:
         if(x_position < 8)
             x_position += 0.15;
         else
             state = -1;
         break;
     case -1:
         if(x_position >- 10)
             x_position -= 0.15;
         else
             state = 1;
         break;
     }
}

int main(int argc, char**argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);

    glutCreateWindow("solar system");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(1000, timer, 0);
    init();

    glutMainLoop();
    return 0;
}
