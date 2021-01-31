#include<bits/stdc++.h>
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
//HASHING
bool detectloop(node* h)
{
    unordered_set<node*> s;
    while(h!=NULL)
  {  if(s.find(h)!=s.end())
    return true;
    s.insert(h);
    h=h->next;
  }
  return false;
}
//FLOYD CYCLE
int detectLoop(node* head)
{
    node* slow=head;
    node* fast=head;
    while (slow&&fast&&fast->next)
    {
       slow=slow->next;
       fast=fast->next->next;
       if(slow=fast)
       return 1;
    }
    return 0;
}
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
 //this depends on us ki hum kitne values tk 
 //loop dhudna chahte h linked list me
    head->next->next->next->next = head;
 
    if (detectloop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
   if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
 
    return 0;
}