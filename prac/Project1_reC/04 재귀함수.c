//재귀함수 이용한 n!
#include<stdio.h>

int repac(int n)	//재귀 팩토리얼
{
	if (n <= 0)	return 1;
	else		return n * repac(n - 1);
}
int replus(int n)	//재귀 1+...+n
{
	if (n == 0)	return 0;
	else		return n + replus(n - 1);
}
int remul(int m, int n)	//재귀 n*m
{
	if (m == 0)	return 0;
	else		return remul(n,m - 1)+n;
}
int rediv(int m, int n)	//재귀 n/m
{
	if (m == 0)	return 0;
	else		return remul(n, m - 1) + n;
}
int main(void) {
	int x,y;
	printf("정수를 입력하시오 : ");	scanf("%d", &x);
	printf("%d! = %d\n", x, repac(x));
	printf("1 +...+ %d = %d\n", x, replus(x));
	printf("정수를 입력하시오 : ");	scanf("%d", &y);
	printf("%d X %d = %d\n", x, y, remul(x,y));
	printf("%d / %d = %d\n", x, y, rediv(x,y));
	
	return 0;
}