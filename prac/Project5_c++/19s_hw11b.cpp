#include<iostream>
using namespace std;
template<typename T>
class CPoint
{
public:
	CPoint(T a, T b) :x(a), y(b) {}
	void Move(T a, T b) { x += a; y += b; }
	void Print() { cout << "(" << x << ", " << y << ")" << endl; }
private:
	T x, y;
};
int main(void)
{
	CPoint<int> P1(1, 2);
	CPoint<double> P2(1.1, 2.2);
	P1.Print();	P2.Print();

	return 0;
}