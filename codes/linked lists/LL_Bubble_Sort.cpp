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

node* swap(node* n1, node* n2) {
    node* temp = n2->next;
    n2->next = n1;
    n1->next = temp;

    return n2;
}

node* LL_Bubble_Sort(node*& head, int size) {
    // Return if head is empty or for only one
    // node in LL.
    if (!head || !head->next)
        return head;

    // Iterative method from 0 to size-1
    for (int i = 0; i < size; ++i) {
        // Prev node for swapping head
        node* prev = nullptr;
        // current node for iterating through LL
        node* curr = head;
        // next node for
        node* next = curr->next;

        // While curr->next is true
        while (curr->next) {
            // If curr->data is greater than or equal to curr->next->data
            if (curr->data >= curr->next->data) {
                // For head case where prev = nullptr    // 5 4 3 2 1
                // swap head with next element.
                if (!prev) {
                    curr->next = next->next;
                    next->next = curr;
                    prev = next;
                    head = prev;
                }
                else {
                    next = curr->next; // 4 5 3 2 1
                    curr->next = next->next;
                    prev->next = next;
                    next->next = curr;
                    prev = next;
                }
            }
            else {
                // Store curr value to prev.
                prev = curr;
                // Iterate to next node.
                curr = curr->next;
            }
        }
    }

    return head;
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

    // Arrange Linked List
    LL_Bubble_Sort(head, n);

    // print Sorted LL
    LL_output(head);
    std::cout << std::endl;

    return 0;
}