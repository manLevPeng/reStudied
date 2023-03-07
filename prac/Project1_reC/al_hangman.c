#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int IsThere(char* Answer, char* myword, char key)
{
    for (int i = 0; Answer[i] != '\0'; i++)             //알고리즘 1: 순차검색
        if (Answer[i] == key)  myword[i] = key;

    if (strcmp(Answer, myword) == 0)    return 1;       //정답을 모두 맞췄는지 검사
    else                                return 0;
}
int IsThere2(char* Answer, char* myword, char key, int low, int high)      //알고리즘 2: 이분검색
{
    int mid; 
    if(low>high)    return 0;             
    else{
        mid=(low+high)/2;
        if(Answer[mid] == key)  myword[mid] = key;
        else { IsThere2(Answer, myword, key, low, mid-1); IsThere2(Answer, myword, key, mid+1, high);};
    }
    if (strcmp(Answer, myword) == 0)    return 1;       //정답을 모두 맞췄는지 검사
    else                                return 0;
}
int selectWord(int dsize)
{
    int c = rand() % dsize;		                        //dic[c]의 단어가 answer word
    return c;
}
int main(void) 
{	
    char* dic[] = { "algorithm", "summer", "spring", "error", "bug", "compose", "today", "tuesday", "university"};
    int dicSize = sizeof(dic) / sizeof(char*);
	srand((unsigned)time(NULL));			         //난수 발생을 위한 시드 설정
	
    char* Aword = dic[selectWord(dicSize)];          //dic에서 랜덤으로 정답 단어 선택
    int len = strlen(Aword);                         //정답 단어의 길이
    
    int i;
    char* Pword = (char*)malloc(len + 1);            //화면에 나타날 문자 배열
    for (i = 0; i < len; i++)   Pword[i] = '_';      //화면에 나타날 단어 빈칸으로 초기화
    Pword[len] = '\0';

    int try = 0;                                     //시도횟수
    char k;                                          //시도할 문자
    printf("~~ 행맨 게임 s t a r t ! ~~");
    while (1) {
        printf("\n맞출단어 : %s  ", Pword);
        printf("    빈칸에 들어갈 문자 : ");  k=getchar();               //문자입력
        try++;                                      //시도 회수 카운트
        if (IsThere(Aword, Pword, k) == 1) break;   //문자가 단어 안에 있는지 확인 : 알고리즘 1
        //if (IsThere(Aword, Pword, k, 0, len) == 1) break;   문자가 단어 안에 있는지 확인 : 알고리즘 2
    }
    printf("\n%d 번 만에 \"%s\"를 맞추었습니다.\n", try, Pword);
 
    return 0;
}
