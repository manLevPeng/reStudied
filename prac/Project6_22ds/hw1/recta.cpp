//B835009 고예령 컴퓨터공학과 4학년
#include<iostream>
#include"recta.h"
using namespace std;

Rectangle::Rectangle(int x=0, int y=0, int h=0, int w=0):xLow(x),yLow(y),height(h),width(w){}
void Rectangle::Print()
{
	cout << "Position : " << xLow << " " << yLow << "; Height = " << height << " Width = " << width << endl;
}
bool Rectangle::SmallerThan(Rectangle& s) {
	if (height * width < s.height * s.width)	return true;
	else										return false;	
}
bool Rectangle::EqualTo(Rectangle& s) {
	if (height * width == s.height * s.width)	return true;
	else										return false;
}
int Rectangle::GetHeight()	{ return height; }
int Rectangle::GetWidth()	{ return width; }