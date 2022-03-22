//막대 from에 쌓여있는 n개의 원판을 막대 mid를 사용해 막대 to로 옮긴다.
#include<stdio.h>
void hanoi(int n, char from, char mid, char to)
{
	if (n == 1)		printf("판 1을 %c에서 %c로 옮긴다\n", from, to);	//from에서 to로 원판을 옮긴다
	else {
		hanoi(n - 1, from, to, mid);									//from의 맨 밑 원반을 제외한 나머지 원판을 mid로 옮긴다
		printf("판 %d을 %c에서 %c로 옮긴다\n", n, from, to);			//from에 남은 한 개의 원판을 to로 옮긴다
		hanoi(n - 1, mid, from, to);									//mid의 원판들을 to로 옮긴다			
	}
}
int main(void)
{
	int n;
	printf("몇개의 원판이 있습니까? : ");
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
}