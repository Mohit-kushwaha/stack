#include<iostream>
using namespace std;
class node
{
public:
 int data;
 node* next;   
};
//insert a new node in front;
void Push(node** head,int new_data)//** means pointer points the head
{
node* new_node = new node; //allocate data
new_node->data=new_data;  //this will put the data
new_node->next=(*head);   //new node as a head
(*head)=new_node;         //this will move the head to new node
}
void middle(node* prev,int new_data)
{
  if (prev ==NULL)  //random value of array cant be null 
  {
    return;
  }
  node* new_node = new node();  //allocate data
  new_node->data=new_data;     //this will put the data
    new_node->next = prev->next;  //this will make the new node as previus node
 prev->next=new_node;           //this will move the prev to new node
}
void last(node** head,int new_data)//** this mean pointer points to head
{
    node* new_node=new node;
    new_node->data=new_data;
    new_node->next=NULL;
    if (*head==NULL)
    {
        *head=new_node;
        return;
    }
    node*last=*head;
    while (last->next!=NULL)
    {
        last=last->next;
        last->next=new_node;
        return;
    }
    
}
void Printlist(node* node)
{
    while(node!=NULL)
    {
        cout<<node->data<<" ";
        node=node->next;
    }
    //cout<<"NULL";
}
int main()
{

node* head = NULL;  
      
    // Insert 6. So linked list becomes 6->NULL  
    last(&head, 6);  
      
    // Insert 7 at the beginning.  
    // So linked list becomes 7->6->NULL  
    Push(&head, 7);  
      
    // Insert 1 at the beginning.  
    // So linked list becomes 1->7->6->NULL  
    Push(&head, 1);  
      
    // Insert 4 at the end. So  
    // linked list becomes 1->7->6->4->NULL  
    last(&head, 4);  
      
    // Insert 8, after 7. So linked  
    // list becomes 1->7->8->6->4->NULL  
    middle(head->next, 8);  
      
    cout<<"Created Linked list is: ";  
    Printlist(head);  
      
    return 0;  

}