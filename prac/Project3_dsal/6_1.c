//sorting
#include<stdio.h>
#include<stdlib.h>
#define swap(type, x, y) do {type t=x;x=y;y=t;} while(0)
void Bubble(int a[], int n)					//끝->앞쪽으로 스캔하면서 이웃하는 두 요소를 비교하고 교환하는 버블 정렬
{
	for (int i = 0; i < n - 1; i++) {
		int exchg = 0;						//패스에서 교환을 시도한 횟수
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);	//패스
				exchg++;
			}
		if (exchg == 0)	break;				//교환이 수행되지 않았다면 정렬 멈춤
	}
}
void Selection(int a[], int n)				//단순 선택 정렬
{
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = 0; j < n - 1; j++)
			if (a[j] < a[i])	min = j;
		swap(int, a[i], a[min]);
	}
}
int main(void)
{
	int nx;
	int *x;								//배열의 첫 번째 요소에 대한 포인터
	printf("버블정렬합니다.\n요소 갯수를 입력하시오 : "); scanf("%d", &nx);
	x = calloc(nx, sizeof(int));		//요소 개수가 nx개인 int형 배열 생성
	
	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);	scanf("%d", &x[i]);
	}

	Bubble(x, nx);						//배열 x를 버블 정렬

	printf("오름차순으로 정렬했습니다.\n");
	for (int i = 0; i < nx; i++)
		printf("x[%d] : %d\n", i,x[i]);
	
	free(x);							//배열 해제
	return 0;

}