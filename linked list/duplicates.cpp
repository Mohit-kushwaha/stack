#include<iostream>
using namespace std;

class node{
	    public:
	    node*next=NULL;
	    int data;
	    
	    node(int d){
	        data=d;
	        
	    }
	    
	    node(node*&head,int d){
	        	  
	        node*nn=new node(d);
	        	   
	        if(head==NULL){
	            head=nn;
	            return;
	        }
	        
            node*temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
	   temp->next=nn;
	        
	    }
	};
	
	void rd(node*head){
	    

	    while(head!=NULL and head->next!=NULL){ 
	            node*temp=head;
	            int x=0;
	            while(temp->next!=NULL and temp->data==temp->next->data)
                {
	                x++;
					temp=temp->next;
				}

	            if(x!=0)
                {
			        node*t=head;
			        head=head->next;
			
	                temp=temp->next;					
		
			        t->next=temp;
	                node*temp2=head;

	                while(head!=temp)
                    {							//THIS WHILE LOOP IS NECESSARY TO FREE UP THE HEAP MEMORY
	        										//FOR A TEST CASE LIKE 
	                    temp2=head;								//8
	                    head=head->next;						//10 20 30 30 30 30 30 30 THE MEMORY OF ALL THE 30's EXCEPT THE FIRST ONE WONT BE FREED WITH THE IF BUT THEN ON THE OTHER HAND I GET RUNTIME ERROR WITHOUT IF
	                    delete temp2;

	                }
		        }
                else
			        head=head->next; 
        
		  }
	        
	    }
	
	
int main() {
    
    int n;
    cin>>n;
    node*head=NULL;
    
    while(n!=-1){
        int d;
        cin>>d;
        
        node(head,d);
        
        n--;
    }
	rd(head);

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    
	
}