#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

};
void reverse(node** head)
{
  node* curr= *head;
  node* next;
 while (curr->next!=NULL)
  {
     next=curr->next;
     curr->next=next->next;
     next->next=*head;
     *head=next;
  }
}
void push(node** head,int new_data)
{
    node* new_node=new node();
    new_node->data=new_data;
    new_node->next=*head;
    *head=new_node;
}
void printlist(node* head)
{
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node* head=NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 85);
    cout<<"given"<<endl;
    printlist(head);
    reverse(&head);
    cout<<"after"<<endl;
    printlist(head);
    
}