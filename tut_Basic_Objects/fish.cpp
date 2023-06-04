#include "fish.h"


void fish() {
    glPushMatrix();

    //glTranslatef(-0.8, -0.7,0);
    glScalef(0.06, 0.06, 0);
    glBegin(GL_TRIANGLES);
    glColor3ub(140, 70, 50);
    glVertex2f(-0.4, 0.2);
    glVertex2f(0, 0.2);
    glVertex2f(0, 0);

    glVertex2f(-0.4, 0.2);
    glVertex2f(0, 0);
    glVertex2f(-0.4, -0.2);

    glVertex2f(0, 0);
    glVertex2f(-0.4, -0.2);
    glVertex2f(0, -0.2);

    glVertex2f(0, 0.2);
    glVertex2f(0, -0.2);
    glVertex2f(0.3, 0);

    glVertex2f(0.25, 0);
    glVertex2f(0.45, 0.2);
    glVertex2f(0.45, -0.2);

    glColor3ub(150, 0, 0);
    glVertex2f(-0.1, 0.33);
    glVertex2f(-0.1, 0.2);
    glVertex2f(-0.3, 0.2);

    glVertex2f(-0.4, 0.2);
    glVertex2f(-0.4, -0.2);
    glVertex2f(-0.55, 0);

    glColor3ub(255, 255, 255);
    glVertex2f(-0.45, 0.);
    glVertex2f(-0.43, 0.07);
    glVertex2f(-0.48, 0.07);


    glEnd();
    glPopMatrix();
}