#include <bits/stdc++.h> 
using namespace std; 
  
/* Link list node */
class Node  
{  
    public: 
    int data;  
    Node* next;  
};  
  
/* A utility function to insert  
a node at the beginning of a  
linked list*/
void push (Node** head_ref, int new_data)  
{  
    /* allocate node */
    Node* new_node = new Node(); 
  
    /* put in the data */
    new_node->data = new_data;  
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);  
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;  
}  
  
/* A function to check if there are three elements in a, b  
and c whose sum is equal to givenNumber. The function  
assumes that the list b is sorted in ascending order  
and c is sorted in descending order. */
bool isSumSorted(Node *headA, Node *headB,  
                Node *headC, int givenNumber)  
{  
    Node *a = headA;  
  
    // Traverse through all nodes of a  
    while (a != NULL)  
    {  
        Node *b = headB;  
        Node *c = headC;  
  
        // For every node of list a, prick two nodes  
        // from lists b abd c  
        while (b != NULL && c != NULL)  
        {  
            // If this a triplet with given sum, print  
            // it and return true  
            int sum = a->data + b->data + c->data;  
            if (sum == givenNumber)  
            {  
            cout << "Triplet Found: " << a->data << " " <<  
                                b->data << " " << c->data;  
            return true;  
            }  
  
            // If sum of this triplet is smaller, look for  
            // greater values in b  
            else if (sum < givenNumber)  
                b = b->next;  
            else // If sum is greater, look for smaller values in c  
                c = c->next;  
        }  
        a = a->next; // Move ahead in list a  
    }  
  
    cout << "No such triplet";  
    return false;  
}  
  
  
/* Driver code*/
int main()  
{  
    /* Start with the empty list */
    Node* headA = NULL;  
    Node* headB = NULL;  
    Node* headC = NULL;  
  int n,x,y;
  cout<<"enter number1"<<endl;
  cin>>n;
  cout<<"enter number2"<<endl;
  cin>>x;
  cout<<"enter number3"<<endl;
  cin>>y;
  int i,j,l;
    while(n--)
    {
        cout<<"enter number i"<<endl;
       cin>>i;
       push(&headA,i);
    }
    while(x--)
    {
        cout<<"enter number j"<<endl;
        cin>>j;
        push (&headB,j); 
    }
   while (y--)
   {
       cout<<"enter number l"<<endl;
       cin>>l;
        push (&headC, l);
   }
   
   cout<<"enter number"<<endl;
    int givenNumber;
    cin>>givenNumber;  
  
    isSumSorted (headA, headB, headC, givenNumber);  
  
    return 0;  
}  