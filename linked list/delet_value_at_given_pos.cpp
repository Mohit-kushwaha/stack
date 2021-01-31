#include<bits/stdc++.h>
using namespace std;
class node
{

public:
     int data;
     node* next;
};

void push(node** head,int new_data)
{
    node* new_node=new node();
    new_node->data=new_data;
    new_node->next=(*head);
   (*head)=new_node;
}
void deletenode(node** head,int position)
{
    //if list is empty
    if (*head==NULL)
    {
        return;
    }
    node*temp=*head; //storing head node
    if(position==0)
    {
        *head=temp->next;  //change head
        delete temp;       //delete old memory
        return;
    }
    //if poisiton is in between the node
    for (int i = 0;temp!=NULL&& i < position-1; i++)
    {
       temp=temp->next;
    }
    //position is bigger then the size of node
    if(temp==NULL||temp->next)
    return;
    //temp->next have to be deleted 
    //to delete it first we have to store pointer to next of the node to be deleted
    node* next=temp->next->next;
    temp->next=next;     //unlink the deleted node
    delete temp->next;   //free memory
}
//print the list
void printlist(node* node)
{
    while (node!=NULL)
    {
        cout<<node->data<<" ";
        node=node->next;
    }
    
}
int main()
{
    node* head = NULL; 
  
    push(&head, 7); 
    push(&head, 1); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 8); 
  
    cout<<"Created Linked List: "<<endl; 
    printlist(head); 
    deletenode(&head, 4); 
    cout<<"\nLinked List after Deletion at position 4: \n"; 
    printlist(head); 
    return 0; 

}