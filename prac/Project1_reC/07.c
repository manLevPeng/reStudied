#include<stdio.h>
int main(void)
{
	int aa[3][2] = { 1,2,3,4,5,6 };
	int a[2], b[2], c[2], * cp;
	cp = c;
	a[1] = 1; *(b + 1) = 1; cp++; *cp = 1;
	printf("%d %d %d\n", a[1], b[1], c[1]);
	printf("%d %d\n", aa[1][2], *(aa[1]+2));
	printf("%d %d %d\n", aa[2][1], (*(aa + 2) + 1));
}