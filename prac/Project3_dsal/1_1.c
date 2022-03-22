#include<stdio.h>
int max3(int a,int b, int c);	//세 정수 값을 입력받고 최댓값 구하기
int mid3(int a, int b, int c);	//세 정수 값을 입력받고 중앙값 구하기
int main(void)
{
	int a, b, c;
	printf("정수를 입력하시오 : ");	scanf("%d", &a);
	printf("정수를 입력하시오 : ");	scanf("%d", &b);
	printf("정수를 입력하시오 : ");	scanf("%d", &c);
			
	printf("\n최댓값 : %d", max3(a,b,c));
	printf("\n중앙값 : %d", mid3(a, b, c));
}
int max3(int a, int b, int c)
{
	int max = a;
	if (b > max)	max = b;
	if (c > max)	max = c;

	return max;
}
int mid3(int a, int b, int c)
{
	int mid;
	if (a >= b)
		if (b >= c)			mid = b;
		else if (a >= c)	mid = c;
		else				mid = a;
	else if (a > c)			mid = a;
	else if (b > c)			mid = c;
	else					mid = b;

	return mid;
}