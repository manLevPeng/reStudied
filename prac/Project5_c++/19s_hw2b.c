#include<stdio.h>
#include<stdlib.h>

struct Node* pStart = NULL;							//리스트의 첫 번째 노드 포인터
struct Node* pEnd = NULL;							//리스트의 마지막 노드 포인터
struct Node
{
	int data;
	struct  Node* next;
};
void addrear(int val)								//새 Node를 만들고 data필트에 val을 저장하여 pStart로 시작하는 리스트 뒤에 추가한다
{
	struct Node* pNew;								//새로 추가할 노드 포인터
	pNew = (struct  Node*)malloc(sizeof(struct Node));
	pNew->data = val;
	pNew->next = NULL;

	if (pStart == NULL)								//첫 번째 노드
		pStart = pEnd = pNew;
	else											//노드 추가
	{
		pEnd->next = pNew;
		pEnd = pNew;
	}
}
void printlist(struct Node *Current)				//Current가 가리키는 리스트를 출력한다
{
	while (Current != NULL)
	{
		printf("%d\n", Current->data);
		Current = Current->next;
	}
}
int main(void)
{	
	for (int i = 1; i <= 5; i++)	addrear(i);		//새 노드를 만들어 리스트 뒤에 i를 추가
	printlist(pStart);
	return 0;
}