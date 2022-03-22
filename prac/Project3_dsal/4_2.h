#ifndef ___IntQueue
#define ___IntQueue

typedef struct {
	int max;								// 큐의 용량
	int num;								// 현재 요소 개수
	int front;	
	int rear;	
	int *que;								// 큐의 첫 요소에 대한 포인터
} IntQueue;

int Initialize(IntQueue *q, int max);		//큐 초기화

int Enque(IntQueue *q, int x);				//큐에 데이터 인큐
int Deque(IntQueue *q, int *x);				//큐에서 데이터를 디큐
int Peek(const IntQueue *q, int *x);		//큐에서 데이터를 피크 : 맨 앞의(꺼낼)데이터 엿보기

void Clear(IntQueue *q);					//모든 데이터 삭제

int Capacity(const IntQueue *q);			//큐의 최대 용량
int Size(const IntQueue *q);				//큐의 데이터 갯수

int IsEmpty(const IntQueue *q);				//큐가 비어 있는지 확인
int IsFull(const IntQueue *q);				//큐가 가득 찼는지 확인

int Search(const IntQueue *q, int x);		//큐에서 검색
void Print(const IntQueue *q);				//큐의 모든 데이터 출력

void Terminate(IntQueue *q);				//큐 종료
#endif