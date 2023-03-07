//B835009 고예령 컴퓨터공학과 4학년
#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle
{
public:
	Rectangle(int, int, int, int);	//constructor
	void Print();
	bool SmallerThan(Rectangle&);	//면적이 작은가
	bool EqualTo(Rectangle&);		//면적이 같은가
	int GetHeight();
	int GetWidth();
private:
	int xLow, yLow, height, width;
};
#endif // !RECTANGLE_H
