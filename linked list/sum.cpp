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
node* add( node*l1,node* l2)
{
    stack<int> s1,s2;
    while (l1!=NULL)
    {
        s1.push(l1->data);
        l1=l1->next;
    }
    while (l2!=NULL)
    {
        s2.push(l2->data);
        l2=l2->next;
    }
    int carry=0;
    node* result=NULL;
    if (s1.empty()==false||s2.empty()==false)
    {
     int a=0,b=0;
      if(s1.empty()==false){
            a=s1.top();
            s1.pop();
        }
        if(s2.empty()==false){
            b=s2.top();
            s2.pop();
        } 
        int total=a+b+carry;
        node* temp=new node();
        temp->data=total%10;
        carry=total/10;
        if (result==NULL)
        {
          result=temp;
        }
        else
        {
            temp->next=result;
            result=temp;
        }
        
    }
    if (carry!=0)
    {
        node* temp=new node();
        temp->data=carry;
        temp->next=result;
        result=temp;
    }
    return result;
}
void printll(node* head)
{
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    
}
int main()
{
    node* head1=NULL;
    node* head2=NULL;
    int n,m,i,j;
    cin>>n>>m;
   /* while (n--)
    {
        cin>>i;
        push(&head1,i);
    }
    while (m--)
    {
        cin>>j;
        push(&head2,j);
    }*/
     
     //  In this case it gives output 0 everytime

      int arr[n],ar[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];

        push(&head1,i);
    }
   for (int j = 0; j < n; j++)
   {
      cin>>ar[j];

      push(&head2,j);
   }
   // calling  by its size

   /* for (i = n-1; i >= 0; --i)  
        push(&head1, arr[i]);  
   
    // Create second list as 1->8  
    for (j = m-1; i >= 0; --j)  
        push(&head2, ar[j]);  */

     node* result= add(head1,head2);
     printll(result);   
     return 0;
}