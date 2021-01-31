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
//Push function can be written in pointer form
/*node *newNode(int key)  
{  
     node *temp =  new node;  
    temp->data = key;  
    temp->next = NULL;  
    return temp;  
}  */
int countnode(node* n)
{
    int count=0;
    node* temp=n;
    while (temp->next!=n)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
int countnodeinLoop(node* head)
{
    node*slow=head;
    node* fast= head;
    while (slow&&fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast) 
        return countnode(slow);
    }
    return 0;
}

int main()
{
    node* head=NULL;
  
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
    //This can be written as:-
       /*node *head = newNode(1);  
    head->next = newNode(2);  
    head->next->next = newNode(3);  
    head->next->next->next = newNode(4);  
    head->next->next->next->next = newNode(5);
  
      head->next->next->next->next->next = head->next;  */
   head->next->next->next->next = head;
    cout << countnodeinLoop(head) << endl;  
  
    return 0;  
}