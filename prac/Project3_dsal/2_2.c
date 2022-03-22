//구조체 배열
#include<stdio.h>
#define VMAX 21
typedef struct {											//신체검사 데이터형
	char name[10];
	int height;
	double sight;
}PhysCheck;
double avg_height(const PhysCheck dat[], int n)				//키의 평균값 구하기
{
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += dat[i].height;
	return sum / n;
}
void dist_sight(const PhysCheck dat[], int n, int dist[])	//시력분포 구하기
{
	int i;
	for (i = 0; i < VMAX; i++)
		dist[i] = 0;
	for (i = 0; i < n; i++)
		if (dat[i].sight >= 0.0 && dat[i].sight <= VMAX / 10.0)
			dist[(int)(dat[i].sight * 10)]++;
}
int main(void) 
{
	PhysCheck x[] = {
		{"강군",182,1.3},{"나양",163,1.1},{"김씨",170,0.8},{"박가",168,0.2}
	};
	int nx = sizeof(x) / sizeof(x[0]);						//사람 수
	int vdist[VMAX];										//시력 분포
	
	puts("~~~~~~신체검사표~~~~~~");
	puts("이름      키      시력");
	puts("......................");

	for (int i = 0; i < nx; i++)
		printf("%-9.18s%4d%8.1f\n", x[i].name, x[i].height, x[i].sight);
	printf("\n평균키 : %5.1f cm\n", avg_height(x, nx));
	dist_sight(x, nx, vdist);
	printf("\n시력 분포\n");
	for (int i = 0; i < VMAX; i++)
		printf("%3.1f ~ : %2d명\n", i / 10.0, vdist[i]);

	return 0;
}