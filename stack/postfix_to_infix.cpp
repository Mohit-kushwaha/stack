#include<iostream>
#include<stack>
using namespace std;

bool operand(char x)
{
    return (x>='a'&&x<='z' || x>='A'&&x<='Z');
}
string posTOinf(string exp)
{
  stack<string>s;
  for (int i = 0;  exp[i] !=0; i++)
  {
      if (operand(exp[i]))
      {
          string op(1,exp[i]);
          s.push(op);
      }
      else
      {
          string op1= s.top();
          s.pop();
          string op2=s.top();
          s.pop();
          s.push('('+op2+exp[i]+op1+')');
      }
      
  }
  return s.top();
}
int main()
{
    string exp="ab*c+";
    cout<<posTOinf(exp);
}