#include<iostream>
#include<math.h>
using namespace std;
#include<GL\glut.h>
void lineBres(int x1,int y1,int x2,int y2);
void lineSimple(int x1,int y1,int x2,int y2);
void lineDDA(int x1,int y1,int x2,int y2);
void putPixel(int x,int y);
float round(float a);
void main(){
	lineSimple(16,10,24,22);

}


void lineSimple(int x1,int y1,int x2,int y2){
	int  dx = x2-x1;
	int  dy = y2-y1;
	float m = (float) dy/dx;
	
	float x = x1;
	float y = y1;

	if(fabs(m)<1){	
	for(int k = 0;k < dx;k++){
		float b = y1-m*x1;
		x = x+1;
		y=m*x+b;
		int yy = round(y);
		putPixel(x,yy);
		cout << "x ="<< x<<"Y = "<< yy <<endl; 
		} 
	}else{
		float b = x1-(y1/m);
		for(int k = 0;k < dy;k++){
		y = y+1;
		x = (y/m)+b;
		int xx = round(x);
		putPixel(xx,y);
		cout << "x ="<< xx<<"Y = "<< y <<endl; 
	} 

	}


}
float round(float a){
	float b = (int)(a+0.5);
	return b;
}
void putPixel(int x,int y){
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
}