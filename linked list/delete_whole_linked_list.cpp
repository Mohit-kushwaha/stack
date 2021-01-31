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
void deletell(node** head)
{
    node* current=*head;
    node* next;
    while (current!=NULL)
    {
        next= current->next; 
        delete current;
     current=next;
        
    }
    *head=NULL;
}
void push(node** head,int new_data)
{
    node* new_node=new node();
    new_node->data=new_data;
    new_node->next=*head;
    *head=new_node;
}
int main()  
{  
    /* Start with the empty list */
    node* head = NULL;  
      
    /* Use push() to construct below list  
    1->12->1->4->1 */
    push(&head, 1);  
    push(&head, 4);  
    push(&head, 1);  
    push(&head, 12);  
    push(&head, 1);  
      
    cout << "Deleting linked list";  
    deletell(&head);  
      
    cout << "\nLinked list deleted";  
}  