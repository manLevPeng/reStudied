#include<stdio.h>
#include "ArrayList.h"
int main(void)
{
	//1번 리스트 생성 및 초기화
	List list;
	int data;
	ListInit(&list);

	//1번 1부터 9까지 리스트에 저장
	for (int i = 1; i <= 9; i++)
		LInsert(&list, i);

	printf("현재 데이터의 수 : %d\n", LCount(&list));
	
	//2번 리스트에 저장된 값 순차 참조하여 값 합산, 출력
	int sum=0;

	if (LFirst(&list, &data)) {			//첫 번째 데이터 조회
		sum += data;
		printf("%d\n", sum);

		while (LNext(&list, &data)) {		//두 번째 이후의 데이터 조회
			sum += data;
			printf("%d\n", sum);
		}
	}
	printf("\n\n");

	//3번 2의 배수와 3의 배수 탐색하여 모두 삭제

	if (LFirst(&list, &data)) {
		if (data%2==0 || data % 3 == 0)	LRemove(&list);

		while (LNext(&list, &data))
			if (data%2==0 || data % 3 == 0)	LRemove(&list);
	}
	//남은 데이터 전체 출력
	printf("현재 데이터의 수 : %d\n", LCount(&list));

	if (LFirst(&list, &data)) {			
		printf("%d ", data);

		while(LNext(&list, &data))		
			printf("%d ", data);
	}
	printf("\n\n");

	return 0;
}