#include <iostream>

class node {
public:
	int data;
	node* next;
};

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

// Function to find length of Linked Lists
int length_of_LL(node* head) {
	int count = 0;
	while (head) {
		++count;
		head = head->next;
	}
	return count;
}

// Function to print kth last element.
void kthLast_using_length(node* head, int length, int kth) {
	// Calculate position
	// starting from index 0 therefore length - kth + 1 isn't necessary
	// else while condition will be indx<pos-1
	int pos = length - kth;

  // Make head to reach that position
	int indx = 0;
	while (indx < pos) {
		head = head->next;
		++indx;
	}

  // print the data of that node lying at position
	std::cout << head->data << std::endl;
}

// main driver
int main() {
	// creation for LL without size.
	// node with input data will be created.
	// input terminates if -1 is entered
	node* head = NULL;
	node* tail = NULL;
	while (true) {
		int input = 0;
		std::cin >> input;
		if (input == -1) break;
		LL_input_back(head, tail, input);
	}

	// kth element from last excluding 0
	int kth = 0;
	std::cin >> kth;

	// calculate LL size
	int size = length_of_LL(head);

	// find and print kth from last using length
	kthLast_using_length(head, size, kth);

	return 0;
}
