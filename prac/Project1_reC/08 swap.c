#include<stdio.h>
void myswap(int *x, int *y)
{
	int temp;
	temp = *x; *x = *y; *y = temp;
}

int main(void)
{
	int a = 10, b = 20;
	printf("바꾸기 전 : a = %d, b = %d\n", a, b);
	myswap(&a, &b);
	printf("바꾼 후   : a = %d, b = %d\n", a, b);

}