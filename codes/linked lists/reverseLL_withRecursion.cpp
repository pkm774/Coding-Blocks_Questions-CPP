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
}

node* rev_LL_rec(node*& head) {
	// base
	if (head->next == NULL) {
		return head;
	}

	// recursive
	node* temp = rev_LL_rec(head->next);
	head->next->next = head;
	head->next = NULL;

	// return head
	return temp;
}

int main() {
	int size = 0;
	std::cin >> size;

	node* head = NULL;
	node* tail = NULL;
	createLL(head, tail, size);

	node* rev_head = rev_LL_rec(head);

	LL_output(rev_head);

	return 0;
}
