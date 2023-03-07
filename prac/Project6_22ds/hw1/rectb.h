//B835009 고예령 컴퓨터공학과 4학년
#ifndef RECTANGLE_H
#define RECTANGLE_H
using namespace std;
class Rectangle
{
public:
	Rectangle(int, int, int, int);	//constructor
	bool operator<(Rectangle&);			//면적이 작은가
	bool operator==(Rectangle&);		//면적이 같은가
	int GetHeight();
	int GetWidth();
	friend ostream& operator<<(ostream&, Rectangle&);
private:
	int xLow, yLow, height, width;
};
#endif // !RECTANGLE_H
