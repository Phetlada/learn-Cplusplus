#include <iostream>

using namespace std;

class Circle
{
public:
    int r;
public:	
    Circle(int);
	Circle(float);
	Circle(int,int);
};
Circle::Circle(int a)
{
	cout <<"1";
}
Circle::Circle(float a)
{
    cout <<"2";
}
Circle::Circle(int a, int b)
{
    cout <<"3";
}
int main()
{
	float a = 6;
    Circle c1(2,6);
    return 0;
}