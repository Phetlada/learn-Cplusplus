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
	//lineSimple(7,10,26,20);
	lineBres(2,14,24,26);

}

void lineBres(int x1,int y1,int x2,int y2){
	int  dx = x2-x1;
	int  dy = y2-y1;
	int num1 = 2*dy;
	int num2 = num1-(2*dx);
	int p = num1-dx;
	int x = x1; int y = y1;
	putPixel(x,y);
	for(int k = 0;k < dx;k++){
		if(p<0){
			x = x+1;
			putPixel(x,y);
			p = p+num1;
		cout << k << " . x ="<< x<<"Y = "<< y << "P = " << p <<endl;
		}else{
			x = x+1; 
			y = y+1;
			putPixel(x,y);
			p = p+num2;
		cout <<k << " . x ="<< x<<"Y = "<< y << "P = " << p <<endl; 
		}
	} 
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