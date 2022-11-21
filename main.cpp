#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

#include <stdlib.h>
#include <windows.h>


void display();
void reshape(int, int);
void timer(int);

void init(){
    glClearColor(0.11,0.63,0.84,1.0);
}

int main(int argc, char**argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //using GLUT_double to elimenate any frame timings issues

    glutInitWindowPosition(200, 0);
    glutInitWindowSize(1200, 800);

    glutCreateWindow("20101912/20101839");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(1000, timer, 0);
    init();
    glutMainLoop();

}

int state = 1;
float step=0;
float step2=0;


void circle(float x, float y, double r){
    float x1, y1;
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 360; i++){
        float pi = 3.1416;
        float A = (i*2*pi)/180;
        float x1 = x+((r) * cos(A) );
        float y1 = y+((r) * sin(A));
        glVertex2f(x1, y1);
    }
    glEnd();
}
void semicircle(float x, float y, double r){
    float x1, y1;
    glBegin(GL_POLYGON);
    for(int i = 0 ; i<=180 ; i++){
        float A = i * 3.1416 / 180;
        float x1 = x+((r) * cos(A) );
        float y1 = y+((r) * sin(A));
        glVertex2d(x1,y1);
    }
    glEnd();
}

void sun(){
    glColor3f(1.00, 0.843, 0.00);
    circle(-8,8,1.5);
}
void cloud1(){
    glColor3f(10.0,10.0,10.00);
    glTranslated(-4,7,0);
    circle(0,0,2);
    circle(1.2,0,1.5);
    circle(-1.2,0,1.5);

}
void cloud2(){
    glColor3f(10.0,10.0,10.00);
    glTranslated(0,7.5,0);
    if ((1.2+step) <= 8){
    circle(0+step,0,2);
    circle(1.2+step,0,1.5);
    circle(-1.2+step,0,1.5);

    }
    else{
    circle(6.8-step,0,2);
    circle(8-step,0,1.5);
    circle(5.6-step,0,1.5);

    }


}
void cloud3(){
    glColor3f(10.0,10.0,10.00);
    glTranslated(4,6,0);
    circle(0,0,2);
    circle(1.2,0,1.5);
    circle(-1.2,0,1.5);
}

void sky(){
    glColor3f(0.116, 0.560, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-10.0, 2.0);
    glVertex2f(-10.0, 10.0);
    glVertex2f(10.0, 10.0);
    glVertex2f(10.0, 2.0);
    glEnd();
}

void sand(){
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-10.0, -10.0);
    glVertex2f(-10.0, -5.);
    glVertex2f(10.0, -1.0);
    glVertex2f(10.0, -10.0);
    glEnd();

}

void mrkb(){
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(7.0);
    glBegin(GL_LINES);
    glVertex2f(-7+step,1+step2);
    glVertex2f(-7+step,-2+step2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-7+step,1+step2);
    glVertex2f(-5.5+step,-1+step2);
    glVertex2f(-7+step,-1+step2);
    glEnd();
    glRotatef(180.0 , -10.5 , 0 , 0);
    semicircle(-7+step,2-step2,1.8);
}





void display(){
    glClear(GL_COLOR_BUFFER_BIT); //clears the frame buffer
    glLoadIdentity();
    glPointSize(10.0);
    sky();
    sand();
    sun();
    cloud2();
    glTranslated(0,-7,0);
    mrkb();
    glEnd();
    glutSwapBuffers(); //displays the animation

}

void reshape(int w, int h){
        glViewport(0, 0, (GLsizei)w, (GLsizei)h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-10, 10, -10, 10);
        glMatrixMode(GL_MODELVIEW);
    }

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
	step+=0.1;
	step2+=0.02;


}
