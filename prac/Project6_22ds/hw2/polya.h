//B835009 고예령 컴퓨터공학과 4학년
#pragma once
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include<iostream>
using namespace std;
struct Term								//다항식의 항을 (계수, 지수) 쌍으로 표현
{
	float coef;							//계수
	int exp;							//차수
};
class Polynomial
{
public:
	Polynomial();						//다항식 p(x)=0을 생성
	Polynomial operator+(Polynomial&);	//다항식의 합을 반환
	void NewTerm(const float, const int);
private:
	Term* termArray;					//0이 아닌 항의 배열
	int capacity;						//termArray의 크기. 1로 초기화
	int terms;							//저장된 항의 수. 0으로 초기화
	friend ostream& operator<<(ostream&, Polynomial&);
	friend istream& operator>>(istream&, Polynomial&);
};
#endif // !POLYNOMIAL_H
