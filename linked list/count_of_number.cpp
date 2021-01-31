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
    node* new_node= new node();
    new_node->data=new_data;
    new_node->next=*head;
   *head=new_node;
}
int count(node*head,int x)
{
    node* current=head;
    int count=0;
    while(current!=NULL)
    {
        if(current->data==x)
        count++;
        current=current->next;
        
    }
    return count;

}
int main()
{
    node* head= NULL;
     push(&head, 1); 
    push(&head, 3); 
    push(&head, 1); 
    push(&head, 2); 
    push(&head, 1); 
    cout<<count(head,1);
}