#include<iostream>
using namespace std;
class Complex
{
public:
	Complex(float r = 0.0, float i = 0.0) : re(r), im(i) {}
	Complex operator+(Complex& right) {
		Complex tmp;
		tmp.re = re + right.re;
		tmp.im = im + right.im;
		return tmp;
	}
	Complex operator-(Complex& right) {
		Complex tmp;
		tmp.re = re - right.re;
		tmp.im = im - right.im;
		return tmp;
	}
	Complex operator*(Complex& right) {
		Complex tmp;
		tmp.re = re * right.re;
		tmp.im = im * right.im;
		return tmp;
	}
	Complex operator/(Complex& right) {
		Complex tmp;
		tmp.re = re / right.re;
		tmp.im = im / right.im;
		return tmp;
	}
	void Print() { 
		if(im>0)
			cout << re << " + " << im << "i" << endl; 
		else
			cout << re << " - " << -im << "i" << endl;
	}
private:
	float re, im;
};
int main(void)
{
	Complex com1(1.0, 2.0), com2(3.0, 4.0), com3, com4, com5, com6;
	com1.Print();	com2.Print();
	com3 = com1 + com2;		com3.Print();
	com4 = com1 - com2;		com4.Print();
	com5 = com1 * com2;		com5.Print();
	com6 = com1 / com2;		com6.Print();
}

