#include<iostream>						//vector클래스에 대해 sort알고리즘을 적용
#include<vector>
#include<algorithm>
using namespace std;
void PrintVecotr(vector<int> intV, const char *name)
{
	vector<int>::iterator iter;
	cout << ">> " << name << " : ";
	for (iter = intV.begin(); iter != intV.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}
int main(void)
{
	int i;
	vector<int> intV(5);

	cout << "5개의 정수 입력 : ";
	for (i = 0; i < 5; i++)
		cin >> intV[i];
	PrintVecotr(intV, "정렬 전");

	sort(intV.begin(), intV.end());	//모든 원소들에 대해 수행
	PrintVecotr(intV, "정렬 후");
	return 0;
}