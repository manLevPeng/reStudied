#include<iostream>
using namespace std;
void update(int val1, int &val2)
{
	val1 += val1;
	val2 += val2;
}
int main(void)
{
	int a = 1, b = 1;
	for (int i = 0; i < 5; i++)
		update(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}