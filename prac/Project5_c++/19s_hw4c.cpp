#include<iostream>
using namespace std;
int& GetArray(int* ary, int index)					//참조 반환
{
	return ary[index];
}
void SumMul(int* ary, int num, int &s, int &m)		//(정수 배열의 주소, 배열의 크기, 배열의 모든 성분의 계산된 합을 저장하는 call-by-reference 인수, 곱을 저장하는 인수)
{										
	s = 0; m = 1;									//s와 m 초기화
	for (int i = 0; i < num; i++) {					//배열 성분들의 합과 곱을 계산하여 그 값을 3번째 인수 s와 네번째 인수 m으로 반환하는 프로그램
		s += ary[i];
		m *= ary[i];
	}					
		
}
int main(void)
{
	int ary[5], sum, mul;

	for (int i = 0; i < 5; i++)
		GetArray(ary, i) = i + 1;
	SumMul(ary, 5, sum, mul);
	cout << "sum = " << sum << endl << "mul = " << mul << endl;
	
	return 0;
}