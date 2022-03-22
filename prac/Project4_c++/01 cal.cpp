#include<iostream>
using namespace std;
class Calculator
{
public:
	void Init();
	void ShowOpCount();
	float Add(float a, float b);	//덧셈
	float Min(float a, float b);	//뺄셈
	float Mul(float a, float b);	//곱셈
	float Div(float a, float b);	//나눗셈
	
private:
	int AddCount;
	int MinCount;
	int MulCount;
	int DivCount;
};
void Calculator::Init()
{
	AddCount = MinCount = MulCount = DivCount = 0;
}
void Calculator::ShowOpCount()
{
	cout << endl<<"덧셈 : " << AddCount << endl << "뺄셈 : " << MinCount << endl << "곱셈 : " << MulCount << endl << "나눗셈 : " << DivCount << endl;
}
float Calculator::Add(float a, float b)
{
	AddCount++;
	return a + b;
}
float Calculator::Min(float a, float b)
{
	MinCount++;
	return a - b;
}
float Calculator::Mul(float a, float b)
{
	MulCount++;
	return a * b;
}
float Calculator::Div(float a, float b)
{
	DivCount++;
	return a / b;
}

float main(void)
{
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "3.0 x 2.5 = " << cal.Mul(3.0, 2.5) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}