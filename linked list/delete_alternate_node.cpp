#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
};
void deleteAlt(node* head)
{
    if(head==NULL)   //if list is empty
    return;
    //Keep track of previous of the node t
    //o be deleted. First change the next link of previous node and then free the memory allocated for the node.
    node* prev= head; 
    node* node=head->next;
    while (prev !=NULL && node!=NULL)   //1->2->3->4->5->NULL
    {
        prev->next=node->next;  //in this 2 will be replaced by 3
        delete(node);
        prev=prev->next;  //update prev
        if (prev!=NULL)
        {
           node=prev->next; //update node
        }
        
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
    push(&head, 5);  
    push(&head, 4);  
    push(&head, 3);  
    push(&head, 2);  
    push(&head, 1);  
  
    cout<<"List before calling deleteAlt() \n";  
    printlist(head);  
  
    deleteAlt(head);  
  
    cout<<"\nList after calling deleteAlt() \n";  
    printlist(head);  
  
    return 0;  
}