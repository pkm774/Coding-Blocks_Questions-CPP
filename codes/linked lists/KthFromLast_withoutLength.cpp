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

// kth element using two pointer
void findKth_last(node* head, int kth) {
	// creating of main and reference pointer
	node* main = head;
	node* refr = head;

	// move reference pointer kth times forward in LL
	int count = 1;
	while (count <= kth) {
		refr = refr->next;
		++count;
	}

	// move main forward until reference node becomes null
	// For LL = 1 2 3 4 5 6 and kth = 3 ; ans will be 4
	// for above case :
	// --------------------------------------
	// variable | cur pos   next  next  next
	// --------------------------------------
	//   main   |    1       2     3     4
	//   refr   |    4       5     6    NULL
	while (refr) {
		main = main->next;
		refr = refr->next;
	}

	// print the data of main pointer
	// it will be kth element from last
	std::cout << main->data << std::endl;
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
	// print kth element
	findKth_last(head, kth);

	return 0;
}
