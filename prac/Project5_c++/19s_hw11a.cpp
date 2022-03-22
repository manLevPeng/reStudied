#include<iostream>
using namespace std;
class CIntPoint
{
public:
	CIntPoint(int a, int b):x(a),y(b){}
	void Move(int a, int b) { x += a; y += b; }
	void Print(){ cout << "(" << x << ", " << y << ")" << endl; }
private:
	int x, y;
};
class CDoublePoint
{
public:
	CDoublePoint(double a, double b) :x(a), y(b) {}
	void Move(double a, double b) { x += a; y += b; }
	void Print() { cout << "(" << x << ", " << y << ")" << endl; }
private:
	double x, y;
};
int main(void)
{
	CIntPoint P1(1, 2);
	CDoublePoint P2(1.1, 2.2);
	P1.Print();	P2.Print();

	return 0;
}