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

int main() {
	long long size = 0;
	std::cin >> size;

	node* head = NULL;
	node* tail = NULL;
	createLL(head, tail, size);

	node* newll = ll_reverse(head);

	LL_output(newll);

	return 0;
}
