//B835009 고예령 컴퓨터공학과 4학년
#include<iostream>
#include<fstream>
using namespace std;
void getdata(istream&, int&, int&);
void Path(int, int);

int main(int argc, char* argv[]) {
	int m, p;	//m x p maze
	if (argc == 1)
		cerr << "Usage: " << argv[0] << " maze_data_file\n";
	else {
		ifstream is(argv[1]);
		if (!is) { cerr << argv[1] << " dose not exist\n"; return 1; }
	cout << "For maze datafile [" << argv[1] << "]\n";
	getdata(is, m, p); is.close();
	Path(m, p);
	}
}
