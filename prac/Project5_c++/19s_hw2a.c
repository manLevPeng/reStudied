#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct  Node* next;
};
int main(void)
{
	int i;
	struct Node* pStart = NULL;			//첫 번째 노드 포인터
	struct Node* pEnd = NULL;			//마지막 노드 포인터
	struct Node* Current;				//새로 추가할 노드 포인터
	
	for (i = 1; i <= 5; i++) {			//노드 생성
		Current = (struct  Node*)malloc(sizeof(struct Node));
		Current->data = i;
		Current->next = NULL;

		if (pStart == NULL)				//첫 번째 노드
			pStart = pEnd = Current;
		else							//노드 추가
		{
			pEnd->next = Current;
			pEnd = Current;
		}
		Current = pStart;
	}
		while (Current != NULL)
		{
			printf("%d\n",Current->data);
			Current = Current->next;
		}
	
	return 0;
}