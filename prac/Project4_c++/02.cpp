#include<iostream>
#include<cstring>
using namespace std;
class Printer
{
public:
	void SetString(char* s);
	void Showstring();

private:
	char mystring[30];
};

void Printer::SetString(char* s)
{
	strcpy(mystring, s);
}

void Printer::Showstring()
{
	cout << mystring << endl;
}
int main(void)
{
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.Showstring();

	pnt.SetString("I love C++");
	pnt.Showstring();

	return 0;
}