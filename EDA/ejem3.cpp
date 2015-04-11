#include <GL/freeglut.h>
#include <iostream>
#include <sstream>

using namespace std;

int width = 800;
int height = 800;
void initGL(void) {
   glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Black Background
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void resize(int w, int h){
   width = w;
   height = h;
   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-width/2.0, width/2.0, -height/2.0, height/2.0, -1, 1);
   glMatrixMode(GL_MODELVIEW);
}

void draw(){
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(100, 0);
        glVertex2f(100, 100);
        glVertex2f(0, 100);
    glEnd();
    glutSwapBuffers();
}

void mousePress(int button, int state, int x, int y){
    cout<<x - width*0.5<<", "<<width*0.5 - y<<endl;
}

int main(int argc, char **argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowPosition(0, 0);
   glutInitWindowSize(width, height);
   glutCreateWindow("");
   initGL();
   glutReshapeFunc(resize);
   glutDisplayFunc(draw);
   glutMouseFunc(mousePress);
   glutMainLoop();
   return 0;
}

