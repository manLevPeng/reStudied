#pragma once
#ifndef POST_H
#define POST_H          //1자 토큰 이외의 토큰에 대한 토큰 타입의 정의가 필요. 1자(연산자) 토큰의 토큰 타입->그 문자의 아스키코드
#define ID      257     //변수 이름
#define NUM     258     //숫자
#define EQ      259     //==
#define NE      260     //!=
#define GE      261     //>=
#define LE      262     //<=
#define AND     263     //&&
#define OR      264     //||
#define UMINUS  265     //-u(unary)
#define MAXLEN  80
#include<cstring>       //for strlen

struct Expression {
    char* buf;
    int pos;            //Expression 내의 현위치([0~len-1]사이의 수)
    int len;            //Expression의 buf가 가리키는 문자열의 길이
    bool infix;         //true for infix expression (- 처리 위해 필요)
    Expression(char* linebuf, bool inf = false) :buf(linebuf), pos(0), len(strlen(buf)), infix(inf) {}
};
struct Token {
    bool operator==(char);
    bool operator!=(char);
    Token();
    Token(char);                //1자 토큰 : (연산자)토큰 자체를 타입으로 취급
    Token(char, char, int);     //2자 토큰과 그 타입 : 예) <=과 LE
    Token(char*, int);          //ID토큰의 이름 및 길이
    Token(float);               //NUM토큰의 값 저장
    bool IsOperand();           //토큰 타입이 ID나 NUM이면 true
    int type;                   //1자 토큰은 그 자체값. 그 외는 미리 정의된 값.
    union {
        struct { int len; char* str; };    //토큰 길이, 토큰값
        float val;                         //단, 타입이 NUM인 경우 그 값을 저장
    };
};
#endif POST_H