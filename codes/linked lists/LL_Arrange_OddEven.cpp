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

void LL_Arrange_OddEven(node* head, int size) {
    // Prev pointer for keeping previous node records
    node* prev = NULL;

    // Even head parent node having
    // -1 as initial value and nulptr in next.
    node* ehead = new node;
    ehead->data = -1;
    ehead->next = nullptr;
    // Even head iteration node
    node* ehd = ehead;

    for (int i = 1; i <= size; ++i) {
        // If head node index position is odd then put
        // current value in prev and iterate head to
        // its next node.
        if (i % 2 != 0) {
            prev = head;
            // If next exist
            if (head->next) {
                // Iterate to next
                head = head->next;
            }
        }
        // If head node index position is even then
        // point ehd (Even head iteration node) next to
        // head and iterate ehd to its next node
        // for further joining of even nodes.
        else {
            ehd->next = head;
            ehd = ehd->next;
            
            // Prev will be at odd position and
            // head will be at even position so
            // point prev->next to next node of head
            // which will be at odd position;
            prev->next = head->next;
            // not head will be at the next node of prev
            // having odd position.
            head = prev->next;
        }
    }

    // Temp node for holding -1 value
    node* temp = ehead;
    // put nullptr in the end node of of ehd
    ehd->next = nullptr;
    // prev will be at last odd node
    // make it point to 2nd node of ehead.
    prev->next = ehead->next;
    // free temp memory.
    free(temp);
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

    // print original LL
    std::cout << "Original List: "; LL_output(head); std::cout << std::endl;

    // Arrange Linked List
    LL_Arrange_OddEven(head, n);

    // print modified LL
    std::cout << "Modified List: "; LL_output(head); std::cout << std::endl;

    return 0;
}