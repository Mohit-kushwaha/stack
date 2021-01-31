#include<bits/stdc++.h>
using namespace std;
class node
{
private:
    /* data */
public:
    int val;
    int data;
    node* next;
};

void push(node** head,int new_data)
{
     node* new_node = new node();
     new_node->data=new_data;
     new_node->next=*head;
     *head=new_node;
}
/*void last(node* &head,node* &tail)
{
if (head==NULL)
{
    return ;
}
node* prev=NULL;
node*curr=head;
node* t1=tail;
tail=head;
while(curr!=NULL)
{
    node* nxt=curr->next;
curr->next=prev;
prev=curr;
curr=nxt;
}
tail=head;
head=t1;
}*/
void fromlast(node* head,int n)
{
    int length=0,i;
    node*temp=head;
    while (temp!=NULL)
    {
        temp=temp->next;
        length++;
    }
    
    if (length<n)
    
        return;
        temp=head;
    
    for ( i = 1; i < length-n+1; i++)
    
        temp=temp->next;
        cout<<temp->data<<" ";
        return;
    
    
}
int main()
{
    node*head=NULL;
    node*tail=NULL;
   push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 35); 

/*int n,i;
  cin>>n;
 while(n--)
 {
  cin>>i;
  push(&head,i);
 }
  */
    
    



fromlast(head, 4); 
    return 0; 
   /* reverse(head,tail);*/
}