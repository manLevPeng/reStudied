#include<iostream>
#include<cstring>
using namespace std;
class Person {
public:
	void Print()
	{
		cout << "name : " << name << endl << "height : " << height << endl << "weight : " << weight << endl;
	}
	void Change(int h, int w)
	{
		height = h, weight = w;
	}
	Person(const char *n, int h, int w) :height(h), weight(w)
	{
		int len = strlen(n) + 1;
		name = new char[len];
		strcpy(name, n);		//for (int i = 0; i < len; i++)	name[i] = n[i];
	}
private:
	char *name;
	int height;
	int weight;
};

int main(void)
{
	Person P1("Kim Byung-Gi", 180, 70);
	Person P2("Park Hye-young", 160, 50);
	P1.Print();	P2.Print();
	P1.Change(185, 75);
	P1.Print();

	return 0;
}