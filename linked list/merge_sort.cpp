#include <bits/stdc++.h> 
using namespace std; 

/* Link list node */
class Node { 
public: 
	int data; 
	Node* next; 
}; 

Node* SortedMerge(Node* a, Node* b); 
void FrontBackSplit(Node* source,Node** frontRef, Node** backRef); 

void MergeSort(Node** headRef) 
{ 
	Node* head = *headRef; 
	Node* a; 
	Node* b; 

	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)) { 
		return; 
	} 

	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b); 

	/* Recursively sort the sublists */
	MergeSort(&a); 
	MergeSort(&b); 

	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(a, b); 
} 

/* See https:// www.geeksforgeeks.org/?p=3622 for details of this 
function */
Node* SortedMerge(Node* a, Node* b) 
{ 
	Node* result = NULL; 

	/* Base cases */
	if (a == NULL) 
		return (b); 
	else if (b == NULL) 
		return (a); 

	/* Pick either a or b, and recur */
	if (a->data <= b->data) { 
		result = a; 
		result->next = SortedMerge(a->next, b); 
	} 
	else { 
		result = b; 
		result->next = SortedMerge(a, b->next); 
	} 
	return (result); 
} 

void FrontBackSplit(Node* source, 
					Node** frontRef, Node** backRef) 
{ 
	Node* fast; 
	Node* slow; 
	slow = source; 
	fast = source->next; 

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL) { 
		fast = fast->next; 
		if (fast != NULL) { 
			slow = slow->next; 
			fast = fast->next; 
		} 
	} 

	/* 'slow' is before the midpoint in the list, so split it in two 
	at that point. */
	*frontRef = source; 
	*backRef = slow->next; 
	slow->next = NULL; 
} 

/* Function to print nodes in a given linked list */
void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data << " "; 
		node = node->next; 
	} 
} 


void push(Node** head_ref, int new_data) 
{ 
	
	Node* new_node = new Node(); 

	
	new_node->data = new_data; 

	
	new_node->next = (*head_ref); 

	
	(*head_ref) = new_node; 
} 

int main() 
{ 
	/* Start with the empty list */
	Node* res = NULL; 
	Node* a = NULL; 
int n,i;
cin>>n;
while(n--)
{
    cin>>i;
    push(&a, i); 
}

	/* Sort the above created Linked List */
	MergeSort(&a); 

//	cout << "Sorted Linked List is: \n"; 
	printList(a); 

	return 0; 
} 

