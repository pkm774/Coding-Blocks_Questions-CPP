#include <iostream>

class Node {
public:
	int data;
	Node* next;
};

void LL_input_back(Node*& head, Node*& tail, int dat) {
	Node* newnode = new Node;

	newnode->data = dat;
	newnode->next = NULL;

	if (head == NULL && tail == NULL) {
		head = newnode;
		tail = newnode;
	}
	else {
		tail->next = newnode;
		tail = newnode;
	}
}

void input_LL(Node*& head, Node*& tail) {
	int size = 0;
	std::cin >> size;

	while (size--) {
		int data = 0;
		std::cin >> data;

		LL_input_back(head, tail, data);
	}
}

void LL_output(Node* head) {
	while (head) {
		std::cout << head->data << " ";
		head = head->next;
	}
}

// Function to find length of Linked Lists
int LL_length(Node* head) {
	int count = 0;
	while (head) {
		++count;
		head = head->next;
	}
	return count;
}

// Function to append the last K element of a linked list to the front
void k_append_LL(Node*& head, int k) {

	// node for storing head address
	Node* prevhead = head;
	// node for tail modification
	Node* tail = head;

	// size of Linked List
	int size = LL_length(head);

	// if size is smaller than k, then
	// k will become k - size
	if (size < k) {
		k = k - size;
	}

	// set kth position variable i.e, size - k
	int pos = size - k;
	int pos2 = pos;

	// traverse head to the kth position
	while (pos--) {
		head = head->next;
	}

	// traverse tail to the size - 1 th pos
	while (size - 1) {
		tail = tail->next;
		--size;
	}

	// point tail to head.
	tail->next = prevhead;

	// iterate the tail back to new head
	while (pos2--) {
		tail = tail->next;
	}

	// set its next to null
	tail->next = NULL;
}

// Main driver function
int main() {
	// creation of Linked List
	Node* head = NULL;
	Node* tail = NULL;

	// Custom function to create n nodes Linked List
	input_LL(head, tail);

	// Numbers of last element to append at first
	int k = 0;
	std::cin >> k;

	// Function to append the last K elements
	// of a linked list to the front
	k_append_LL(head, k);

	// Custom function to print LL using range-based for-loop
	LL_output(head);
}
