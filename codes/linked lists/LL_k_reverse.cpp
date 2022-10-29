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
    int data = 0;
    for (int i = 0; i < size; ++i) {
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
	if (!head) {
		return head;
	}

	// Create prev, curr and next nodes.
	node* prev = NULL;
	node* curr = head;
	node* next = NULL;

	// Declare a count variable for reversing k nodes.
	// Means 1,2 and 3
	int count = 1;

	// While current is not null and count is less than k
	while (curr && count <= k) {
		// Point next to next node of curr node,
		// next will hold n-1 nodes after curr node.
		next = curr->next;
		// make curr->next point to prev for linking
		// current node with previous one.
		curr->next = prev;
		// Make prev to curr so that next node will be
		// linked to current prev.
		prev = curr;
		// Make curr to next for further iteration
		// and reverse operation.
		curr = next;
		// Increase count with 1 for comparing with k.
		++count;
	}

	// next will now hold remaining (total number of nodes - k) nodes,
	// means it will be pointing to next node after previous k nodes.
	// If next is not null means further node exists then,
	// reverse remaining nodes with recursive call and link them
	// to head node.
	if (next) {
		// head will hold the last node of reversed linked list,
		// link remaining reversed lists.
		head->next = ll_k_reverse(next, k);
	}

	// next is null means no further reverse operations,
	// therefor return prev which is the head node of
	// current reversed linked list.
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
