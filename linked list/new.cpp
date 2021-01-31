#include<iostream>
struct Node { 
	int data; 
	struct Node* next; 
} Node; 

/*Function to swap the nodes */
struct Node* swap(struct Node* ptr1, struct Node* ptr2) 
{ 
	struct Node* tmp = ptr2->next; 
	ptr2->next = ptr1; 
	ptr1->next = tmp; 
	return ptr2; 
} 

/* Function to sort the list */
void bubbleSort(struct Node** head, int count) 
{ 
	struct Node** h; 
	int i, j, swapped; 

	for (i = 0; i <= count; i++) { 

		h = head; 
		swapped = 0; 

		for (j = 0; j < count - i - 1; j++) { 

			struct Node* p1 = *h; 
			struct Node* p2 = p1->next; 

			if (p1->data > p2->data) { 

				/* update the link after swapping */
				*h = swap(p1, p2); 
				swapped = 1; 
			} 

			h = &(*h)->next; 
		} 

		/* break if the loop ended without any swap */
		if (swapped == 0) 
			break; 
	} 
} 

/* Function to print the list */
void printList(struct Node* n) 
{ 
	while (n != NULL) { 
		printf("%d ", n->data); 
		n = n->next; 
	} 
	printf("\n"); 
} 

/* Function to insert a struct Node 
at the beginning of a linked list */
void insertAtTheBegin(struct Node** start_ref, int data) 
{ 
	struct Node* ptr1 
		= (struct Node*)malloc(sizeof(struct Node)); 

	ptr1->data = data; 
	ptr1->next = *start_ref; 
	*start_ref = ptr1; 
} 

// Driver Code 
int main() 
{ 
    	struct Node* start = NULL; 
    int n;
    std::cin>>n;

	int arr[n] ; 
    for (int i = 0; i < n; i++)
    {
        std::cin>>arr[i];
      
    }
    
	int list_size, i; 

	/* start with empty linked list */

	list_size = sizeof(arr) / sizeof(arr[0]); 

	/* Create linked list from the array arr[] */
	for (i = 0; i < list_size; i++) 
		insertAtTheBegin(&start, arr[i]); 

	/* print list before sorting */
	//printf("Linked list before sorting\n"); 
	printList(start); 

	/* sort the linked list */
	bubbleSort(&start, list_size); 

	/* print list after sorting */
	//printf("Linked list after sorting\n"); 
	printList(start); 

	return 0; 
} 
