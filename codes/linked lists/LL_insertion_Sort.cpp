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

// base function for insertion sort for linked list
void insert_sorted(node* curr, node*& newll) {

	// case 1 : when newll is empty i.e, NULL
	//          or newll->data >= curr->data
	// thhen :
	if (newll == NULL || newll->data >= curr->data) {
		// curr->next will point to newll node and
		curr->next = newll;
		// newll will become current
		newll = curr;
	}
	// case 2 : when newll is not NULL and
	//          curr->data is greater than newll data
	else {
		// create a temp node to hold the adress
		// of ll starting from newll node
		node* temp = newll;

		// traverse through ll starting from temp node
		// until temp->next become NULL and
		// temp->next->data is less than curr->data
		while (temp->next != NULL && temp->next->data < curr->data) {
			temp = temp->next;
		}

		// after reaching to the node holding less value than curr->data
		// set curr->next to temp->next
		// i.e, temp->next = NULL (last element) or temp->next = next node adress
		curr->next = temp->next;
		// set temp->next to current
		temp->next = curr;
	}

}

// function insertion sort for linked list
node* insertion_sort(node* head) {
	// set curr to head
	node* curr = head;

	// create a empty newll node head which will be
	// used to create sorted linked list
	node* newll = NULL;

	// traverse through each element of ll
	// and push value by value to get inserted in newll
	// in sorted order
	while (curr) {
		// create a nxt pointer and point it to the
		// curr->nxt address
		node* nxt = curr->next;

		// pass the curr and and newll.
		// data will get compared and sorted
		// into newll
		insert_sorted(curr, newll);

		// set curr to next value of nxt.
		// curr = curr->next cannot be used because
		// curr->next will hold null after returning from
		// insert_sorted(curr, newll);
		curr = nxt;
	}

	// return head pointer of newll
	return newll;
}

int main() {
	int size = 0;
	std::cin >> size;

	// create new ll
	node* head = NULL;
	node* tail = NULL;
	createLL(head, tail, size);

	// print original ll
	LL_output(head);

	// set newll to the returned adress of sorted ll
	node* newll = insertion_sort(head);

	// print sorted ll
	LL_output(newll);

	return 0;
}
