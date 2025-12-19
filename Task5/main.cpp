#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_DROPS 1000

float dropX[MAX_DROPS];
float dropY[MAX_DROPS];
int totalDrops = 0;
float waterLevel = -8.0f;

void obj6() {
    glColor3f(0.4f, 0.2f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-10, 5);
    glVertex2f(-10, -2);
    glVertex2f(-9.196, -1.987);
    glVertex2f(-9.22, 5.012);
    glEnd();
}

void obj7() {
    glColor3f(0.4f, 0.2f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-13, 5);
    glVertex2f(-11.99, 5);
    glVertex2f(-12, -2);
    glVertex2f(-13, -2);
    glEnd();
}

void obj8() {
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-13, 5);
    glVertex2f(-10.80, 8.191);
    glVertex2f(-12, 10);
    glVertex2f(-16.441, 5.012);
    glEnd();
}

void obj9() {
    glColor3f(0.0f, 0.8f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-13, 5);
    glVertex2f(-6, 5);
    glVertex2f(-9.58, 9.973);
    glEnd();
}

void obj10(){
    glColor3f(1.0f, 0.9f, 0.0f);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 200; i++) {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 1.3828;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawHouse() {
    glColor3f(0.6f, 0.3f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(-4, -2);
    glVertex2f(4, -2);
    glVertex2f(4, 3);
    glVertex2f(-4, 3);
    glEnd();

    glColor3f(0.8f, 0.1f, 0.1f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-5, 3);
    glVertex2f(5, 3);
    glVertex2f(0, 6);
    glEnd();

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(4, 2);
    glVertex2f(2.78, 2.01);
    glVertex2f(2.77, 0.824);
    glVertex2f(4, 0.823);
    glVertex2f(-4, 2);
    glVertex2f(-4, 0.805);
    glVertex2f(-2.81, 0.805);
    glVertex2f(-2.83, 2);
    glEnd();

    glColor3f(0.4, 0.2, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-1, 1);
    glVertex2f(1, 1);
    glVertex2f(1, -2);
    glVertex2f(-1, -2);
    glEnd();
}

void addDrop() {
    if (totalDrops < MAX_DROPS) {
        dropX[totalDrops] = -18.0f + static_cast<float>(rand()) / (RAND_MAX / 36.0f);
        dropY[totalDrops] = 15.0f;
        totalDrops++;
    }
}

void update(int value) {
    for (int i = 0; i < totalDrops; i++) {
        dropY[i] -= 0.4f;
        if (dropY[i] <= waterLevel) {
            if (waterLevel < 3.5f) waterLevel += 0.005f;
            for (int j = i; j < totalDrops - 1; j++) {
                dropX[j] = dropX[j + 1];
                dropY[j] = dropY[j + 1];
            }
            totalDrops--; i--;
        }
    }
    for (int i = 0; i < 5; i++) addDrop();
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void drawRaindrops() {
    glColor3f(0.4f, 0.7f, 1.0f);
    glLineWidth(1.5f);
    glBegin(GL_LINES);
    for (int i = 0; i < totalDrops; i++) {
        glVertex2f(dropX[i], dropY[i]);
        glVertex2f(dropX[i], dropY[i] - 0.5f);
    }
    glEnd();
}

void drawWater() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.0f, 0.3f, 0.7f, 0.7f);
    glBegin(GL_QUADS);
    glVertex2f(-20, -15);
    glVertex2f(20, -15);
    glVertex2f(20, waterLevel);
    glVertex2f(-20, waterLevel);
    glEnd();
    glDisable(GL_BLEND);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(7.0, 7.5, 0);
    obj10();
    glPopMatrix();
    obj6();
    obj7();
    obj8();
    obj9();
    drawHouse();
    drawWater();
    drawRaindrops();
    glutSwapBuffers();
}

void init() {
    glClearColor(0.05f, 0.05f, 0.1f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-18, 18, -15, 15);
    srand(time(NULL));
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(850, 600);
    glutCreateWindow("Rain & Flood Creation");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
