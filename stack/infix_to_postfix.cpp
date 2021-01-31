#include<iostream>
#include<stack>
using namespace std;
//first we will arrange the operators in order
int great(char c)
{
    if (c=='^')
    return 3;
    else if (c== '*'||c=='/')
    return 2;
    else if (c=='+'||c=='-')
    return 1;
    else
    return -1;

}
//now convert infix to postfix function 
void inTOpo(string s)
{
  std::stack<char>st;
  st.push('N');
  int l=s.length();
  string ns;
  for (int i = 0; i < l; i++)
  {
      if ((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
      {
          ns+=s[i];
      }
      else if (s[i]=='(')
      {
          st.push('(');
      }
     else if (s[i]==')')
     {
         while (st.top() !='N'&&st.top()!='(')
         {
             char c = st.top();
             st.pop();
             ns+=c;
         }
         if (st.top()=='(')
         {
             char c = st.top();
             st.pop();
         }
         
     }
      else
      {
           while (st.top()!='N'&& great(s[i])<= great(st.top()))
           {
               char c = st.top();
               st.pop();
               ns+=c;
           }
           st.push(s[i]);
      }
      
  }
  while (st.top()!='N')
  {
      char c = st.top();
      st.pop();
      ns+=c;
  }
  cout<<ns<<endl;
}
int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    inTOpo(exp); 
    return 0;
}