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

void push(node* &head,node* &tail,int d)
{
    node* cur=new node(d);
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

void print_ll(node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

node* reverse(node* head){
    if(head==NULL)return head;

    node *prev=NULL,*next=NULL,*cur=head;
    
    while(cur)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;

        cur=next;
    }

    return prev;
}

node* add(node *head1,node *head2)
{
    int c=0,d;

    head1=reverse(head1);
    head2=reverse(head2);

    node *head=NULL,*tail=NULL;
    while(head1||head2||c)
    {
        if(head1)
        {
            c+=head1->data;
            head1=head1->next;
        }

        if(head2)
        {
            c+=head2->data;
            head2=head2->next;
        }

        push(head,tail,c%10);
        c=c/10;
    }

    return reverse(head);
}


int main()
{
    int n,m,cur;

    cin>>n>>m;

    node *head1=NULL,*tail1=NULL,*head2=NULL,*tail2=NULL;

    for(int i=0;i<n;i++)
    {
        cin>>cur;
        push(head1,tail1,cur);
    }

    for(int i=0;i<m;i++)
    {
        cin>>cur;
        push(head2,tail2,cur);
    }

    node* result=add(head1,head2);

    if(result)print_ll(result);
    else cout<<0;
}