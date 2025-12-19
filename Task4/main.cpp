#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

float move1 = 0.0f;
float move2 = 0.0f;
float move3 = 0.0f;
float move4 = 0.0f;
float speed = 0.5f;

void obj1(){
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-7, 4);
    glVertex2f(-7, 1);
    glVertex2f(-4, 1);
    glVertex2f(-4, 4);
    glEnd();
}

void obj2(){
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-7, -1);
    glVertex2f(-4, -1);
    glVertex2f(-4, -4);
    glVertex2f(-7, -4);
    glEnd();
}

void obj3(){
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(1, 4);
    glVertex2f(4, 4);
    glVertex2f(4, 1);
    glVertex2f(1, 1);
    glEnd();
}

void obj4(){
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(1, -1);
    glVertex2f(4, -1);
    glVertex2f(4, -4);
    glVertex2f(1, -4);
    glEnd();
}

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': move1 += speed;
        break;
        case 's': move1 -= speed;
        break;
        case 'a': move2 -= speed;
        break;
        case 'd': move2 += speed;
        break;
        case 'i': move3 += speed;
        break;
        case 'k': move3 -= speed;
        break;
        case 'j': move4 -= speed;
        break;
        case 'l': move4 += speed;
        break;
        case ' ': move1 = move2 = move3 = move4 = 0.0f;
        break;
    }
    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(0, move1, 0);
    obj1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(move2, 0, 0);
    obj2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, move3, 0);
    obj3();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(move4, 0, 0);
    obj4();
    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("4 Different Objects Moving");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-15, 15, -10, 10);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutMainLoop();
    return 0;
}
