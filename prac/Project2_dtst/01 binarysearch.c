#include <stdio.h>
int BSearch(int ar[], int len, int t)
{
	int head = 0, tail = len - 1, mid;
	while (head <= tail) {
		mid = (head + tail) / 2;
		if (t == ar[mid])	return mid;
		else {
			if (t < ar[mid])		tail = mid - 1;
			else /*t > ar[mid]*/	head = mid + 1;
		}
	}
	return -1;
}
int ReBSearch(int ar[], int first, int last, int t)
{
	if (first > last)	return -1;
	
	int mid = (first + last) / 2;
	if (ar[mid] == t)		return mid;
	else if (ar[mid] < t)	return ReBSearch(ar, mid + 1, last, t);
	else  /* ar[mid] > t */	return ReBSearch(ar, first, mid-1 , t);
}
void prtSR(int idx)
{
	if (idx == -1)	printf("타겟 탐색 실패\n");
	else			printf("타겟 저장 인덱스 : %d\n", idx);
}
int main(void)
{
	int ar[] = { 1,3,5,7,9 }, idx;
	idx = BSearch(ar, sizeof(ar) / sizeof(int), 7);
	prtSR(idx);

	idx = BSearch(ar, sizeof(ar) / sizeof(int), 4);
	prtSR(idx);

	idx = ReBSearch(ar, 0, sizeof(ar) / sizeof(int)-1, 7);
	prtSR(idx);

	idx = ReBSearch(ar, 0, sizeof(ar) / sizeof(int)-1, 4);
	prtSR(idx);

	return 0;
}