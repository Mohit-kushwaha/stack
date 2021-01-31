#include<iostream>
using namespace std;
class node
{
  public:
      int data;
  node* next;
};
node* swap(node* ptr1,node* ptr2)
{
    node*temp=ptr2->next;
    ptr2->next=ptr1->next;
    ptr1->next=temp;
}
void bubblesort(node** head ,int count)
{
    struct node** h;
    int i,j,swapped;
    for ( i = 0; i <=count ; i++)
    { 
      h=head;
      swapped=0;
    for ( j = 0; j < count-i-1; j++)
    {
    struct  node* p1=*h;
    struct  node* p2=p1->next;
      if (p1->data>p2->data)
      {
        *h=swap(p1,p2);
        swapped=1;
      }
      h=&(*h)->next;
    }
       if (swapped==0)
       break;
       
       
    }
    
}
void printll(node* n)
{
  while(n!=NULL)
  {
    cout<<n->data<<" ";
    n=n->next;
  }
}

void Push(node** head,int new_data)//** means pointer points the head
{
node* new_node = new node; //allocate data
new_node->data=new_data;  //this will put the data
new_node->next=(*head);   //new node as a head
(*head)=new_node;         //this will move the head to new node
}
int main()
{
int n;
cin>>n;
int arr[n];
node* head =NULL;
for (int i = 0; i < n; i++)
{
   cin>>arr[i];
   Push(&head,i);
}
//int size=sizeof(arr) / sizeof(arr[0]); 
cout <<"Linked list before sorting\n"; 
printll(head);
cout <<"Linked list after sorting\n"; 
bubblesort(&head,n);
printll(head);
return 0;
}