#include<stdio.h>
int main(void)
{
	printf("if(0)의 결과 : ");
	if (0)		printf("0은 참이다");
	else		printf("0은 거짓이다");

	printf("\nif(0.0)의 결과 : ");
	if (0.0)	printf("0.0은 참이다");
	else		printf("0.0은 거짓이다");

	printf("\nif(0.1)의 결과 : ");
	if (0.1)	printf("0.1은 참이다");
	else		printf("0.1은 거짓이다");

	printf("\nif(1)의 결과 : ");
	if (1)		printf("1은 참이다");
	else		printf("1은 거짓이다");

	printf("\nif(245)의 결과 : ");
	if (245)		printf("245은 참이다");
	else			printf("245은 거짓이다");

	printf("\nif('c')의 결과 : ");
	if ('c')		printf("'c'은 참이다");
	else			printf("'c'은 거짓이다");
}