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

void createLL(node*& head, node*& tail, int size) {
    int data = 0;
    for (int i = 0; i < size; ++i) {
        std::cin >> data;
        LL_input_back(head, tail, data);
    }
}

void LL_output(node* head) {
	while (head) {
		std::cout << head->data << " ";
		head = head->next;
	}
	std::cout << std::endl;
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

node* addTwoNumbers(node* head1, node* head2) {
	// Create new head for answer linked list.
	node* head3 = NULL;
	// Carry variable for carry operation.
	int carry = 0;

	// Iterate while either ll head1 or ll head2 becomes null
	// or cary becomes zero
	while (head1 != NULL || head2 != NULL || carry != 0)
	{
		// Sum variable for calculating current sum
		int sum = 0;

		// Get head1 data in sum.
		if (head1 != NULL)
		{
			sum += head1->data;
			head1 = head1->next;
		}
		// Add head1 data with head2 data
		if (head2 != NULL)
		{
			sum += head2->data;
			head2 = head2->next;
		}

		// Add carry in sum
		sum += carry;
		// Create a new node and push data in it.
		node* newnode = new node;
		newnode->data = sum % 10;
		newnode->next = NULL;
		// Add remaining numbers except sum % 10 in carry.
		carry = sum / 10;

		// To add the nodes in the newly created list
		// First check if new head3 is empty or not.
		if (head3 == NULL)
		{
			// If node3 is empty then point the currnt head3 to newnode.
			head3 = newnode;
		}
		// If the head3 is not empty then :
		else {
			// add other newnodes and form a list.
			node* temp = head3;
			// Iterate to the last element of head3.
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			// Add newnode at the last.
			temp->next = newnode;
		}
	}

	// Return address of head3 after completing sum operation.
	return head3;
}

int main() {
	int size = 0, size2 = 0;
	std::cin >> size >> size2;

	// LL1
	node* head1 = NULL;
	node* tail1 = NULL;
	createLL(head1, tail1, size);
	// Reverse input LL1
	ll_reverse(head1);

	// LL2
	node* head2 = NULL;
	node* tail2 = NULL;
	createLL(head2, tail2, size2);
	// Reverse input LL2
	ll_reverse(head2);

	node* head3 = NULL;
	// Get newly generated sum linked list
	head3 = addTwoNumbers(head1, head2);
	// Reverse sum LL
	ll_reverse(head3);
	// Print SUM LL
	LL_output(head3);

	return 0;
}
