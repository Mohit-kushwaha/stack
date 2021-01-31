#include<iostream>
using namespace std;
class node
{
private:
    /* data */
public:
      int data;
      node* next;
};
void push(node** head,int new_data)
{
    node* new_node=new node();
    new_node->data=new_data;
    new_node->next=*head;
    *head=new_node;
}
int detectLoop(node* head)
{
    node* slow=head;
   node* fast=head;
   while (slow&&fast&&fast->next)
   {
       slow=slow->next;
       fast=fast->next->next;
       if (slow==fast)
       {
           return 0;
       }
       
   }
    return 0;
}
void print(node* Node)
{
   while (Node!=NULL)
   {
      cout<<Node->data;
      Node=Node->next;    
   }
   
}
int main()
{
    node* head=NULL;
    int n;
//cin>>n;
    while (n!=-1)
    {
        cin>>n;
        push(&head,n);
    }
    detectLoop(head);
    print(head);
} 