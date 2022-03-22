#include<stdio.h>
#include<stdlib.h>
#include "3_2.h"
int Initialize(IntQueue* q, int max)
{
	q->num = q->front = q->rear = 0;
	if ((q->que = calloc(max, sizeof(int))) == NULL) {
		q->max = 0;						//배열 생성 실패
		return -1;
	}
	q->max = max;
	return 0;
}
int Enque(IntQueue* q, int x)
{
	if (q->num >= q->max)	return-1;	//큐가 가득 참
	else {
		q->num++;
		q->que[q->rear++] = x;
		if (q->rear == q->max)
			q->rear = 0;
		return 0;
	}
}
int Deque(IntQueue* q, int *x)
{
	if (q->num <= 0)	return-1;		//큐가 비어있음
	else {
		q->num--;
		*x = q->que[q->front++];
		if (q->front == q->max)
			q->front = 0;
		return 0;
	}
}
int Peek(const IntQueue* q, int *x)
{
	if (q->num <= 0)	return-1;		//큐가 비어있음
	*x = q->que[q->front];
	return 0;
}
void Clear(IntQueue* q)
{
	q->num = q->front = q->rear = 0;
}
int Capacity(const IntQueue* q)
{
	return q->max;
}
int Size(const IntQueue* q)
{
	return q->num;
}
int IsEmpty(const IntQueue* q)
{
	return q->num <= 0;
}
int IsFull(const IntQueue* q)
{
	return q->num >= q->max;
}
int Search(const IntQueue* q, int x)
{
	int idx;
	for (int i = 0; i < q->num; i++) {
		if (q->que[idx = (i + q->front) % q->max] == x)
			return idx;					//검색 성공
	}
	return -1;							//검색 실패
}
void Print(const IntQueue* q)
{
	for (int i = 0; i < q->num; i++) {
		printf("%d\n", q->que[(i + q->front) % q->max]);
	}
}
void Terminate(IntQueue* q)
{
	if (q->que != NULL)
		free(q->que);					//메모리 공간에 할당된 배열 해제
	q->max = q->num = q->front = q->rear = 0;
}