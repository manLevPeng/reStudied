#include<stdio.h>
void vadd(int a[3], int b[3], int result[3])	//1번 array vector 더하기
{
	for (int i = 0; i < 3; i++)
		result[i] = a[i] + b[i];
}
int myatio(char strr[10000])	//2번 정수 문자열 입력받아 숫자 정수로
{
	int result=0, i=0; 
	for (;strr[i]!='\0'; i++)
		result = result * 10 + strr[i] - '0';

	return result;
}
void mystrcpy(char target[1000], char source[1000])		//3번 문자열 복사
{
	int i=0;
	for (; source[i] != 0; ++i) 
		target[i] = source[i];
	target[i] = 0;
}
int mystrlen(char t[100])	//4번 문자열 길이 count
{
	int i = 0;
	for (; t[i] != '\0'; i++);
	return i;
}
char mylast(char f[1000])		//5번 문자열의 끝문자 반환
{
	int i = 0;
	for (; f[i] != '\0'; i++);
	return f[i - 1];
}
void mystrcat(char ap[1000], char b[1000])		//6번 문자열을 합치는 strcat
{
	int i = 0;
	for (; ap[i] != '\0'; ++i);
	for (int j=0; b[j] != '\0'; ++i,++j)
		ap[i] = b[j];
	ap[i] = 0;
}
int mystrcmp(char a[1000], char b[1000])		//7번 문자열을 비교해 동일하면 0, 아니면 글자 차이 리턴하는 strcmp 
{
	int i = 0;
	for (; a[i] == b[i] && a[i] && b[i]; i++);
	return a[i] - b[i];
}
int main(void)
{
	int a[3] = { 1, 2, 3 }, b[] = { 3, 2, 1 }, c[3];
	vadd(a, b, c);	
	printf("%d %d %d\n", c[0], c[1], c[2]);		//1번
	printf("%d\n", myatio("123"));		//2번
	
	char ori[] = "원본복사완료", copy[20];
	mystrcpy(copy, ori);	//3번
	printf("copy = %s\n", copy);

	printf("\'rainbow\' 문자열의 길이 = %d\n", mystrlen("rainbow"));	//4번
	printf("\'rainbow\' 문자열의 끝문자 = %c\n", mylast("rainbow"));	//5번

	char x[10] = "rain", y[] = "bow";
	mystrcat(x,y);
	printf("\'rain\' + \'bow\' = %s\n", x);		//6번

	char *e = "cale", *f = "cale";
	printf("%d %d", mystrcmp(e, f), mystrcmp("e", "f"));		//7번

}