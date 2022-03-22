#include<stdio.h>
#include "09 power.h"

int main(void)
{
	int x, y;
	printf("x의 값을 입력하시오 : ");	scanf("%d", &x);
	printf("\ny의 값을 입력하시오 : ");	scanf("%d", &y);
	printf("\n%d의 %d 제곱값은 %f",x,y,power(x,y));

	return 0;
}