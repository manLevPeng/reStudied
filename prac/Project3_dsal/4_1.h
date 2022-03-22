#ifndef ___IntStack
#define ___IntStack

typedef struct {						//스택을 구현하는 구조체
	int max;							//스택 용량
	int ptr;							//스택 포인터 : 스택에 쌓인 데이터의 개수
	int* stk;							//스택의 첫 요소에 대한 포인터
}IntStack;

int Initialize(IntStack* s, int max);	//스택 초기화
int Push(IntStack* s, int x);			//스택에 데이터 푸시
int Pop(IntStack* s, int* x);			//스택에서 데이터를 팝
int Peek(IntStack* s, int* x);			//스택에서 데이터를 피크 : 스택 꼭대기의 데이터 엿보기

void clear(IntStack* s);				//스택 비우기

int Capacity(const IntStack* s);		//스택의 최대용량
int Size(const IntStack* s);			//스택의 데이터 갯수

int IsEmpty(const IntStack* s);			//스택이 비어있는지 확인
int IsFull(const IntStack* s);			//스택이 가득 찼는지 확인

int Search(const IntStack* s, int x);	//스택에서 검색
int Print(const IntStack* s);			//스택의 모든 데이터 출력

void Terminate(IntStack* s);			//스택 종료

#endif