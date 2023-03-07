#include<iostream>
#include<stack>
#include "post.h"
using namespace std;

Token::Token() { }
Token::Token(char c) :len(1), type(c) 
{    str = new char[1];    str[0] = c;  } //디폴트 타입 = c 자기자신
Token::Token(char c, char c2, int ty) :len(2), type(ty) 
{    str = new char[2];    str[0] = c;    str[1] = c2;  }
Token::Token(char* arr, int l) :type(ID), len(l) 
{   
    str = new char[len + 1];
    for (int i = 0; i < len; i++)
        str[i] = arr[i];
    str[len] = '\0';
}
Token::Token(float v) :val(v), type(NUM) { }

bool Token::IsOperand()        { return type == ID || type == NUM; }    //피연산자인가
bool Token::operator==(char b) { return (len == 1 && str[0] == b); }    //문자길이가 1이면서 같은 문자
bool Token::operator!=(char b) { return (len != 1 || str[0] != b); }    //문자길이가 1이 아니거나 같은 문자가 아닐 때

ostream& operator<<(ostream& os, Token t)
{
    if (t.type == NUM)                  os << t.val;
    else
        for (int i = 0; i < t.len; i++) os << t.str[i];
    os << " ";
    return os;
}
bool IsAlpha(char c) { return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'; }
bool IsDigit(char c) { return c >= '0' && c <= '9'; }

bool GetID(Expression& e, Token& tok) 
{
    char c = e.buf[e.pos];
    if (!IsAlpha(c)) return false;                //알파벳이 아니면 거짓
    int pos_start = e.pos;    e.pos++;
    while (IsAlpha(c = e.buf[e.pos]) || IsDigit(c)) e.pos++;
    int idlen = e.pos - pos_start;
    tok = Token(e.buf + pos_start, idlen);
    return true;
}
bool GetNUM(Expression& e, Token& tok)
{   
    char c; 
    if (!IsDigit(c = e.buf[e.pos])) return false;   //숫자가 아니면 거짓
    float val = c - '0';
    while (IsDigit(c = e.buf[++e.pos])) {            
        val = val * 10 + c - '0';
    }
    if ((c = e.buf[e.pos]) == '.') {			//소수점 이하 처리
        e.pos++;
        while (IsDigit(c = e.buf[++e.pos])) {		
            val = val + (c - '0') / 10;									
        }
    }
    tok = Token(val);
    return true;
}
void SkipBlanks(Expression& e)                    //공백 넘어가기
{
    char c;
    while (e.pos < e.len && ((c = e.buf[e.pos]) == ' ' || c == '\t'))
        e.pos++;
}
bool TwoCharOp(Expression& e, Token& tok)       //7가지 2자 토큰들(<=, >=, ==, !=, &&, ||, -u)처리
{
    if (e.pos >= e.len - 1)  return false;      //2자 이상 남아있어야 함
    char c = e.buf[e.pos]; 
    char c2 = e.buf[e.pos + 1];
    int op;     //LE GE EQ NE AND OR UMINUS
    if (c == '<' && c2 == '=')          op = LE;
    else if (c == '>' && c2 == '=')     op = GE;
    else if (c == '=' && c2 == '=')     op = EQ;
    else if (c == '!' && c2 == '=')     op = NE;
    else if (c == '&' && c2 == '&')     op = AND;
    else if (c == '|' && c2 == '|')     op = OR;
    else if (c == '~' && c2 == 'u')     op = UMINUS;
    else    return false;               //2자 토큰이 아니면 false
    tok = Token(c, c2, op);     
    e.pos += 2;
    return true;
}
bool OneCharOp(Expression& e, Token& tok)
{
    char c = e.buf[e.pos];
    if (c == '-' || c == '!' || c == '*' || c == '/' || c == '%' || c == '+' || c == '<' || c == '>' || c == '(' || c == ')' || c == '=')
    { tok = Token(c); e.pos++; return true; }
    return false;
}
Token NextToken(Expression& e)                          //다음 토큰을 반환
{
    static bool opndFound = false;                      //연산자 미발견(for infix 식)
    Token tok;
    SkipBlanks(e);
    if (e.pos == e.len) tok = Token('#');               //끝에 도달하면 토큰없음을 알리는 토큰
    else if (GetID(e, tok) || GetNUM(e, tok)) {}        //아무것도 안함
    else if (TwoCharOp(e, tok)) {}                      //아무것도 안함
    else if (OneCharOp(e, tok)) {                       //1자 토큰 여부 점검
        if (e.infix && tok.type == '-' && !opndFound)   //operand 후 아님
            tok = Token('-', 'u', UMINUS);              //-u(unary)로 바꾼다
    }
    else throw "Illegal Character Found";
    if (e.infix) opndFound = tok.IsOperand();
    return tok;
}
int icp(Token& t) //in-coming priority
{   /* t.type이 '('면 0, UMINUS나 '!'면 1, '*'나 '/'나 '%'면 2,
                '+'나 '-'면 3, '<' 나 '>'나 LE나 GE면 4, EQ나 NE면 5,
                AND면 6, OR이면 7, '='이면 9, '#'면 10을 return         */
    if (t.type == '(')                                                          return 0;
    else if (t.type == UMINUS || t.type == '!')                                 return 1;
    else if (t.type == '*' || t.type == '/' || t.type == '%')                   return 2;
    else if (t.type == '+' || t.type == '-')                                    return 3;
    else if (t.type == '<' || t.type == '>' || t.type == LE || t.type == GE)    return 4;
    else if (t.type == EQ || t.type == NE)                                      return 5;
    else if (t.type == AND)                                                     return 6;
    else if (t.type == OR)                                                      return 7;
    else if (t.type == '=')                                                     return 9;
    else if (t.type == '#')                                                     return 10;
}
int isp(Token& t) //in-stack priority
{    // '(' 경우 0, 기타의 경우 icp(t)를 return
    if (t.type == '(')  return 9;
    else                return icp(t);
}
void PostFix(Expression e)      //후위연산자로 변환
{
	stack<Token> stack;
	stack.push('#');
	for (Token x = NextToken(e); x != '#'; x = NextToken(e))
		if (x.IsOperand())
			cout << x;
		else if (x == ')'){
			for (; stack.top() != '('; stack.pop())
				cout << stack.top();
			stack.pop();
		}
		else{
			for (; isp(stack.top()) <= icp(x); stack.pop())
				cout << stack.top();
			stack.push(x);
		}
		while(stack.top() != '#') { cout << stack.top(); stack.pop();}
		stack.pop();

		cout << endl;
}