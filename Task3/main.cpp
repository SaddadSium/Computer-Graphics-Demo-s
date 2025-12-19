#include <GL/freeglut.h>
#include <bits/stdc++.h>
using namespace std;

void square(float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(-1, -1);
        glVertex2f( 1, -1);
        glVertex2f( 1,  1);
        glVertex2f(-1,  1);
    glEnd();
}

float xt1 = -15, yt1 = 0;
float xt2 =  15, yt2 = 0;
float xt3 = 0, yt3 = -6;
float xt4 = 0, yt4 =  6;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        glTranslatef(xt1, yt1, 0);
        square(1, 0, 0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(xt2, yt2, 0);
        square(0, 1, 0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(xt3, yt3, 0);
        square(0, 0, 1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(xt4, yt4, 0);
        square(0, 0, 0);
    glPopMatrix();

    glutSwapBuffers();
}

void timer(int)
{
    xt1 += 0.3;
    if (xt1 > 18) xt1 = -18;
    xt2 -= 0.3;
    if (xt2 < -18) xt2 = 18;
    yt3 += 0.2;
    if (yt3 > 8) yt3 = -8;
    yt4 -= 0.2;
    if (yt4 < -8) yt4 = 8;
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
}

void init()
{
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20, 20, -10, 10);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("4 Moving Squares");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
