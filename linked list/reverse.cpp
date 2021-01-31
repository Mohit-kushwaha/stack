#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node
{
   public:
   int data;
   node* next;

};
void reverse(node** head)
{
   stack<node*>s;
   node* temp= *head;
   while(temp->next!=NULL)
   {
      //store all the values in stack
      s.push(temp);
      temp=temp->next;
   }
  *head=temp;
  while (!s.empty())
  {
     temp->next=s.top();//store the top value of stack  in list
    s.pop();//pop the value from stack list;
  //update the next pointer in list 
  temp=temp->next;
}
  temp->next=NULL;
}
void printll(node* head)
{
   while (head!=NULL)
   {
      cout<<head->data<<" ";
      head=head->next;
   }
}
void insert_back(node** head,int new_data)
{
   node* temp=new node();
   temp->data=new_data;
   temp->next=NULL;
   if(*head==NULL)
   {
       *head=temp;
       return;
   }
   else
   {
      node* last_node=*head;
      while (last_node->next!=NULL)
      {
         last_node=last_node->next;
      }
      last_node->next=temp;
      return;
   }
   
}
int main()
{
   node* head=NULL;
   int n,i;
   cin>>n;
   while (n--)
   {
      cin>>i;
      insert_back(&head,i);
   }
   reverse(&head);
   printll(head);
   return 0;
}