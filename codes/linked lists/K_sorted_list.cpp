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
    for (int i = 0; i < size; ++i) {
        int data = 0;
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

// Function to find mid of Linked List
node* find_mid(node* head) {
    node* slow = head;
    node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void K_sort_list(node* head) {

}

int main()
{
    // Input size
    int n = 0, k = 0;
    std::cin >> n >> k;

    // Create new ll from size
    node* head = NULL;
    node* tail = NULL;
    createLL(head, tail, n*k);

    // Sort the ll
    K_sort_list(head);

    return 0;
}
