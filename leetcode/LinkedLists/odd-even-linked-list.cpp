#include <iostream>

/**
 * Definition for singly-linked list.
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/***********************  Solution  ********************************/

class Solution
{
private:
    // Function for calculating LL size
    int LL_Length(ListNode *head)
    {
        int count = 0;

        while (head)
        {
            ++count;
            head = head->next;
        }

        return count;
    }

public:
    ListNode *oddEvenList(ListNode *head)
    {
        // If Linked List is empty then return
        // received empty head
        if (!head)
        {
            return head;
        }

        // New Node for holding odd and even values
        ListNode *oddHead = new ListNode(0);
        ListNode *evenHead = new ListNode(0);

        // nodes for traversing on oddHead and evenHead
        ListNode *oddTail = oddHead, *evenTail = evenHead;

        // n will contain total nodes in linked list
        int n = LL_Length(head);
        // Index will start from 1
        int index = 1;

        // While will continue till head is not null and
        // index value is less than or equal to n
        while (head && (index <= n))
        {
            // Attach each even index nodes to evenTail
            if (index % 2 == 0)
            {
                evenTail->next = head;
                // Iterate evenTail to the attached node.
                evenTail = evenTail->next;
            }
            // Attach odd index nodes to oddTail
            else
            {
                oddTail->next = head;
                oddTail = oddTail->next;
            }

            // Point head to its next value for
            // further iteration.
            head = head->next;
            // Increment in index value
            ++index;
        }

        // terminate evenTail with nullptr.
        evenTail->next = nullptr;

        // Case when even nodes are present
        if (evenHead->next)
        {
            // Attach evenHead next node to oddTail
            oddTail->next = evenHead->next;
        }
        // Case when even nodes are not present
        else
        {
            // Terminate oddTail with nullptr
            oddTail->next = nullptr;
        }

        // Case when oddHead next node is not empty
        if (oddHead->next)
        {
            // Head will hold new LL starting from
            // oddhead's next nodes.
            head = oddHead->next;
        }
        // or Head will hold LL starting from
        // evenHead's next nodes.
        else
        {
            head = evenHead->next;
        }

        // Delete dummy Head pointers.
        delete oddHead;
        delete evenHead;

        // Return new formed Linked List
        return head;
    }
};