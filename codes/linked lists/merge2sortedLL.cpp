#include <iostream>

class node {
public:
	int data;
	node* next;
};

// Funtion for new node creation with data
// Using push at last algo
void LL_input_back(node*& head, node*& tail, int dat) {
	node* newnode = new node;

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

// Function for data input from user
// Saves data to nodes with help of LL_input_back()
void take_input_LL(node*& head, node*& tail) {
	int size = 0;
	std::cin >> size;

	while (size--) {
		int data = 0;
		std::cin >> data;
		LL_input_back(head, tail, data);
	}
}

// Function to print Linked List
void LL_output(node* head) {
	while (head) {
		std::cout << head->data << " ";
		head = head->next;
	}
}

// Function for merging two sorted Linked Lists using pure recursion
node* merge_sort_LL(node* head1, node* head2) {
	// Check if Head is empty or becomes empty
	// then return head2 address (pointer)
	if (!head1) {
		return head2;
	}
	// If head1 is not empty then check for head2
	// if head2 is empty then return head1 address (pointer)
	else if(!head2) {
		return head1;
	}
	else {
		// Create a temporary head storing NULL at begenning
		// it will serve the purpose of head of the newly generated LL
		node* temphead = NULL;

		// if head1 data is smaller than head2 data then set temphead to
		// node pointer having small data value (it will start from it) and
		// for the next address to store in temphead->next
		// pass head->next and head2 in this function recursively.
		// It will check and store next increasing element address respectively.
		if (head1->data <= head2->data) {
			temphead = head1;
			temphead->next = merge_sort_LL(head1->next, head2);
		}
		// If head2 data is less than head1 data then temphead will
		// be at head2 (starting from head2) and for temphead->next pointing address,
		// head and head2->next will be passed in this function recursively.
		// Process continues till one LL either head1 or head2 ends.
		else {
			temphead = head2;
			temphead->next = merge_sort_LL(head1, head2->next);
		}

		// return the head node or head address or head pointer
		return temphead;
	}
}

int main() {
	int test = 0;
	std::cin >> test;

	while (test--) {
		// Creation of head and tail for LL1
		node* head1 = NULL;
		node* tail1 = NULL;
		// Input for LL1
		take_input_LL(head1, tail1);

		// Creation of head and tail for LL2
		node* head2 = NULL;
		node* tail2 = NULL;
		// Input for LL2
		take_input_LL(head2, tail2);

		// Get head of resulting LL
		node* resultLL = merge_sort_LL(head1, head2);
		// Print that LL
		LL_output(resultLL);
		// Move control to next line for printing next output
		// clearly in case of test > 1.
		std::cout << std::endl;
	}

	return 0;
}
