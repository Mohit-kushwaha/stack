#include<iostream>
using namespace std;
class node{
    public:
       int data;
       node* next;
};
 
 node* sortedIntersect(node* a,node* b)
 {
     if (a==NULL||b==NULL)
     {
         return NULL;
     }
     //now if lists are  not empty

      if (a->data < b->data)
      {
          return sortedIntersect(a->next,b);
      }
     if (a->data>b->data)
     {
         return sortedIntersect(a,b->next);
     }
     //now in the above cases we had checked for smaller lists
     //now  below line pass only if lists are equal (a==b)
     node* temp= new node();
     temp->data= a->data;
     temp->next=sortedIntersect(a->next,b->next);
     return temp;
 }
 void push(node** head,int new_data)
 {
     node* new_node= new node();
     new_node->data= new_data;
     new_node->next=*head;
     *head=new_node;
 }
 void printList(struct node* Node)
{
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
}
 
 int main()
{
    /* Start with the empty lists */
    struct node* a = NULL;
    struct node* b = NULL;
    struct node* intersect = NULL;//thi is our empyt linked list which we will use to store temp

    push(&a, 6);
    push(&a, 5);
    push(&a, 4);
    push(&a, 3);
    push(&a, 2);
    push(&a, 1);

    push(&b, 8);
    push(&b, 6);
    push(&b, 4);
    push(&b, 2);
    intersect = sortedIntersect(a, b);
  printf("Linked list containing common items of a & b \n ");
    printList(intersect);
    }