#include<iostream>
using namespace std;
class node
{
private:
  
public:
int key;
node* next;
};
void push(node** head,int new_key)
{
    node* new_node=new node();
    new_node ->key=new_key;
    new_node->next=*head;
    *head=new_node;

}
//this iterative function
bool search(node* head,int x)
{
    node* current=head;
    while (current!=NULL)
    {
        if (current->key==x)
        
          
            return true;
            current=current->next;
        
        
    }
    return false;
}
//this is an recurssive function
/*bool search(node* head, int x)  
{  
    // Base case  
    if (head == NULL)  
        return false;  
      
    // If key is present in current node, return true  
    if (head->key == x)  

    return true;  
  
    // Recur for remaining list  
    return search(head->next, x);  
}  */
int main()  
{  
    /* Start with the empty list */
    node* head = NULL;  
    int x = 21;  
  
    /* Use push() to construct below list  
    14->21->11->30->10 */
    push(&head, 10);  
    push(&head, 30);  
    push(&head, 11);  
    push(&head, 21);  
    push(&head, 14);  
  
    search(head, 21)? cout<<"Yes" : cout<<"No";  
    return 0;  
}  
