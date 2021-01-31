#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};

void print_ll(node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

node* segregate(node* head)
{
    if(!head) 
    return head;
    node *odd_head=NULL,
    *odd_tail=NULL,*even_head=NULL,
    *even_tail=NULL;

    while(head)
    {
        if(odd_head==NULL)
        {
            odd_head=head;
            odd_tail=head;
        }

        else{
            odd_tail->next=head;
            odd_tail=odd_tail->next;
        }

        head=head->next;
     
        if(head==NULL)
        continue;

        if(even_head==NULL)
        {
            even_head=head;
            even_tail=head;
        }

        else{
            even_tail->next=head;
            even_tail=even_tail->next;
        }

        head=head->next;
    }

    odd_tail->next=even_head;
    if(even_tail)
    even_tail->next=NULL;
    return odd_head;
}

int main()
{
    int n,x;
    cin>>n;

    node *tail=NULL,*head=NULL;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        node* cur=new node(x);

        if(head==NULL)
        {
            head=cur;
            tail=cur;
        }

        else
        {
            tail->next=cur;
            tail=tail->next;
        }
    }
	cout<<"Original List: ";
	print_ll(head);
	cout<<"\nModified List: ";
    print_ll(segregate(head));
}