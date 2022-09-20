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

// Function to print kth last element.
node* ll_k_reverse(node*& head, long long k) {
	// Check for empty LL
	if (head == NULL) {
		return head;
	}

	// Create prev, curr and next nodes.
	node* prev = NULL;
	node* curr = head;
	node* next = NULL;
	// Declare a count variable for keeping track
	// of number of reversed nodes.
	int count = 0;

	// While current is not null and count is less than k
	while (curr && count < k) {
		// next will hold n+1 element
		// make curr->next point to prev
		// now prev will become curr and
		// curr will become next.
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		// increase count
		++count;
	}

	// Recursive case call if next is not null.
	if (next) {
		// Reverse remaining elements.
		head->next = ll_k_reverse(next, k);
	}

	// return head i.e, prev
	return prev;
}

// main driver
int main() {
	long long n = 0, k = 0;
	std::cin >> n >> k;

	// Creation for LL with size.
	node* head = NULL;
	node* tail = NULL;
	createLL(head, tail, n);

	// Reverse upto k element.
	head = ll_k_reverse(head, k);

	LL_output(head);

	return 0;
}
