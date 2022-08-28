#include <iostream>

class node {
public:
	int data;
	node* next;
};

// Function to calculate numbers of nodes or length of linked list
int LLlength(node*& head) {
	int count = 0;
	node* temp = head;
	while (temp != NULL) {
		++count;
		temp = temp->next;
	}
	delete temp;
	return count;
}

// Function to print data from nodes of link list
void printLL(node*& head) {
	node* temp = head;
	while (temp != NULL) {
		std::cout << temp->data << " --> ";
		temp = temp->next;
	}
	delete temp;
	std::cout << "NULL" << std::endl;
}

// Function to insert element at last, head and tail are passed by reference
void insertATlast(node*& head, node*& tail, int dat) {
	// creating new node having data and pointer element
	node* n = new node;

	// filling elements of node n
	n->data = dat;
	n->next = NULL;

	// if head and tail pointer holds null then put the adress of n into both
	if (head == NULL && tail == NULL) {
		head = n;
		tail = n;
	}
	// if tail pointer is not empty then put the adress of n in tail
	// and change the position of tail to current n;
	else {
		tail->next = n;
		tail = n;
	}
}

int findKey(node* head, int key) {
	int size = LLlength(head);
	for (int i = 0; i < size;) {
		if (head->data == key) {
			return i + 1;
		}
		++i;
		head = head->next;
	}
	return 0;
}

int main() {
	node* head = NULL;
	node* tail = NULL;
	int key = 0;

	insertATlast(head, tail, 1);
	insertATlast(head, tail, 3);
	insertATlast(head, tail, 8);
	insertATlast(head, tail, 99);
	insertATlast(head, tail, 5);
	insertATlast(head, tail, 4);

	printLL(head);

	key = 99;
	// key = 100;

	int pos = findKey(head, key);

	if (pos) {
		std::cout << "Key found at : " << pos << std::endl;
	}
	else {
		std::cout << "Key found not !" << std::endl;
	}

	return 0;
}
