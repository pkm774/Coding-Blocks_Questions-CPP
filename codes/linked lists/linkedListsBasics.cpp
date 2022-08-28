#include <iostream>

// Node declaration for Linked List
class node {
public:
	int data;
	node* next;
};

/***************************************************************************************************/

						   /*     Length and Print function for LL     */

/***************************************************************************************************/

// Function to calculate numbers of nodes or length of linked list
int LLlength(node*& head) {
	int count = 0;
	node* temp = head;
	while (temp != NULL) {
		++count;
		temp = temp->next;
	}
	delete temp;
	return count;
}

// Function to print data from nodes of link list
void printLL(node*& head) {
	node* temp = head;
	while (temp != NULL) {
		std::cout << temp->data << " --> ";
		temp = temp->next;
	}
	delete temp;
	std::cout << "NULL" << std::endl;
}

/***************************************************************************************************/

						   /*     Insertion methods in linked lists     */

/***************************************************************************************************/

// Function to insert element at first, head and tail are passed by reference
void insertATfirst(node*& head, node*& tail, int dat) {
	// creating new node having data and pointer element
	node* n = new node;

	// filling elements of node n
	n->data = dat;
	n->next = NULL;

	//// check for head if its null by deletion of first node
	//// if its null and tail is not null then put the adress of n into both
	//if (head == NULL && tail != NULL) {
	//	head = n;
	//	tail = n;
	//}

	// if head and tail pointer holds null then put the adress of n into both
	if (head == NULL && tail == NULL) {
		head = n;
		tail = n;
	}
	// if head pointer is not empty then put the adress of head in n
	// and change the position of head to current n;
	else {
		n->next = head;
		head = n;
	}
}

// Function to insert element at last, head and tail are passed by reference
void insertATlast(node*& head, node*& tail, int dat) {
	// creating new node having data and pointer element
	node* n = new node;

	// filling elements of node n
	n->data = dat;
	n->next = NULL;

	// if head and tail pointer holds null then put the adress of n into both
	if (head == NULL && tail == NULL) {
		head = n;
		tail = n;
	}
	// if tail pointer is not empty then put the adress of n in tail
	// and change the position of tail to current n;
	else {
		tail->next = n;
		tail = n;
	}
}

// Function to insert at any index value in linked list
// Only if link list is not empty (minimum 3 values are present)
void insertATpos(node*& head, node*& tail, int position, int dat) {
	// for first position
	if (position == 1) {
		insertATfirst(head, tail, dat);
	}
	// for last position
	else if (position == LLlength(head)) {
		insertATlast(head, tail, dat);
	}
	// for position between first and last
	else {
		// creating new node having data and pointer element
		node* n = new node;

		// filling elements of node n
		n->data = dat;
		n->next = NULL;

		// Temporary node for handling address
		node* htemp = head;
		for (int i = 0; i < position - 2; ++i) {
			htemp = htemp->next;
		}

		n->next = htemp->next;
		htemp->next = n;
	}
}

/***************************************************************************************************/

						   /*     Deletion methods in linked lists     */

/***************************************************************************************************/

// function for deleting element from first in linked list
void deleteFROMfirst(node*& head, node*& tail) {
	// if no node is present
	if (head == NULL) {
		return;
	}
	// if only one node is present
	else if (head->next == NULL) {
		node* temp = head;
		// make both head and tail to NULL because next node doesn't exist
		head = NULL;
		tail = NULL;
		delete temp;
	}
	// if more than one node are present
	else {
		node* temp = head;
		head = head->next;
		delete temp;
	}
}

// function for deleting element from the last of linked list
void deleteFROMlast(node*& head, node*& tail) {
	// if no node is present return void
	if (head == NULL) {
		return;
	}
	// if only one node is present then delete that node by head
	else if (head->next == NULL) {
		node* temp = head;
		// make both head and tail to NULL because next node doesn't exist
		head = NULL;
		tail = NULL;
		delete temp;
	}
	// if more than one node are present
	else {
		node* temp = head;
		for (int i = 1; i <= LLlength(head) - 2; ++i) {
			temp = temp->next;
		}

		tail = temp;
		temp = temp->next;
		tail->next = NULL;
		delete temp;
	}
}

void deleteFROMposition(node*& head, node*& tail, int position) {
	if (position == 1) {
		deleteFROMfirst(head, tail);
	}
	else if (position == LLlength(head)) {
		deleteFROMlast(head, tail);
	}
	else {
		// Temporary node for handling address
		node* htemp = head;
		for (int i = 1; i <= position - 2; ++i) {
			htemp = htemp->next;
		}

		node* temp = htemp->next;
		node* temp2 = temp->next;
		htemp->next = temp2;
		delete temp, temp2;
	}
}

/***************************************************************************************************/

						/*     Linked List user Input function     */

/***************************************************************************************************/

// Function LL for input
// Read size from user and then take number of elements equal to size
// Input method followed here is insertion to last of LL
void LLinput(node*& head, node*& tail) {
	int size = 0;

	std::cout << std::endl << "Enter size for number of nodes: ";
	std::cin >> size;
	std::cout << std::endl << "Enter nodes data of Linked List: ";
	for (int i = 0; i < size; ++i) {
		int data = 0;
		std::cin >> data;
		insertATlast(head, tail, data);
	}
}

/***************************************************************************************************/

					                /*     Driver code     */

/***************************************************************************************************/

int main() {
	// Define starting head and ending tail pointers
	node* head = NULL;
	node* tail = NULL;

	// Size of node in an 64 bit machine will always be 16 bytes no matter what the datatype is.
	// HOW ? --> 4 bytes for data, 4 bytes for padding to align adress in remaining 8 bytes properly.
	std::cout << "Size of node: " << sizeof(node) << std::endl;

	// Insertion before head;
	insertATfirst(head, tail, 1);
	// deleteFROMfirst(head, tail);
	insertATfirst(head, tail, 2);
	// deleteFROMlast(head, tail);
	insertATfirst(head, tail, 3);

	// Insertion will only work if link list is not empty and minimum 3 nodes are present.
	/* Insertion at given position x
	insertATpos(head, tail, 2, 63);*/

	// insertion after tail
	insertATlast(head, tail, 4);
	insertATlast(head, tail, 5);
	insertATlast(head, tail, 6);

	// print function : argument passed is head pointer
	std::cout << std::endl << "Linked list after insertion: " << std::endl;
	printLL(head);

	// Insertion at given position x
	insertATpos(head, tail, 4, 52);
	std::cout << std::endl << "Linked list after inserting 52 at 4th position: " << std::endl;
	printLL(head);

	// deleting first element
	deleteFROMfirst(head, tail);
	std::cout << std::endl << "Linked list after deleting current first element: " << std::endl;
	printLL(head);

	// deleting last element
	deleteFROMlast(head, tail);
	std::cout << std::endl << "Linked list after deleting current last element: " << std::endl;
	printLL(head);

	// deleting element from selected position
	deleteFROMposition(head, tail, 3);
	std::cout << std::endl << "Linked list after deleting 3rd element: " << std::endl;
	printLL(head);

	// Calculate length and print it
	int length = LLlength(head);
	std::cout << std::endl << "Total length of linked list now: " << length << std::endl;

	// Take LL input according to user:
	// Creation of new linked list i.e, new head2 and tail2
	node* head2 = NULL;
	node* tail2 = NULL;

	// LL2 input function, argument passed are head2 and tail2
	LLinput(head2, tail2);
	// Print LL2
	std::cout << std::endl << "New Linked List: " << std::endl;
	printLL(head2);

	return 0;
}

// For checking for EMPTY nodes we can use:
// lLet's say we created a node pointer: node* p;
// for checking :
// if(!p)
// if(p == 0)
// if(p == NULL) <-- perfect to use
// Above three conditions can be used to check for an EMPTY node

// Similarly

// For checking for NON-EMPTY nodes we can use:
// lLet's say we created a node pointer: node* p;
// for checking :
// if(p)
// if(p != 0)
// if(p != NULL) <-- perfect to use
// Above three conditions can be used to check for an NON-EMPTY node


// For checking if NEXT NODE IS NULL we can use:
// for node* p;
// if(p->next == NULL)

// For checking if NEXT NODE IS NOT NULL we can use:
// for node* p;
// if(p->next != NULL)
