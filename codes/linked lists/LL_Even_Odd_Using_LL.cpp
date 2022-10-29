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

node* Even_Odd_Using_LL(node* head)
{
    // New Node for holding odd and even values.
    node* oddHead = NULL;
    node* evenHead = NULL;

    // nodes for traversing on oddHead and evenHead.
    node* oddTail = NULL, * evenTail = NULL;

    // While will continue till head is not null
    while (head)
    {
        // Attach each even node to evenTail
        if (head->data % 2 == 0)
        {
            // If evenHead is empty then point
            // evenHead & evenTail to the head node
            // This task is for one time only when
            // evenHead is null.
            if (!evenHead)
            {
                // Point evenHead & evenTail to the head node.
                evenHead = head;
                evenTail = head;
            }
            // When evenHead is not null.
            else
            {
                // Attach node to evenTail.
                evenTail->next = head;
                // Iterate evenTail to the attached node.
                evenTail = evenTail->next;
            }
        }
        // Attach odd node to oddTail
        else
        {
            // If oddHead is empty then point
            // oddHead & oddTail to the head node
            // This task is also for one time only when
            // oddHead is null.
            if (!oddHead)
            {
                // Point oddHead & oddTail to the head node.
                oddHead = head;
                oddTail = head;
            }
            else
            {
                // Attach node to oddTail.
                oddTail->next = head;
                // Iterate oddTail to the attached node.
                oddTail = oddTail->next;
            }
        }

        // Point head to its next value for
        // further iteration.
        head = head->next;
    }

    // If oddTail is empty means there are no odd values
    // in the Linked List .
    // If oddTail exist then attach evenHead node to oddTail next
    if(oddTail) oddTail->next = evenHead;

    // If there are no even values in Linked List then
    // evenHead and evenTail will not exist and will contain NULL
    // and odd linked list will be terminate by NULL automatically
    // due to line no 107.
    // If evenTail exist Terminate evenTail with NULL.
    if(evenTail) evenTail->next = NULL;

    // Case when oddHead node is not NULL
    if (oddHead)
    {
        // Return oddHead as starting node of LL.
        return oddHead;
    }
    // If odd linked list is not formed then
    else
    {
        // Return evenHead as starting node of LL.
        return evenHead;
    }
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
    node* newhead = Even_Odd_Using_LL(head);

    // print Sorted LL
    LL_output(newhead);

    return 0;
}