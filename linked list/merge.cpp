#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node * next;
	node(int d){
		data=d;
		next=NULL;
	}

};
void print(node* head)
{
   
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return;
}
node* merge(node * a, node* b){
	if(	a==NULL){
	return b;
    }
	else if(b==NULL){
	return a;
    }
	node* c;
	if(a->data<b->data){
	c=a;
	c->next=merge(a->next,b);}
	else{
		c=b;
		c->next=merge(a,b->next);

	}
	return c;

}
void buildlist(node* & head, int n)
{
     while(n>0)
     {
        
    if(head==NULL)
    {
        head=new node(n);
    }
   else
   { 
       node * tail= head;
       while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail->next=new node(n);
    }
    n--;
    }
}
int main() 
{
	
	
		node* head1=NULL;
	node* head2=NULL;
    int n;
		cin>>n;
        int m;
	cin>>m;
        while (n--)
        {
           int i;
           cin>>i;
           buildlist(head1,n);
        }
        
		
	
    while (m--)
    {
       int j;
       cin>>j;
       buildlist(head2,m);
    }
    
    
	
    node * c =merge(head1, head2);
	print(c);
    cout<<endl;
    

	
	return 0;
}