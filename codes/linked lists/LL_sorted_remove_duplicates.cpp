#include <iostream>

class node {
public:
	long long data;
	node* next;
};

void LL_input_back(node*& head, node*& tail, long long dat) {
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

void createLL(node*& head, node*& tail, long long size) {
    long long data = 0;
    for (long long i = 0; i < size; ++i) {
        std::cin >> data;
        LL_input_back(head, tail, data);
    }
}

void LL_output(node* head) {
	while (head) {
		std::cout << head->data << " ";
		head = head->next;
	}
}

node* ll_reverse(node*& head) {
	node* prev = NULL;
	node* curr = head;

	while (curr) {
		node* nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}

	head = prev;
	return head;
}

// Function to print Linked List in reverse order
void printReverse(node* head)
{
	// Base case
	if (head == NULL) {
		return;
	}

	// print the list after head node
	printReverse(head->next);

	// After everything else is printed, print head
	std::cout << head->data << " ";
}

// Function to Delete the nodes having
// smaller value node at the left side.
void delete_duplicates_sorted(node* head) {
	// Set current to head and temp to null.
	node* curr = head;
	// Initialize prev also to head.
	node* prev = head;

	// Iterate till link list ends.
	while (curr && curr->next) {
		// If current's next node data is not equal to prev data,
		// then move current to it's next node and prev will
		// become current.
		if (curr->next->data != prev->data) {
			curr = curr->next;
			prev = curr;
		}
		// If current's next node data is not equal current's data
		// then point temp to that node, make current's next to
		// point temp's next, and free temp from memory.
		else {
			// Temp node for deleting nodes.
			node* temp = curr->next;
			curr->next = temp->next;
			free(temp);
		}
	}
}

int main() {
	long long size = 0;
	std::cin >> size;

	node* head = NULL;
	node* tail = NULL;
	createLL(head, tail, size);

	// Reverse the input Linked List to reduce complexity.
	ll_reverse(head);

	// Delete equal nodes.
	delete_duplicates_sorted(head);

	// Use recursion to print nodes in reverse order.
	printReverse(head);
	std::cout << std::endl;

	return 0;
}
