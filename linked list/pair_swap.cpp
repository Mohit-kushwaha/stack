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
    new_node->next=*head;
    *head=new_node;
}
void swapping(node* head)
{
 node* temp= head;
 while(temp !=NULL&&temp->next!=NULL)
 {
    swap(temp->data,temp->next->data);
     temp = temp->next->next; 
 }   
}
void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main() 
{ 
    node* start = NULL; 
  
    /* The constructed linked list is:  
    1->2->3->4->5 */
    push(&start, 5); 
    push(&start, 4); 
    push(&start, 3); 
    push(&start, 2); 
    push(&start, 1); 
  
    cout << "Linked list "
         << "before calling pairWiseSwap()\n"; 
    print(start); 
  
    swapping(start); 
  
    cout << "\nLinked list "
         << "after calling pairWiseSwap()\n"; 
    print(start); 
  
    return 0; 
} 
  