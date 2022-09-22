#include <iostream>
#include <stack>

// Method 2 : for CIRCULAR Array,
// Checking from first element with i%n logic.
void next_Greater_Element_2(int* arr, int* ans, int n) {
    std::stack<int> stak;

    // Start checking from the last element.
    for (int i = n - 1; i >= 0; --i) {
        // Check first if stack is empty or not, then 
        // access its element for comparing.
        // Next check if the element at the ith index is 
        // smaller than top element of the stack or not.
        if (!stak.empty() && arr[i] <= stak.top()) {
            // If element is smaller from the stack's top element
            // Then push it inside the ans vetor at ith%size index.
            ans[i] = stak.top();
        }
        // If ith index element is greater (is not smaller) from the 
        // stack's top element then :
        else {
            // Pop stack's top element till the ith index element 
            // become smaller than or equal to ith index element.
            while (!stak.empty() && arr[i] >= stak.top()) {
                stak.pop();
            }

            // If stack is not empty then push the previous pushed 
            // top element at i index. This logic avoids consecutive
            // next greater element checking logic.
            // Comment out if() condition for implementation.
            if (!stak.empty()) {
                ans[i] = stak.top();
            }
            else {
                ans[i] = -1;
            }
                
        }

        // Push the current ith element in stack for
        // checking previous than current element at ith index.
        stak.push(arr[i]);
    }
}

// Function to print Next Greater Element for each element of the array
void nextGreater(int* arr, int n)
{
    // Write Code here
    int* ans{ new int [n] {-1} };

    next_Greater_Element_2(arr, ans, n);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << "," << ans[i] << std::endl;
    }
}

// The Main Function
int main()
{
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int* arr{ new int [n] {0} };
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        nextGreater(arr, n);
    }

    return 0;
}