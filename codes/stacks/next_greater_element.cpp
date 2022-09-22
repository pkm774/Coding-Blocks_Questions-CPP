#include <iostream>
#include <vector>
#include <stack>

// Method 1 : for NON-CIRCULAR Array,
// Checking from last element of array.
void next_Greater_Element(std::vector<long long>& arr,
    std::vector<long long>& ans, std::stack<long long>& stak) {

    // Save size of the input vector
    int size = arr.size();

    // Start checking from size-1 of the input vector. 
    for (int i = size - 1; i >= 0; --i) {
        // Check first if stack is empty or not, then 
        // access its element for comparing.
        // Next check if the element at the ith index is 
        // smaller than top element of the stack or not.
        if (!stak.empty() && arr[i] < stak.top()) {
            // If element is smaller from the stack's top element
            // Then push it inside the ans vetor.
            ans[i] = stak.top();
        }
        // If ith index element greater (is not smaller) from the 
        // stack's top element then :
        else {
            // Pop stack element till the ith index element 
            // become smaller than or equal to ith index element.
            while (!stak.empty() && arr[i] > stak.top()) {
                stak.pop();
            }
            // If stack is not empty then push the previous pushed 
            // top element at i index. This logic avoids consecutive
            // next greater element checking logic.
            // Comment out if() condition for implementation.
            /* if(!stak.empty()){
                ans[i] = stak.top();
            }*/
        }

        // Push the current ith element in stack for
        // checking previous than current element at ith index.
        stak.push(arr[i]);
    }
}

// Method 2 : for CIRCULAR Array,
// Checking from first element with i%n logic.
void next_Greater_Element_2(std::vector<long long>& arr,
    std::vector<long long>& ans, std::stack<long long>& stak) {

    // Save size of the input vector
    int size = arr.size();

    // Start checking from the last element.
    for (int i = (size * 2) - 1; i >= 0; --i) {
        // Check first if stack is empty or not, then 
        // access its element for comparing.
        // Next check if the element at the ith%size index is 
        // smaller than top element of the stack or not.
        if (!stak.empty() && arr[i % size] <= stak.top()) {
            // If element is smaller from the stack's top element
            // Then push it inside the ans vetor at ith%size index.
            ans[i % size] = stak.top();
        }
        // If ith%size index element is greater (is not smaller) from the 
        // stack's top element then :
        else {
            // Pop stack's top element till the ith%size index element 
            // become smaller than or equal to ith index element.
            while (!stak.empty() && arr[i % size] >= stak.top()) {
                stak.pop();
            }
            // If stack is not empty then push the previous pushed 
            // top element at i%size index. This logic avoids consecutive
            // next greater element checking logic.
            // Comment out if() condition for implementation.
            /* if(!stak.empty()){
                ans[i % size] = stak.top();
            }*/
        }

        // Push the current ith element in stack for
        // checking previous than current element at ith%size index.
        stak.push(arr[i % size]);
    }
}

int main() {
    int size = 0;
    std::cin >> size;

    // Input vector
    std::vector<long long> arr(size);
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    // Vector for storing ans
    // Initialize all elements with -1
    std::vector<long long> ans(size, -1);
    // Stack for comparesion
    std::stack<long long> stak;

    // Using Method 1
    // next_Greater_Element(arr, ans, stak);

    // Using Method 1
    next_Greater_Element_2(arr, ans, stak);

    // Print answer vector;
    for (int i = 0; i < size; ++i) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
