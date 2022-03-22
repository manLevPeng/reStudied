#include<iostream>
using namespace std;
class CPoint {
private:
	int x;
	int y;
public:
	CPoint(int a, int b) { x = a; y = b; cout << "constructor1 : "; Print(); }
	CPoint(int a)		 { x = a; y = 0; cout << "constructor2 : "; Print(); }
	void Print() { cout << "(" << x << ", " << y << ")" << endl; }
};
int main(void)
{
	CPoint P1(3, 4);				//생성자 1
	CPoint P2(5);					//생성자2
	CPoint P3 = 6;					//CPoint(6)으로 변환->생성자2

	P1.Print(); P2.Print(); P3.Print();
}