#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
    node(int data) {
        this->data = data;
        this->next = NULL;  
    }
};

void findTriplet(node *a, node *b, node *c, int num);
node* reverseList(node *head);
node* mergeSort(node *head);
node* sortedMerge(node* a, node *b);
node* splitListInHalf(node* head);
node* addnode(node *head, int data);
void printList(node *head);

void findTriplet(node *head1, node *head2, node *head3, int num) {
    if (head1 == NULL || head2 == NULL || head3 == NULL)
        return;

    head2 = mergeSort(head2);                       // sort head2 in increasing order
    head3 = mergeSort(head3);                       // sort head3 in increasing order
    head3 = reverseList(head3);                     // reverse head3 to make it in decreasing order
    node *a = head1, *b = head2, *c = head3;
    int sum = 0;
    while (a != NULL) {
        b = head2;                                  // resetting b
        c = head3;                                  // resetting c
        while (b != NULL && c != NULL) {
            sum = a->data + b->data + c->data;
            if (sum == num) {
                cout<<endl<<endl<<"triplet found: "<<a->data<<" "<<b->data<<" "<<c->data;
                return;
            }
            else if (sum < num)
                b = b->next;
            else c = c->next;
        }
        a = a->next;
    }
    cout<<endl<<endl<<"triplet not found..";
}

node* reverseList(node *head) {
    if (head == NULL || head->next == NULL)
        return head;
    
    node *newhead = reverseList(head->next);
    node *ptr = newhead;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = head;
    head->next = NULL;
    return newhead;
}

node* mergeSort(node *head) {
    if (head == NULL || head->next == NULL)
        return head;

    node *first = head;
    node *second = splitListInHalf(head);

    first = mergeSort(first);
    second = mergeSort(second);

    node *result = sortedMerge(first, second);
    return result;
}

node* sortedMerge(node* a, node *b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    node *head = NULL;
    while (a != NULL && b!= NULL) {
        if (a->data < b->data) {
            head = addnode(head, a->data);
            a = a->next;
        }
        else {
            head = addnode(head, b->data);
            b = b->next;
        }
    }
    if (a == NULL && b != NULL)
        while (b != NULL) {
            head = addnode(head, b->data);
            b = b->next;
        }
    if (b == NULL && a != NULL)
        while (a != NULL) {
            head = addnode(head, a->data);
            a = a->next;
        }
    return head;
}

node* splitListInHalf(node* head) {
    if (head == NULL || head->next == NULL)
        return head;
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    node *second = slow->next;
    slow->next = NULL;
    return second;
}

node* addnode(node *head, int data) {
    if (head == NULL)
        return new node(data);
    node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new node(data);
    return head;
}

void printList(node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main() {
    node* headA = NULL;  
    node* headB = NULL;  
    node* headC = NULL;  
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
       addnode(headA,i);
    }
    while(x--)
    {
        cout<<"enter number j"<<endl;
        cin>>j;
        addnode(headB,j); 
    }
   while (y--)
   {
       cout<<"enter number l"<<endl;
       cin>>l;
        addnode(headC, l);
   }
   
   cout<<"enter number"<<endl;
    int givenNumber;
    cin>>givenNumber;
    findTriplet(headA,headB,headC,givenNumber);
    return 0;
}