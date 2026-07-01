#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void display();

int main(int argc, char**argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);
  
    glutCreateWindow("Window 1");

    glutDisplayFunc(display);

    glutMainLoop();

}

void display() {}
