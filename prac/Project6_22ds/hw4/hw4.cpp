//B835009 고예령 컴퓨터공학과 4학년
#include <iostream>
#include "post.h"
using namespace std;
void PostFix(Expression);
int main(void)
{
    char linebuf[MAXLEN];
    while (cin.getline(linebuf, MAXLEN)) {      //getline은 뒤에 널문자 추가
        Expression e(linebuf, true);            //줄버퍼 이용해 Expression 만듦. ture->infix식 의미 
        try { PostFix(e); }
        catch (char const* msg) {
            cerr << "Exception: " << msg << endl; 
        }
    }
}
