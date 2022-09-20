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
	for (long long i = 0; i < size; ++i) {
		long long data = 0;
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

/* Function to reverse the linked list */
void printReverse(node* head)
{
	// Base case
	if (head == NULL)
		return;

	// print the list after head node
	printReverse(head->next);

	// After everything else is printed, print head
	std::cout << head->data << " ";
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

// Function to Delete nodes which have
// smaller value node on left side.
void delNodes(struct node* head)
{
	// Set current to head and temp to null
	struct node* current = head;
	struct node* temp = NULL;

	// Initialize max, used for comparing
	struct node* maxnode = head;

	while (current && current->next) {
		// If current is greater than max,
		// then update max and move current
		if (current->next->data >= maxnode->data) {
			current = current->next;
			maxnode = current;
		}
		// If current is smaller than max, then delete current
		else {
			temp = current->next;
			current->next = temp->next;
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

	// Reverse current node to reduce complexity
	ll_reverse(head);

	// Delete nodes.
	delNodes(head);

	// Use recursion to print nodes in reverse
	printReverse(head);
	std::cout << std::endl;

	return 0;
}
