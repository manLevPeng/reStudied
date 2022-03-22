#include<stdio.h>									//hw2b와 유사하지만 리스트의 앞에 새 노드를 추가하는 버전.
#include<stdlib.h>

struct Node* pStart = NULL;							//리스트의 첫 번째 노드 포인터
struct Node* pEnd = NULL;							//리스트의 마지막 노드 포인터
struct Node
{
	int data;
	struct  Node* next;
};
void addfront(int val)								//새 Node를 만들고 data필트에 val을 저장하여 리스트 앞에 추가한다
{
	struct Node* pNew;								//새로 추가할 노드 포인터
	pNew = (struct  Node*)malloc(sizeof(struct Node));
	pNew->data = val;
	pNew->next = NULL;

	if (pStart == NULL)								//첫 번째 노드
		pStart = pEnd = pNew;
	else											//노드 추가
	{
		pNew->next = pStart;						//새로 추가한 노드의 다음 노드가 기존의 첫번째 노드
		pStart = pNew;								//첫 번째 노드를 새로 만든 노드로 바꾼다
	}
}
void delete(int val)								//data필드값이 val인 Node를 1개 찾아 지운다
{
	if (pStart == NULL)	return;
	
	if (pStart->data == val) {
		struct Node* Current = pStart;
		pStart = pStart->next;
		free(Current);
		return;
	}

	struct Node* p = pStart;
	struct Node* q = p->next;

	while (q != NULL) {
		if (q->data == val) {
			p->next = q->next;
			free(q);
			break;
		}
		p = q;
		q = p->next;
	}
}
	/*
	빈 리스트의 경우 return
	첫 노드의 data가 val인 경우 
	기타 경우 : 현 노드를 p가 가리키고 그 뒤 노드를 q가 가리키도록 하고, 리스트를 쫓아감. p가 가리키는 노트에 val이 있으면 q->next=p->next; free(p);
				(마지막 노드가 free되는 경우 pEnd=q). 아니면 p, q가 앞으로 진행함
	*/

void printlist(struct Node* Current)				//Current가 가리키는 리스트를 출력한다
{
	while (Current != NULL)
	{
		printf("%d\n", Current->data);
		Current = Current->next;
	}
}
int main(void)
{
	for (int i = 1; i <= 5; i++)	addfront(i);		//새 노드를 만들어 리스트 뒤에 i를 추가
	printlist(pStart);
	printf("\n");
	delete(2); delete(5);
	printlist(pStart);

	return 0;
}