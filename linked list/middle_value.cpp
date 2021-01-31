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
    node* new_node=new node;
    new_node->data=new_data;
    new_node->next=*head;
    *head=new_node;
}
void middle(node* head)
{
    node* slow_ptr=head;//this pointer starts fromm head
    node* fast_ptr=head;//this pointer is one step away from slow_ptr
    if(head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
     {   fast_ptr=fast_ptr->next->next;
        slow_ptr=slow_ptr->next;
     }
     cout<<"the midlle element is"<<endl;
    cout<<slow_ptr->data<<endl;
    }
}
void print(node* ptr)
{
    while (ptr!=NULL)
    {
        cout<<ptr->data<<"->";
       ptr=ptr->next;
    }
    cout<<"NULL"<<endl;
}
int main()  
{  
    // Start with the empty list  
    struct node* head = NULL;  
    // Iterate and add element  
    for (int i=15; i>0; i--)  
    {  
        push(&head, i);  
       print(head);  
        middle(head);  
    }  
   print(head);  
        middle(head);  
    return 0;  
}  