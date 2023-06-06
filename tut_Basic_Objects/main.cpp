#include "GL/freeglut.h"
#include <time.h>
#include <iostream>
#include <array>
#include <cmath>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "fish.h"


GLfloat x_arr[35]{};
GLfloat y_arr[35]{};
short fishCount = 0;


struct Position
{
    GLfloat x, y, z;
};

Position dronPos;
float pos_x = 0.5, pos_y = 0.3;
bool isRight = true;


// блок объявлений функций
void renderScene(void);
void backgroundScene();
void ship();
void dron(float x, float y);
void ProcessKeys(unsigned char key, int x, int y);
GLfloat RandomX();
GLfloat RandomY();



void fillArr(GLfloat *x, GLfloat *y)
{
    for (auto i = 0; i <= 34; i++)
    {
        GLfloat x_timed = RandomX();
        GLfloat y_timed = RandomY();
        x_timed = round(x_timed * 10) / 10.0f;
        y_timed = round(y_timed * 10) / 10.0f;
        x[i] = x_timed;
        y[i] = y_timed;
    }
}

int main(int argc, char* argv[])
{
    
    fillArr(x_arr, y_arr);

    for (auto i = 0; i < 34; i++)
    {
        x_arr[i] += 0.3;
        y_arr[i] -= 0.01;
    }

    for (auto i = 0; i <= 34; i++)
    {
        std::cout << x_arr[i] << "\t" << y_arr[i] << "\n";
    }


    srand(time(NULL));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("OpenGL Start Application");
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(ProcessKeys);
    glutMainLoop();
    return 0;
}


void fishes()
{
    glPushMatrix();

   
    for (auto i = 0; i < 34; i++)
    {
        
        glTranslatef(x_arr[i], y_arr[i], 0);
        fish();
    }
    glPopMatrix();
}



void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    backgroundScene();
   
    ship();
    dron(pos_x, pos_y);
    fishes();
    glutSwapBuffers();
}



void backgroundScene() {
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(127, 199, 255);
    glVertex2f(-1, 1);
    glVertex2f(1, 1);
    glVertex2f(1, 0.3);
    glVertex2f(-1, 0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(28, 169, 201);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, 0.3);
    glVertex2f(-1, 0.3);
    glEnd();

    glPopMatrix();
    
}


void ship() {
    glPushMatrix();
    glTranslatef(0.6, 0.4, 0);
    glScalef(0.4, 0.4, 0);
    glBegin(GL_TRIANGLES);
    glColor3ub(155, 45, 48);
    glVertex2f(-0.7, 0.2);
    glVertex2f(-0.2,0.2);
    glVertex2f(-0.7,-0.3);
    
    glVertex2f(-0.7,-0.3);
    glVertex2f(-0.5,-0.5);
    glVertex2f(-0.2,0.2);

    glVertex2f(0.1, 0.1);
    glVertex2f(0.2, 0.3);
    glVertex2f(0.2, 0.1);
    
    glVertex2f(-0.2,0.2);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.5,-0.5);
    
    glVertex2f(0.2,0.3);
    glVertex2f(0.2,0.1);
    glVertex2f(0.5,0.1);
    
    glVertex2f(0.5,0.1);
    glVertex2f(0.5,0.3);
    glVertex2f(0.2,0.3);
    
    glVertex2f(0.3,0.8);
    glVertex2f(0.3,0.3);
    glVertex2f(0.4,0.3);
    
    glVertex2f(0.3,0.8);
    glVertex2f(0.4,0.8);
    glVertex2f(0.4,0.3);
    
    glVertex2f(0.6,0.1);
    glVertex2f(0.7,0.2);
    glVertex2f(0.85,0.1);
   
    glVertex2f(0.85,0.1);
    glVertex2f(0.9,0.2);
    glVertex2f(0.7,0.2);
    
    glVertex2f(0.5,-0.5);
    glVertex2f(-0.1,0.1);
    glVertex2f(0.85,0.1);
    glEnd();

    glPopMatrix();
    
}

void dron(float x, float y) {

    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(0.2, 0.2, 0);
    if (isRight)
        glRotatef(180, 0, 1, 0);
    glBegin(GL_POLYGON);
    glColor3ub(180, 180, 180);
    glVertex2f(-0.7, 0);
    glVertex2f(-0.7, 0.02);
    glVertex2f(-0.7, 0.04);
    glVertex2f(-0.7, 0.06);
    glVertex2f(-0.7, 0.08);
    glVertex2f(-0.6, 0.1);
    glVertex2f(-0.6, 0.14);
    glVertex2f(-0.6, 0.18);
    glVertex2f(-0.6, 0.22);
    glVertex2f(-0.5, 0.25);
    glVertex2f(-0.5, 0.28);
    glVertex2f(-0.5, 0.31);
    glVertex2f(-0.4, 0.33);
    glVertex2f(-0.4, 0.35);
    glVertex2f(-0.3, 0.36);
    glVertex2f(-0.3, 0.37);
    glVertex2f(-0.2, 0.38);
    glVertex2f(-0.1, 0.39);
    glVertex2f(-0.08, 0.4);
    glVertex2f(-0.06, 0.4);
    glVertex2f(-0.04, 0.4);
    glVertex2f(-0.02, 0.4);
    glColor3ub(4, 67, 244);
    glVertex2f(0, 0.4);
    glVertex2f(0.7, 0);
    glVertex2f(0.7, 0.02);
    glVertex2f(0.7, 0.04);
    glVertex2f(0.7, 0.06);
    glVertex2f(0.7, 0.08);
    glVertex2f(0.6, 0.1);
    glVertex2f(0.6, 0.14);
    glVertex2f(0.6, 0.18);
    glVertex2f(0.6, 0.22);
    glVertex2f(0.5, 0.25);
    glVertex2f(0.5, 0.28);
    glVertex2f(0.5, 0.31);
    glVertex2f(0.4, 0.33);
    glVertex2f(0.4, 0.35);
    glVertex2f(0.3, 0.36);
    glVertex2f(0.3, 0.37);
    glVertex2f(0.2, 0.38);
    glVertex2f(0.1, 0.39);
    glVertex2f(0.08, 0.394);
    glVertex2f(0.06, 0.396);
    glVertex2f(0.04, 0.398);
    glVertex2f(0.02, 0.4);
    glColor3ub(180, 180, 180);
    glVertex2f(-0.7, 0);
    glVertex2f(-0.7, -0.02);
    glVertex2f(-0.7, -0.04);
    glVertex2f(-0.7, -0.06);
    glVertex2f(-0.7, -0.08);
    glVertex2f(-0.6, -0.1);
    glVertex2f(-0.6, -0.14);
    glVertex2f(-0.6, -0.18);
    glVertex2f(-0.6, -0.22);
    glVertex2f(-0.5, -0.25);
    glVertex2f(-0.5, -0.28);
    glVertex2f(-0.5, -0.31);
    glVertex2f(-0.4, -0.33);
    glVertex2f(-0.4, -0.35);
    glVertex2f(-0.3, -0.36);
    glVertex2f(-0.3, -0.37);
    glVertex2f(-0.2, -0.38);
    glVertex2f(-0.1, -0.39);
    glVertex2f(-0.08, -0.4);
    glVertex2f(-0.06, -0.4);
    glVertex2f(-0.04, -0.4);
    glVertex2f(-0.02, -0.4);
    glColor3ub(4, 67, 244);
    glVertex2f(0, -0.4);
    glVertex2f(0.7, -0);
    glVertex2f(0.7, -0.02);
    glVertex2f(0.7, -0.04);
    glVertex2f(0.7, -0.06);
    glVertex2f(0.7, -0.08);
    glVertex2f(0.6, -0.1);
    glVertex2f(0.6, -0.14);
    glVertex2f(0.6, -0.18);
    glVertex2f(0.6, -0.22);
    glVertex2f(0.5, -0.25);
    glVertex2f(0.5, -0.28);
    glVertex2f(0.5, -0.31);
    glVertex2f(0.4, -0.33);
    glVertex2f(0.4, -0.35);
    glVertex2f(0.3, -0.36);
    glVertex2f(0.3, -0.37);
    glVertex2f(0.2, -0.38);
    glVertex2f(0.1, -0.39);
    glVertex2f(0.08, -0.394);
    glVertex2f(0.06, -0.396);
    glVertex2f(0.04, -0.398);
    glVertex2f(0.02, -0.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(164, 232, 237);
    glVertex2f(-0.2, 0.48);
    glVertex2f(-0.1, 0.49);
    glVertex2f(-0.08, 0.5);
    glVertex2f(-0.06, 0.5);
    glVertex2f(-0.04, 0.5);
    glVertex2f(-0.02, 0.5);
    glVertex2f(0, 0.5);
    glVertex2f(0.02, 0.5);
    glVertex2f(0.04, 0.5);
    glVertex2f(0.06, 0.5);
    glVertex2f(0.08, 0.5);
    glVertex2f(0.1, 0.49);
    glVertex2f(0.2, 0.48);
    glColor3f(0, 0.4, 0.9);
    glVertex2f(0.23, 0.35);
    glVertex2f(0.24, 0.34);
    glVertex2f(-0.24, 0.34);
    glVertex2f(-0.23, 0.35);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255, 79, 0);
    glVertex2f(0.6, 0.2);
    glVertex2f(0.6, -0.2);
    glVertex2f(0.8, -0.4);
    glVertex2f(0.8, 0.4);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255, 215, 0);
    glVertex2f(-0.65, -0.09);
    glVertex2f(-0.6, -0.2);
    glVertex2f(-0.62, -0.25);
    glVertex2f(-0.71, -0.07);
    glEnd();


    glLineWidth(10);
    glBegin(GL_LINE_STRIP);
    glColor3ub(79, 0, 112);
    glVertex2f(-0.5, -0.25);
    glVertex2f(-0.7, -0.4);
    glVertex2f(-0.9, -0.33);
    glEnd();


    glBegin(GL_LINE_STRIP);
    glColor3ub(79, 0, 112);
    glVertex2f(-0.5, -0.25);
    glVertex2f(-0.7, -0.4);
    glVertex2f(-0.8, -0.6);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(79, 0, 112);
    glVertex2f(-0.4, -0.3);
    glVertex2f(-0.6, -0.45);
    glVertex2f(-0.45, -0.6);
    glEnd();


    glBegin(GL_LINE_STRIP);
    glColor3ub(79, 0, 112);
    glVertex2f(-0.4, -0.3);
    glVertex2f(-0.6, -0.45);
    glVertex2f(-0.7, -0.6);
    glEnd();
    glPopMatrix();
}

void ProcessKeys(unsigned char key, int x, int y)
{
    if (key == 'w') {

        if (pos_y < 0.2)
        {
            pos_y += 0.01;
        }
        glutPostRedisplay();
        isRight = false;
    }
    if (key == 's') {


        if (pos_y > -0.8)
        {
            pos_y -= 0.01;
        }
        glutPostRedisplay();
        isRight = false;
    }
    if (key == 'd')
    {

        if (pos_x < 0.8)
        {
            pos_x += 0.01;
        }


        glutPostRedisplay();
        isRight = true;
    }



    if (key == 'a')
    {
        if (pos_x > -0.8)
        {
            pos_x -= 0.01;
        }
        glutPostRedisplay();

        isRight = false;

    }
}

GLfloat RandomX()
{
    float min = -0.9;
    float max = 0.9;
    return (max - min) * ((double)rand() / (double)RAND_MAX) + min;
    return GLfloat();
}

GLfloat RandomY()
{
    float min = -0.7;
    float max = 0.2;
    return (max - min) * ((double)rand() / (double)RAND_MAX) + min;
    return GLfloat();
}



auto getRandomNum()
{
    auto min = 0;
    auto max = 34;
    auto result = min + rand() % (max - min);
    return result;

}

