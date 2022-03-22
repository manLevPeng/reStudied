#include<stdio.h>
int main(void)
{
	char name[10]; int kor[10], eng[10], math[10], avg[10], total[10], in;
	
	printf("차례대로 이름, 국어 성적, 영어 성적, 수학 성적을 입력하시오");
	for (int i = 0;; i++) {
		printf("\n%d : ", i + 1);
		in = scanf("%s %d %d %d", name, &kor[i], &eng[i], &math[i]);
		if (in <= 0)	break;
		total[i] = (kor[i] + eng[i] + math[i]);
		avg[i] = total[i] / 3;

		printf("%s 총점 %d 평균 %d\n", name, total[i], avg[i]);
	}
}