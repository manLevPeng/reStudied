//B835009 고예령 컴퓨터공학과 4학년
#include<iostream>
#include<stack>
using namespace std;
const int MAXSIZE = 100;
bool maze[MAXSIZE + 2][MAXSIZE + 2] = { 0 };
bool mark[MAXSIZE + 1][MAXSIZE + 1] = { 0 };
enum directions { N, NE, E, SE, S, SW, W, NW };
struct offsets {
	int a, b;
} move[8] = { -1,0,	-1,1,	0,1,	1,1,	1,0,	1,-1,	0,-1,	-1,-1 };
struct Items {
	Items(int xx = 0, int yy = 0, int dd = 0) :x(xx), y(yy), dir(dd) {}
	int x, y, dir;
};

template<class T>
ostream& operator<<(ostream& os, stack<T>& s) {		//스택의 내용을 역순으로 출력
	stack<T> p;
	while (!s.empty()) {							//s->p 에 저장 (순서 바꾸기 위함)
		p.push(s.top());
		s.pop();
	}							
	while (!p.empty()) {
		os << " -> " << p.top();
		p.pop();
	}
	return os;
}
ostream& operator<<(ostream& os, Items& item) {
	static int count = 0;	
	os << "(" << item.x << ", " << item.y << "(";
	count++;
	if ((count % 5) == 0)	os << endl;			//5items 출력시마다 줄 바꾸기
	return os;
}
void Path(const int m, const int p)
{
	mark[1][1] = 1;								//(1,1)에서 시작
	stack<Items> stack;							//C++ STD stack
	Items temp(1, 1, E);
	stack.push(temp);							//스택에 (1,1,E) 먼저 push
	while (!stack.empty()) {					//스택이 빌 때까지
		temp = stack.top();	stack.pop();		//unstack
		int i = temp.x;	int j = temp.y; int d = temp.dir;
		while (d<8){							//move (i,j)->(g,h)
			int g = i + move[d].a; int h = j + move[d].b;
			if ((g == m) && (h == p))			//출구 (g,h)에 도착
			{		
				cout << stack;
				temp.x = i; temp.y = j;	cout << " -> " << temp;
				temp.x = m; temp.y = p; cout << " -> " << temp << endl;
				return;
			}
			if ((!maze[g][h]) && (!mark[g][h])) {	//막혀있지 않은, 방문한 적 없는 방향
				mark[g][h] = 1;						//표시
				temp.x = i; temp.y = j; temp.dir = d + 1;
				stack.push(temp);
				i = g; j = h; d = N;
			}
			else d++;								//다른 방향으로
		}
	}
	cout << "No path in maze" << endl;
}
void getdata(istream& is, int& m, int& p)	//자료파일을 읽어들여 maze에 저장함
{
	is >> m >> p;
	for (int i = 0; i < m + 2; i++) {		//왼쪽 벽, 오른쪽 벽 작성
		maze[0][i] = 1; maze[i][p + 1] = 1;
	}
	for (int j = 0; j <= p; j++) {			//위쪽 벽, 아래쪽 벽 작성
		maze[0][j] = 1; maze[m + 1][j] = 1;
	}
	for (int i = 1; i <= m; i++)			//자료를 읽어들인다
		for (int j = 1; j <= p; j++)
			is >> maze[i][j];
}