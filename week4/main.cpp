#include <GL/glut.h>
#include<math.h>
#include<stdio.h>

int n=0,vx[9999],vy[9999];
static void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glColor3b(1,0,0);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<n;i++){
        glVertex2f((vx[i]-150)/150.0,-(vy[i]-150)/150.0);
    }
    glEnd();
    glutSwapBuffers();
}
void mouseFunc(int x,int y)
{
    vx[n]=x;
    vy[n]=y;
    n++;
    display();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutDisplayFunc(display);
    glutMotionFunc(mouseFunc);
    glutMainLoop();
}
