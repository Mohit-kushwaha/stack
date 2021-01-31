#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
};
node* newnode(int data)
{
   node* temp=new node();
   temp->data=data;
   temp->next=NULL;
  return temp;
}
void Duplicate(node* start)
{
    node* ptr1,*ptr2,*dup;
    ptr1=start;
    while (ptr1!=NULL&&ptr1->next!=NULL)
    {
         ptr2=ptr1;
         while (ptr2->next!=NULL)
         {
             if (ptr1->data==ptr2->next->data)
             {
              dup=ptr2->next;
              ptr2->next=ptr2->next->next;
              delete dup;   
             }
             else
             {
                 ptr2 =ptr2->next;
             }
         }
           ptr1=ptr1->next;
    }
    
}
void print(node* Node)
{
    while(Node!=NULL)
    {
       cout<<" "<<Node->data;
       Node=Node->next;
    }
}
int main()
{
    
node *start= newnode(10);
    start->next = newnode(12);
    start->next->next = newnode(11);
    start->next->next->next = newnode(11);
    start->next->next->next->next = newnode(12);
    start->next->next->next->next->next =newnode(11);
    start->next->next->next->next->next->next =newnode(10);
    cout<<"Linked list before removing duplicates ";
    print(start);
 
    Duplicate(start);
 
    cout<<"\nLinked list after removing duplicates ";
    print(start);
 
    return 0;


}