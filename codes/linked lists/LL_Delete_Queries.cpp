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

void LL_Delete_Queries(node*& head, int query) {
    node* prev = NULL;
    node* curr = head;

    // For head node i.e, query == 0
    if (query == 0) {
        prev = head;
        head = head->next;
        free(prev);
        return;
    }

    // For all nodes except head.
    for (int i = 0; i < query; ++i) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    free(curr);

}

int main()
{
    // Input size
    int n = 0, tq = 0;
    std::cin >> n >> tq;

    // Create new ll from size
    node* head = NULL;
    node* tail = NULL;
    createLL(head, tail, n);

    // Delete From Linked List (Q Queries)
    while (tq--) {
        int q = 0;
        std::cin >> q;
        LL_Delete_Queries(head, q);

        // print result
        LL_output(head);

        std::cout << std::endl;
    }

    return 0;
}
