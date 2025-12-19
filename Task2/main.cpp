#include <GL/freeglut.h>
#include <bits/stdc++.h>
using namespace std;
void obj1()
{
    glBegin(GL_QUADS);
        glColor3f(1, 0, 0);
        glVertex2f(-3, -3);
        glVertex2f( 3, -3);
        glVertex2f( 3,  3);
        glVertex2f(-3,  3);
    glEnd();
}
void obj2()
{
    glBegin(GL_TRIANGLES);
        glColor3f(0, 0, 1);
        glVertex2f(-4, 0);
        glVertex2f( 0, 4);
        glVertex2f( 4,  0);
    glEnd();
}

void obj3()
{
    glBegin(GL_QUADS);
        glColor3f(0, 1, 0);
        glVertex2f(-5, -5);
        glVertex2f( 5, -5);
        glVertex2f( 5,  5);
        glVertex2f(-5,  5);
    glEnd();
}

void obj4()
{
    glBegin(GL_TRIANGLES);
        glColor3f(0, 1, 0);
        glVertex2f(-7, 0);
        glVertex2f( 0, 7);
        glVertex2f( 7,  0);
    glEnd();
}
int dis = 1 ;

void display1()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    obj1();
    glutSwapBuffers();
}

void display2()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    obj2();
    glutSwapBuffers();
}

void display3()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    obj3();
    glutSwapBuffers();
}

void display4()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    obj4();

    glutSwapBuffers();
}

void timer(int)
{
if(dis == 1)
    {
        glutDisplayFunc(display2);
        dis = 2 ;
    }
    else if(dis == 2)
    {
        glutDisplayFunc(display3);
        dis = 3 ;
    }
    else if(dis == 3)
    {
        glutDisplayFunc(display4);
        dis = 4 ;
    }
    else if(dis == 4)
    {
        glutDisplayFunc(display1);
        dis = 1 ;
    }
    glutPostRedisplay();
    glutTimerFunc(200, timer, 0);
}

void init()
{
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10); // 2D coordinate system
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 80);
    glutInitWindowSize(1200, 600);
    glutCreateWindow("4 Objects");
    init();
    glutDisplayFunc(display1);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
