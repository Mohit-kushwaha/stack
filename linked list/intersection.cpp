#include <bits/stdc++.h>
using namespace std;

class node{
public:
    //to store data of linked list
    int val;
    //to store address of next node
    node* next;

    node(int v){
       val =v;
        next = NULL;
    }

     node(){
       // val =v;
        //next = NULL;
    }

};

  void insertAtEnd(node* &head,int d){
        //if first node then head==NULL;
          node* n=new node();
          //we can access object data through pointer using ->
          n->val = d;
          n->next=NULL;

        if(head==NULL){
          //make both head and tail equal to current node
          head =  n;
          return;
        }

         node* curr=head;
         while(curr->next!=NULL){
            curr=curr->next;
         }

         curr->next =n;


    }

    //print linked list
    void printLL(node* head){
        //condition for stopping
        while(head!=NULL){
               //cout << (*head).val << " ";
            cout << head->val << " ";
            //move head pointer to point to next node
            head = head->next;
        }

    }

      //print size of linked list
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




    //recursive
    node* searchRecursive(node* head,int x){
        //base case
        if(head==NULL){
            return NULL;
        }
        if(head->val==x)
            return head;
        return searchRecursive(head->next,x);
    }


  node* intersection(node* h1,node* h2){
            int l1=printLength(h1);
            int l2=printLength(h2);

            node* f=h1;
            node* s=h2;

            //make bigger linked list travel the extra length
            if(l1>l2){
                int diff=l1-l2;
                for(int i=0;i<diff;i++)
                    f=f->next;
            }
            else{
                  int diff=l2-l1;
                for(int i=0;i<diff;i++)
                    s=s->next;

            }

            while(f!=NULL && s!=NULL && f!=s){
                f=f->next;
                s=s->next;
            }

            if(f==NULL)
                return f;
        return f;

    }






int main(){

    node* head =NULL;
    node* h1=NULL;

   // int user;
    //cin>>user;
    //while(user!=-1){
        int n,i,j,m;
        cin>>n>>m;
        while(n--)
         cin>>i;
        {insertAtEnd(head,i);
        }
          while(m--)
          {
              cin>>j;
             insertAtEnd(h1,j);
          } 
           
             h1->next->next->next->next=head->next;
 

node* res=intersection(h1,head);

if(res==NULL)
    cout << "No intersection" << endl;
else
cout << res->val << endl;



  //printLL(head);

}


