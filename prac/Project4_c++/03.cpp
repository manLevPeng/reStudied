#include<iostream>
using namespace std;
class Point
{
public:
	void Init(int x, int y)
	{
		xpos = x;	ypos = y;
	}
	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
private:
	int xpos, ypos;
};
class Circle			//Point 클래스 기반으로 원을 의미하는 클래스
{
public:
	void Init(int x, int y, int r)
	{
		rad = r;
		center.Init(x, y);
	}
	void ShowRingInfo()
	{
		cout << "radius : " << rad << endl;
		center.ShowPointInfo();
	}
private:
	int rad;			//반지름
	Point center;		//원의 중심
};
class Ring				//Circle 클래스 기반으로 두 개의 원을 표현
{
public:
	void Init(int inX, int inY, int inR, int outX, int outY, int outR)
	{
		inCircle.Init(inX, inY, inR);
		outCircle.Init(outX, outY, outR);
	}
	void ShowRingInfo()
	{
		cout << "Inner Circle Info..." << endl;
		inCircle.ShowRingInfo();
		cout << "Outter Circle Info..." << endl;
		outCircle.ShowRingInfo();
	}
private:
	Circle inCircle;
	Circle outCircle;
};

int main(void)
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}
