//B835009 고예령 컴퓨터공학과 4학년
#include<iostream>
#include"polyb.h"
using namespace std;
istream& operator>>(istream& is, Polynomial& p) {		//다항식의 항(계수, 지수) 쌍을 읽어들인다. 높은 차수의 항부터 저장
	int noofterms; float coef; int exp;
	is >> noofterms;
	for (int i = 0; i < noofterms; i++) {
		is >> coef >> exp;
		p.NewTerm(coef, exp);
	}
	return is;
}
ostream& operator<<(ostream& os, Polynomial& p) {
	for (int i = 0; i < p.terms; i++) {
		if (p.termArray[i].coef != 0 && p.termArray[i].coef != 1 && p.termArray[i].coef != -1)	//계수가 1,0,-1이면 계수 출력 생략
			os << p.termArray[i].coef;
		if (p.termArray[i].exp != 0 && p.termArray[i].exp != 1)									//차수가 1,0이 아니면 x^ 출력
			os << "x^";
		if (p.termArray[i].exp == 1)															//차수가 1이면 x 출력
			os << "x";
		if (p.termArray[i].exp != 0 && p.termArray[i].exp != 1)									//차수 출력		
			os << p.termArray[i].exp;

		if (i != p.terms - 1 && p.termArray[i + 1].coef >= 0)
			os << " +";
		else if (p.termArray[i + 1].coef == -1)
			os << " -";
		else if (p.termArray[i + 1].coef < -1)
			os << " ";
	}
	os << endl;
	return os;
}
Polynomial::Polynomial() :capacity(4), terms(0) {
	termArray = new Term[capacity];
}
void Polynomial::NewTerm(const float theCoeff, const int theExp) {	//다항식 뒤에 새로운 항을 추가하는 함수. 새로운 항을 termArray 끝에 추가.
	if (terms == capacity) {
		capacity *= 2;
		Term* temp = new Term[capacity];
		copy(termArray, termArray + terms, temp);
		delete[] termArray;
		termArray = temp;
	}
	termArray[terms].coef = theCoeff;
	termArray[terms++].exp = theExp;
}
Polynomial Polynomial::operator+(Polynomial& b)							//*this와 b를 더한 결과를 반환한다
{
	Polynomial c;
	int aPos = 0, bPos = 0;
	while ((aPos < terms) && (bPos < b.terms))
		if (termArray[aPos].exp == b.termArray[bPos].exp) {				//차수가 같으면
			float t = termArray[aPos].coef + b.termArray[bPos].coef;
			if (t)	c.NewTerm(t, termArray[aPos].exp);
			aPos++; bPos++;
		}
		else if (termArray[aPos].exp < b.termArray[bPos].exp) {
			c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}
		else {
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}
	for (; aPos < terms; aPos++)										//*this의 나머지 항들을 추가한다
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
	for (; bPos < b.terms; bPos++)										//b(x)의 나머지 항들을 추가한다
		c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
	return c;
}
Polynomial Polynomial::operator*(Polynomial& b)							//*this와 b의 곱의 결과를 반환한다
{
	Polynomial c;
	int aPos = 0, bPos = 0, idx = 0;
	for(; aPos < terms; aPos++)
		for (; bPos < terms; bPos++) {
			int tCoef = termArray[aPos].coef * b.termArray[bPos].coef;
			int tExp = termArray[aPos].exp + b.termArray[bPos].exp;
			for (int i = 0; i < c.terms; i++)
				if (c.termArray[i].exp == tExp)							//차수가 같으면
					idx = i; 
			if (idx == 0)												//차수가 같은 항이 없으면 새로 추가
				c.NewTerm(tCoef, tExp);							
			else														//차수가 같은 항이 있으면 서로 더한다
				c.termArray[idx].coef += tCoef; 
		}
	for (int i = 0; i < terms; i++)										//정렬
		for (int j = i + 1; j < terms; j++)
			if (termArray[i].exp < termArray[j].exp)
			{
				Term temp = termArray[i];
				termArray[i] = termArray[j];
				termArray[j] = temp;
			}
	return c;
}
//3x ^ 13 - 21x ^ 10 - 3x ^ 8
