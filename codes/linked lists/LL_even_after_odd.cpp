#include <iostream>

class node {
public:
	int data;
	node* next;
};

// Tail input
void LL_input_back(node*& head, node*& tail, int dat) {
	node* n = new node;

	n->data = dat;
	n->next = NULL;

	if (head == NULL && tail == NULL) {
		head = n;
		tail = n;
	}
	else {
		tail->next = n;
		tail = n;
	}
}

// Create LL with  a given size
void createLL(node*& head, node*& tail, int size) {
	for (int i = 0; i < size; ++i) {
		int data = 0;
		std::cin >> data;
		LL_input_back(head, tail, data);
	}
}

// Function fo printing LL
void LL_output(node* head) {
	while (head) {
		std::cout << head->data << " ";
		head = head->next;
	}
}

// Function to print even after odd
node* even_after_odd(node* head) {
	// Create and empty, the first odd node with 0 as data.
	node* oddhead = new node;
	oddhead->data = 0;
	oddhead->next = NULL;

	// Create and empty, first even node with 0 as data.
	node* evenhead = new node;
	evenhead->data = 0;
	evenhead->next = NULL;

	// Two pointers for iterating through oddhead and evenhead
	node* odd = oddhead;
	node* even = evenhead;

	// Iterate till head reaches last node
	while (head)
	{
		// If head data is odd then :
		if (head->data & 1)
		{
			// Point next of the odd node to
			// the current node having odd data.
			odd->next = head;
			// Set current odd to its next node.
			odd = odd->next;
		}
		// Else if head data is even then :
		else
		{
			// Point next of the even node to
			// the current node having even data.
			even->next = head;
			// Set current even to its next node.
			even = even->next;
		}

		// Iterate through next nodes.
		head = head->next;
	}

	// Joint linked lists formed through oddhead and evenhead.
	// Point odd->next (last odd node's next) to the next node
	// of evenhead, because evenhead contains 0 as node data.
	odd->next = evenhead->next;
	// Put NULL in the next of last node.
	even->next = NULL;
	// De-atach evenhead.
	evenhead->next = NULL;
	// Delete evenhead node.
	delete evenhead;

	// Return next node of oddhead because oddhead is starting
	// from 0.
	return oddhead->next;
}

// main driver
int main() {
	int size = 0;
	std::cin >> size;

	// Creation for LL with size.
	node* head = NULL;
	node* tail = NULL;
	createLL(head, tail, size);

	// Print all odd numbers before even numbers.
	node* odd_head = even_after_odd(head);

	LL_output(odd_head);

	return 0;
}
