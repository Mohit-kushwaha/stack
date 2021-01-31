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
   new_node->next=NULL;
   if (*head==NULL)
   {
       *head=new_node;
       return;
   }
     node* cur=*head;
    while(cur->next)cur=cur->next;
    
    cur->next=new_node;
}
int index(node* head,int ind)
{
    node* current=head;
    int count=0;
    while (current!=NULL)
    {
        if (count==ind)
        
             return (current->data); 
          
            count++;
            current=current->next;
        
        
    }
    return 0;
}
int main() 
{ 
  
    // Start with the 
    // empty list 
    node* head = NULL; 
  
    push(&head, 1); 
    push(&head, 10); 
    push(&head, 30); 
    push(&head, 14); 
    push(&head, 85); 
    cout << "Element at index 0 is "<<endl;
    cout<<index(head, 0)<<endl; 
    cout << "Element at index 1 is "<<endl;
    cout<<index(head, 1)<<endl; 
    cout << "Element at index 2 is "<<endl;
    cout<<index(head, 2)<<endl; 
    cout << "Element at index 3 is "<<endl;
    cout<<index(head, 3)<<endl; 
    cout << "Element at index 4 is "<<endl;
    cout<<index(head, 4)<<endl; 
    return 0; 
} 
