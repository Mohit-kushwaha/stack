#include<iostream>
using namespace std;
class node
{
private:
    /* data */
public:
      int data;
      node*next;
};
void push(node** head,int new_data)
{
    node* new_node=new node();
    new_node->data=new_data;
    new_node->next=*head;
    *head=new_node;
}
void Duplicates(node* head)
{
    node* current=head;
    node* next_next;
    if (current==NULL)
     return;

    while (current->next!=NULL)
    {
        if (current->data==current->next->data)
        {
           next_next=current->next->next;
           delete current->next;
           current->next=next_next;
        }
      else
  {
      current=current->next;
  }
    }
  
    
}
void printList(node* Node) 
{ 
    while (Node!=NULL) 
    { 
        cout<<Node->data<<"->"; 
        Node = Node->next; 
    } 
    cout<<" NULL";
} 
int main() 
{ 
    /* Start with the empty list */
    node* head = NULL; 
     
  
    push(&head, 20); 
    push(&head, 13); 
    push(&head, 13); 
    push(&head, 11); 
    push(&head, 10); 
    push(&head, 11);                                     
 
    cout<<"Linked list before duplicate removal "; 
    printList(head); 
 
    /* Remove duplicates from linked list */
    Duplicates(head); 
 
    cout<<"\nLinked list after duplicate removal ";     
    printList(head);             
     
    return 0; 
} 