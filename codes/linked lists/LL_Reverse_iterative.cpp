#include <iostream>
#include <stack>

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

void LL_reverse_iterative(node* head, int length) {
    std::stack<int> data;
    node* head2 = head;

    for (int i = 0; i < length; ++i) {
        data.push(head2->data);
        head2 = head2->next;
    }

    while (!data.empty()) {
        head->data = data.top();
        data.pop();
        head = head->next;
    }
}

int main()
{
    // Input size
    int n = 0;
    std::cin >> n;

    // Create new ll from size
    node* head = NULL;
    node* tail = NULL;
    createLL(head, tail, n);

    // LL Reverse using iterative method
    LL_reverse_iterative(head, n);

    // print result
    LL_output(head);

    return 0;
}
