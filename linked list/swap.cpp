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

/*void push(node** head,int new_data)
{
   node* new_node=new node();
   new_node->data=new_data;
   new_node->next=NULL;
   if (*head==NULL)
   {
       *head=new_node;
       return;
   }
}*/
void push(node** head,int new_data)
{
      node* new_node=new node();
       new_node->data=new_data;
      new_node->next=*head;
      *head=new_node;
}

void swap(node** head,int x,int y)
{
    //if the values are same 
    if(x==y)
    return;
    //we have to search for X
    node* prevX=NULL,*currX=*head;
    while (currX&&currX->data!=x)
    {
           prevX=currX;
           currX=currX->next;
    }
//we hace to search for Y
    node* prevY=NULL,*currY=*head;
    while (currY&&currY->data!=y)
    {
         prevY=currY;
         currY=currY->next;
    }
    //IF Y OR X is not present in linked list
    if (currX==NULL||currY==NULL)
    return;
    //if X is not is not head of linked list
   if(prevX!=NULL)
   prevX->next = currY;
    //make it  head as Y 
   else
   * head=currY; 
//if Y is not is not head of linked list
   if(prevY!=NULL)
  
   prevY->next=currX;
else
 //make it head as X
*head=currX;
    //swap the values
    node*temp=currY->next;
    currY->next=currX->next;
    currX->next=temp;

}
void print(node* head)
{

    while(head!=NULL)
    {
      cout<<head->data<<" -> ";
      head=head->next;
    }
    cout<<"NULL";
}
int main()  
{  
    node *start = NULL;  

    push(&start, 7);  
    push(&start, 6);  
    push(&start, 5);  
    push(&start, 4);  
    push(&start, 3);  
    push(&start, 2);  
    push(&start, 1);  
  
    cout << "Linked list before calling swapNodes() ";  
    print(start);  
  
    swap(&start, 4, 3);  
  
    cout << "\nLinked list after calling swapNodes() ";  
    print(start);  
  
    return 0;  
}  