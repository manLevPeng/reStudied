#include<stdio.h>
int main(void)
{
	int a, b, c; 
	printf("정수를 입력하시오 : ");
	scanf("%d", &a);

	printf("실수를 입력하시오 : ");
	scanf("%d", &b);

	printf("실수를 입력하시오 : ");
	scanf("%d", &c);
	
	int sum = a + b + c, avg = sum / 3;
	printf("합은 %d이고 평균은 %d입니다",sum,avg);

	return 0;
}