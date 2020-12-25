#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
#include<GL\glut.h>
float round(float a){
	float b = (int)(a+0.5);
	return b;
}
void main(){

	cout<< round(135.2345);
}