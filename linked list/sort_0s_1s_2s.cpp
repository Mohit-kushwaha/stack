#include<iostream>
using namespace std;
class node{
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
void sort(node* head)
{
    int count[3]={0,0,0};
    node* ptr=head;
    //now we will count the number of 0s,1s,2s
    while (ptr!=NULL)
    {
        count[ptr->data]+=1;
        ptr=ptr->next;
    }
    int i=0;
    ptr=head;
    //now traverse the data we had stored
    while (ptr!=NULL)
    {
        if (count[i]==0)
        
        ++i;
        else
        {
            ptr->data=i;
            --count[i];
           ptr= ptr->next;
        }
    }
    
}
void print(node* Node)
{
   while(Node!=NULL)
  { 
      cout<<Node->data<<" ";
   Node=Node->next;
   }
}
int main()
{
    node* head=NULL;
    int n,i;
    cin>>n;
    while (n--)
    {
       cin>>i;
       push(&head,i);
    }
    sort(head);
    print(head);
}