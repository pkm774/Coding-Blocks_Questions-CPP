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

// Function to reverse linked list
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

void checkPalindrome(node* head) {
    // Single node check
    // Segfault with single node.
    if (head->next == NULL) {
        std::cout << "true" << std::endl;
    }

    // Find out the mid node of the Linked List
    node* mid = find_mid(head);
    // Point next_nodes to the next node of mid
    node* next_nodes = mid->next;
    // Reverse the nodes starting from next_nodes and
    // connect reversed Linked List to parent Linked List.
    mid->next = ll_reverse(next_nodes);

    // Point fhead to the starting head of the Linked List
    node* fhead = head;
    // Point shead to the next node of mid from
    // where Linked List is reversed.
    node* shead = mid->next;
    // Check till shead becomes null; 
    while (shead) {
        if (fhead->data != shead->data) {
            // If node's data did not matches then
            // its not palindrome, cout and return
            std::cout << "false" << std::endl;
            return;
        }
        // Iterate through nodes if data matches
        fhead = fhead->next;
        shead = shead->next;
    }
    // Control is here means ll is a palindrome ll.
    std::cout << "true" << std::endl;

    // Reverse again to form original linked list.
    // (Optional step)
    mid->next = ll_reverse(next_nodes);
}

int main()
{
    // Input size
    int size = 0;
    std::cin >> size;

    // Create new ll from size
    node* head = NULL;
    node* tail = NULL;
    createLL(head, tail, size);

    // Check for palindrome
    checkPalindrome(head);

    return 0;
}
