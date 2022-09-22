#include <iostream>
#include <queue>
#include <set>

class Stack {
private:
    std::queue<int> q1;
    std::queue<int> q2;
public:
    void push(int data) {
        // Push data first in empty q2
        q2.push(data);

        // Push all the remaining
        // elements in q1 to q2.
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // swap the names of two queues
        std::queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop() {
        // if no elements are there in q1
        if (q1.empty()) {
            return;
        }

        q1.pop();
    }

    int top()
    {
        if (q1.empty()) {
            return -1;
        }

        return q1.front();
    }

    int size()
    {
        return q1.size();
    }

    bool empty() {
        if (q1.empty()) {
            return true;
        }

        return false;
    }
};

// Recursive function to print stack elements
// in reverse order.
void Print_rev_Stack(Stack S) {
    // If stack is empty then return
    if (S.empty()) {
        return;
    }

    // Store current data in x
    int x = S.top();

    // Pop the top element of the stack
    S.pop();

    // Recursively call the function PrintStack
    Print_rev_Stack(S);

    // Print the stack element starting
    // from the bottom
    std::cout << x << " ";

    // Push the same element onto the stack
    // to preserve the order
    S.push(x);
}

int main() {
    // Create stack
    Stack S;

    // Create a set for auto sorting
    /* Print using set */
    // std::set<int> s;

    // Size and order of data
    int size = 0;
    std::cin >> size;

    // Insert numbers in stack in the order from 0 to size-1
    for (int i = 0; i < size; ++i) {
        S.push(i);
    }

    /* Print using set */
    /*for (int i = 0; i < size; ++i) {
        s.insert(S.top());
        S.pop();
    }

    for (auto i : s) {
        std::cout << i << " ";
    }*/
    Print_rev_Stack(S);
    std::cout << std::endl;

    return 0;
}
