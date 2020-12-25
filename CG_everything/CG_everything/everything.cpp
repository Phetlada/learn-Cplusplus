#include<iostream>
#include "func.h"
using namespace std;
#include<GL\glut.h>


void init(void);
void display(void);
void main(int argc, char **argv)
{
	line_mouse();
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(800,600);
	glutCreateWindow("Everything");
	init();
	glutDisplayFunc(display);
	glutMotionFunc (myMotion);
	glutPassiveMotionFunc (myPassiveMotion);
	glutMainLoop();
}
void init(void){
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,800.0,0.0,600.0);
}
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5);
	glPointSize(1.2);
	glColor3f(1.0,0,0);
	//glLineWidth(5);
	//drawCharacter();
	//putPixel(10,10);
	//line_triangle();
	//line_square();
	//line_Pentagon();
	//line_Hexagon();
	//color_square();
	//color_Hexagon();
	//ellip_circle();
	//circle();
	glFlush();
}