#include<iostream>
using namespace std;
template<class T>
class CPoint
{
public:
	CPoint(T a, T b) :x(a), y(b) {}
	void Move(T a, T b) { x += a; y += b; }
	void Print() { cout << "(" << x << ", " << y << ")" << endl; }
	
	template <class T2>
	friend ostream& operator << (ostream&, CPoint<T2>);
private:
	T x, y;
};

template<class T>
ostream& operator<<(ostream& os, CPoint<T> pt)
{
	os << '(' << pt.x << ", " << pt.y << ')' << endl;
	return os;
}

int main(void)
{
	CPoint<int> P1(1, 2);
	CPoint<double> P2(1.1, 2.2);
	
	cout << P1 << P2;

	return 0;
}