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

// Function for merging two sorted Linked Lists using pure recursion
node* merge_sort_LL(node* head1, node* head2) {
    // Check if Head is empty or becomes empty
    // then return head2 address (pointer).
    if (!head1) {
        return head2;
    }
    // If head1 is not empty then check for head2
    // if head2 is empty then return head1 address (pointer).
    else if (!head2) {
        return head1;
    }
    // If both of them are not not empty then proceed 
    // further for sorting.
    else {
        // Create a temporary head storing NULL at begenning
        // it will serve the purpose of head of the newly generated LL
        node* temphead = NULL;

        // if head1 data is smaller than head2 data then set temphead to
        // node pointer having small data value (it will start from it) and
        // for the next address to store in temphead->next
        // pass head->next and head2 in this function recursively.
        // It will check and store next increasing element address respectively.
        if (head1->data <= head2->data) {
            temphead = head1;
            temphead->next = merge_sort_LL(head1->next, head2);
        }
        // If head2 data is less than head1 data then temphead will
        // be at head2 (starting from head2) and for temphead->next pointing address,
        // head and head2->next will be passed in this function recursively.
        // Process continues till one LL either head1 or head2 ends.
        else {
            temphead = head2;
            temphead->next = merge_sort_LL(head1, head2->next);
        }

        // return the head node or head address or head pointer.
        return temphead;
    }
}

node* Merge_K_Sorted_Lists(node* head) {
    // --> base case
    // Check for empty head
    if (!head || !(head->next)) {
        return head;
    }

    // --> recursive case
    // Find the mid of linked list
    node* mid = find_mid(head);

    // left half will start from main head
    node* lhead = head;
    // right half will start from next node of mid
    node* rhead = mid->next;

    // Point mid->next to null to break the link of
    // right half list from left half list
    mid->next = NULL;

    // Sort both of the halfs
    node* left = Merge_K_Sorted_Lists(lhead);
    node* right = Merge_K_Sorted_Lists(rhead);

    // Merge them to form sorted single linked list.
    node* result = merge_sort_LL(left, right);

    return result;
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
    node* result = Merge_K_Sorted_Lists(head);

    // print result
    LL_output(result);

    return 0;
}
