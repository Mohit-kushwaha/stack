#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;//store data of linked list
    node* next; //stored adress of next node
     node(int v)
    {
    val=v;
    next=NULL;
    }
    node()
    {
   // val=v;
    //next=NULL;
    }
   
};
 void insertatend(node* &head,node* &tail,int d)
    {
        node* n= new node();
        n->val=d;
        n->next=NULL;
        if(head==NULL)
        {
          //make both head and tail equal to current node
           head=tail=n;
          return;   
        }
        //addd the index to node
        tail->next=n;
        //make node to newly added node
        tail=n;

    }
void print(node* head)
{
    
    while (head!=NULL)
    {
     
       cout<<head->val<<" "<<endl;
    
    head=head->next;
}

}
 int printLength(node* head){
        int c=0;
        //condition for stopping
        while(head!=NULL){
                c++;
               //cout << (*head).val << " ";
           // cout << head->val << " ";
            //move head pointer to point to next node
            head = head->next;
        }
        return c;

    }
void insertatstart(node* &head,node* &tail,int d)
{
     node* n= new node();
        n->val=d;
        n->next=NULL;
        if(head==NULL)
        {
          //make both head and tail equal to current node
           head=tail=n;
          return;   
        }
        //make next of new node to be head
n->next=head;
head=n;
}
int main()
{
/*node a(5);
node b(10);
a.next=&b;
cout<<(*(a.next)).val<<endl;
cout<< (a.next)->val<<endl;*/
//storing address of first address
node* head=NULL;
node* tail=NULL;
insertatend(head,tail,1);
insertatend(head,tail,2);
insertatend(head,tail,3);
insertatend(head,tail,4);
insertatend(head,tail,5);
insertatend(head,tail,6);
print(head);
cout<<endl;
cout<<"/////////////////////////"<<endl;
node* h1=NULL;
node* t1= NULL;
insertatstart(h1,t1,6);
insertatstart(h1,t1,5);
insertatstart(h1,t1,4);
insertatstart(h1,t1,3);
insertatstart(h1,t1,2);
insertatstart(h1,t1,1);
print(h1);
cout<<endl<<endl;
cout << printLength(h1) << endl;
    cout << printLength(head) << endl;

}