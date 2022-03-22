#include<stdio.h>
void func()
{
	int cnt1 = 0;
	static int cnt2 = 0;
	cnt1++;	printf("cnt1 = %d\n", cnt1);		//변수 cnt1은 함수 func()가 호출 될 때마다 생성되고, 초기화되고, 함수가 끝날때 사라짐
	cnt2++;	printf("cnt2 = %d\n", cnt2);		//static 변수 cnt2는 한번 생성되고 초기화ㅣ되어 main이 끝날때까지 사라지지 않음
}
int main(void)
{
	func();
	func();
	func();
}