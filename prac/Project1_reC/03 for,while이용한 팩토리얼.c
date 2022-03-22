#include<stdio.h>
int repac(int n)
	{
		if (n <= 0)	return 1;
		else		return n * repac(n - 1);
	} 
int main(void)
{
	//for문 이용한 구구단
	for (int i = 1; i <= 9; i++)
		printf("3 X %d = %d\n", i, 3 * i);

	printf("\n");

	//for문 이용한 n!
	int x, fpac=1;
	
	printf("정수를 입력하시오 : ");	scanf("%d", &x);
	for (int i = 1; i <= x; i++)
		fpac = fpac * i;
	printf("%d! = %d\n", x, fpac);

	printf("\n");

	//while문 이용한 n!
	int wpac=1, y=1;
	printf("정수를 입력하시오 : ");	scanf("%d", &x);
	while (y <= x) {
		wpac = wpac * y;
		y++;
	}
	printf("%d! = %d\n", x, wpac);


	printf("\n");
}