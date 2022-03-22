//재귀
#include<stdio.h>
int gdc(int x, int y)		//유클리드 호제법에 의한 최대공약수 구하기
{
	if (y == 0)	return x;
	else		return gdc(y, x % y);
}
int main(void)
{
	int x, y;
	printf("두 정수의 최대공약수를 구합니다.\n두 정수를 입력하시오 : ");	scanf("%d %d", &x, &y);
	printf("최대공약수는 %d입니다.\n", gdc(x, y));
}