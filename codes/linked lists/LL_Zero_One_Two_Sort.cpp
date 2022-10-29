#include <iostream>
#include <stack>

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void LL_input_back(node*& head, node*& tail, int dat) {
    node* n = new node(dat);

    if (head == nullptr && tail == nullptr) {
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

node* LL_Zero_One_Two_Sort(node* head) {
    if (!head || !(head->next)) {
        return head;
    }

    // New Node for holding 0, 1 and 2 values
    node* zeroHead = new node(-1);
    node* oneHead = new node(-1);
    node* twoHead = new node(-1);

    // nodes for traversing on zeroHead , oneHead and  twoHead
    node* zeroTail = zeroHead, * oneTail = oneHead, * twoTail = twoHead;

    // Attach each 0 to zeroTail, 1 to oneTail and 2 to twoTail
    // after traversing through original linked list and
    // make head to traverse at next node of head.
    while (head) {
        if (head->data == 0) {
            zeroTail->next = head;
            zeroTail = zeroTail->next;
        }
        else if(head->data == 1) {
            oneTail->next = head;
            oneTail = oneTail->next;
        }
        else {
            twoTail->next = head;
            twoTail = twoTail->next;
        }

        head = head->next;
    }
    
    // Case when '1' nodes are present
    if (oneHead->next) {
        zeroTail->next = oneHead->next;
    }
    // Case when '1' nodes are not present
    else {
        zeroTail->next = twoHead->next;
    }
    // Joint twos head to ones tail
    oneTail->next = twoHead->next;
    // twos tail will contain nullptr
    twoTail->next = nullptr;
    
    // Case when 0, 1 heads not exist
    // if 0s head exist then head will point 0s head
    if (zeroHead->next) {
        head = zeroHead->next;
    }
    // if 1s head exist then head will point 1s head
    else if(oneHead->next) {
        head = oneHead->next;
    }
    // or head will point 2s head.
    else {
        head = twoHead->next;
    }
    
    // Delete dummy pointers.
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main()
{
    // Input size
    int n = 0;
    std::cin >> n;

    // Create new ll from size
    node* head = nullptr;
    node* tail = nullptr;
    createLL(head, tail, n);

    // Arrange Linked List
    node* newhead = LL_Zero_One_Two_Sort(head);

    // print Sorted LL
    LL_output(newhead);

    return 0;
}