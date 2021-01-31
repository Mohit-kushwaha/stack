#include<iostream>
using namespace std;
class node
{

public:
  int data;
  node* next;
};
void back(node** head,int new_data)
{
    node* new_node=new node();
   new_node->data=new_data;
   new_node->next=(*head);
   (*head)=new_node;
}
void deletenode(node** head,int key)
{
  node* temp=*head;
  node* prev=NULL;
  //the key is head
  if (temp!=NULL&&temp->data==key)
  {
    *head=temp->next;
    delete temp;
    return;
  }
  //if the key is predent in between the node
  //in this case we have to change prev_node as next
if(temp!=NULL&&temp->data!=key)
{
  prev=temp;
  temp=temp->next;
}
//if key is not present 
if (temp==NULL)
{
  return;
}
//unlink the key
prev->next=temp->next;
delete temp;
}
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
  
    // Add elements in linked list 
    back(&head, 7); 
    back(&head, 1); 
    back(&head, 3); 
    back(&head, 2); 
  
    cout<<"Created Linked List: "<<endl; 
    printlist(head); 
  
    deletenode(&head, 1); 
    cout<<"Linked List after Deletion of 1: "<<endl; 
      
    printlist(head); 
      
}