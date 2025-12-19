#include <GL/freeglut.h>
#include <bits/stdc++.h>
using namespace std;
string color = "red";

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutSwapBuffers();
}

void timer(int)
{
    if(color == "red")
    {
        glClearColor(0, 1, 0, 1);
        color = "green";
    }
    else
    {
        glClearColor(1, 0, 0, 1);
        color = "red";
    }
    glutPostRedisplay();
    glutTimerFunc(220, timer, 0);
}


void init()
{
    glClearColor(1, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10); // 2D coordinate system
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(60, 40);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Change of Background Color");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
