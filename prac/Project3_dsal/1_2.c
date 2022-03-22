#include<stdio.h>
void print_mul(void);	//곱셈표 출력
int main(void)
{
	print_mul();
}
void print_mul(void) 
{
	printf("~~~곱셈표~~~\n");
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++)
			printf("% 3d", i * j);
		printf("\n");
	}
}