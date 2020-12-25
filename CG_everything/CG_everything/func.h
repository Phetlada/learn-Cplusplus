#ifndef FUNC_H
#define FUNC_H
#include<GL\glut.h>

void putPixel(int x, int y);
void line_triangle();
void line_square();
void line_Pentagon();
void line_Hexagon();
void color_square();
void color_Hexagon();

void plot_e(int xc,int yc,int x,int y);
void ellipseMidpoint(int xc,int yc,int xr,int yr);
void ellip_circle();

void plot_c(int xc,int yc,int x,int y);
void circle();

void drawCharacter (void);

void line(int x1, int y1, int x2, int y2);
void myMotion (GLint x, GLint y);
void myPassiveMotion (GLint x, GLint y);
void line_mouse();
#endif