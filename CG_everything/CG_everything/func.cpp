#include<iostream>
using namespace std;
#include<GL\glut.h>
GLint X1, Y1, X2, Y2;

void putPixel(int x, int y){
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
}
void line_triangle(){
	//glBegin(GL_LINES);
	//glBegin(GL_LINE_STRIP);
	glBegin(GL_LINE_LOOP);
		glVertex2i(50,50);
		glVertex2i(100,100);
		glVertex2i(100,50);
	glEnd();
}
void line_square(){
	//glBegin(GL_LINES);
	//glBegin(GL_LINE_STRIP);
	glBegin(GL_LINE_LOOP);
		glVertex2i(50,50);
		glVertex2i(50,100);
		glVertex2i(100,100);
		glVertex2i(100,50);
	glEnd();
}
void line_Pentagon(){
	//glBegin(GL_LINES);
	//glBegin(GL_LINE_STRIP);
	glBegin(GL_LINE_LOOP);
		glVertex2i(50,50);
		glVertex2i(25,100);
		glVertex2i(75,150);
		glVertex2i(125,100);
		glVertex2i(100,50);
	glEnd();
}
void line_Hexagon(){
	//glBegin(GL_LINES);
	//glBegin(GL_LINE_STRIP);
	glBegin(GL_LINE_LOOP);
	//glBegin( GL_TRIANGLE_FAN );
	//glBegin( GL_TRIANGLE_STRIP );
	//glBegin( GL_TRIANGLES );
		glVertex2i(50,50);
		glVertex2i(25,75);
		glVertex2i(25,100);
		glVertex2i(50,125);
		glVertex2i(100,125);
		glVertex2i(125,100);
		glVertex2i(125,75);
		glVertex2i(100,50);
	glEnd();
}
void color_Hexagon(){
	glBegin( GL_TRIANGLE_FAN );
	//glBegin( GL_TRIANGLE_STRIP );
	//glBegin( GL_TRIANGLES );
		glVertex2i(50,50);
		glVertex2i(25,75);
		glVertex2i(25,100);
		glVertex2i(50,125);
		glVertex2i(100,125);
		glVertex2i(125,100);
		glVertex2i(125,75);
		glVertex2i(100,50);
	glEnd();
}
void color_square(){
	glRecti( 50, 50, 200, 150 );

}
void plot_e(int xc,int yc,int x,int y){
	putPixel(xc+x,yc+y);
	putPixel(xc-x,yc+y);
	putPixel(xc+x,yc-y);
	putPixel(xc-x,yc-y);
}
void plot_c(int xc,int yc,int x,int y){
	putPixel(xc+x,yc+y);
	putPixel(xc-x,yc+y);
	putPixel(xc+x,yc-y);
	putPixel(xc-x,yc-y);
	putPixel(xc+y,yc+x);
	putPixel(xc-y,yc+x);
	putPixel(xc+y,yc-x);
	putPixel(xc-y,yc-x);
}
void ellipseMidpoint(int xc,int yc,int xr,int yr){
	float x,y,dx,dy,d1,d2;
	x=0;
	y=yr;
	d1 = (yr * yr) - (xr * xr * yr) +  (0.25 * xr * xr);
	dx = 2 * yr * yr * x; 
    dy = 2 * xr * xr * y; 

	while(dx<dy){
		plot_e(xc,yc,x,y);
		x++; 
		if(d1<=0){
            dx = dx + (2 * yr * yr); 
            d1 = d1 + dx + (yr * yr); 
		}else{
			y--;
			dx = dx + (2 * yr * yr); 
            dy = dy - (2 * xr * xr); 
            d1 = d1 + dx - dy + (yr * yr); 
		}
		
	}
	d2 = ((yr * yr) * ((x + 0.5) * (x + 0.5))) +  ((xr * xr) * ((y - 1) * (y - 1))) -(xr * xr * yr * yr);
	while (y >= 0) {
		plot_e(xc,yc,x,y);
		y--; 
		if (d2 > 0)  
        { 
            dy = dy - (2 * xr * xr); 
            d2 = d2 + (xr * xr) - dy; 
        } 
        else 
        { 
            x++; 
            dx = dx + (2 * yr * yr); 
            dy = dy - (2 * xr * xr); 
            d2 = d2 + dx - dy + (xr * xr); 
        } 
	}

}
void ellip_circle(){
	int xc = 100, xr = 40, yc = 200, yr = 30;
	ellipseMidpoint(xc,yc,xr,yr);
	glFlush();
}
void circle(){
	int xc = 100,yc = 200,r = 50;
	int x,y,p;
	x=0;
	y=r;
	plot_c(xc,yc,x,y);
	p=1-r;
	while(x<y){
		x++;
		if(p<=0){
			p=p+(2*x)+1;
		}else{
			
			y--;
			p = p+(2*x)+1-(2*y);
		}
		plot_c(xc,yc,x,y);
	} 
}
void drawCharacter (void)
{
GLubyte text[4] = {'G','L','U','T'};
glColor3f (1.0, 0.0, 0.0);
glRasterPos2i( 40, 40);
for( int n = 0; n < 4 ; n++)
glutBitmapCharacter(GLUT_BITMAP_9_BY_15,text[n]);
}
void line_mouse(){
	X1 = Y1 = X2 = Y2 = 0;
}
void line(int x1, int y1, int x2, int y2)
{
 glBegin(GL_LINES);
 glVertex2i(x1, y1);
 glVertex2i(x2, y2);
glEnd();
}
void myMotion (GLint x, GLint y)
{
y = 600 - y;
glColor3f (1.0, 0.0, 0.0);
putPixel(x, y);
glFlush ( );
}
void myPassiveMotion (GLint x, GLint y)
{
y = 600 - y;
glColor3f (0.0, 0.0, 1.0);
X1 = X2; Y1 = Y2; X2 = x; Y2 = y;
line( X1, Y1, X2, Y2);
glFlush ( );
}