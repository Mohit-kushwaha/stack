#include<iostream>
#include<stack>
using namespace std;
class twoStacks
{

    int *arr;
    int size,top1,top2;
    public:
    twoStacks(int n)  //constructor
    {
        size=n;
        arr= new int[n];
        top1 =-1;
        top2=size;
    }
    //push element x to stack
    void push1(int x)
    {
        if (top1 < top2-1)
        {
           top1++;
           arr[top1]=x;
        }
        else
        {
            cout<<"stack overflow";
            exit(1);
        }
        
    }
    void push2(int x)
    {
        if (top1 < top2 -1)
        {
            top2--;
            arr[top2]=x;
        }
        else
        {
            cout<<"stack overflow";
            exit(1);
        }
        
    }
    int pop1()
    {
        if (top1>=0)
        {
            int x= arr[top1];
            top1--;
            return x;
        }
        else
        {
            cout<<"stack underflow";
            exit(1);
        }
        
    }
    int pop2()
    {
        if (top2>=0)
        {
            int x=arr[top2];
            top2--;
            return x;
        }
        else
        {
            cout<<"stack underrflow";
            exit(1);
        }
        
    }
};


int main()
{
    twoStacks ts(4);
    ts.push1(5);
    ts.push2(10);
    ts.push1(15);
  //  ts.push1(11);
    ts.push2(7);
    //ts.push2(40);
    cout << "Popped element from stack1 is "
         << ts.pop1(); 
       
    cout << "\nPopped element from stack2 is "
         << ts.pop2(); 
    return 0; 
}