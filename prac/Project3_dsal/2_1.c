#include<stdio.h>
#include<stdlib.h>
int main(void)
{	
	//int형 객체를 동적으로 생성하고 해제
	int *x;
	x = calloc(1, sizeof(int));
	if (x == NULL)	puts("메모리 할당에 실패했습니다.");
	else
	{
		*x = 57;
		printf("*x = %d\n", *x);
		free(x);
	}

	//int형 배열을 동적으로 생성하고 해제
	int* a, na;
	printf("요소 갯수 : ");	scanf("%d", &na);
	a = calloc(na, sizeof(int));				//요소 갯수가 na개인 int형 배열 생성

	if (a == NULL)	puts("메모리 확보에 실패했습니다.");
	else
	{
		printf("%d개의 정수를 입력하시오 :\n", na);
		for (int i = 0; i < na; i++) {
			printf("a[%d] : ", i);	scanf("%d", &a[i]);
		}
		printf("각 요소의 값 : \n");
		for (int i = 0; i < na; i++)	printf("a[%d] : %d\n", i, a[i]);
		free(a);
	}

	return 0;
}