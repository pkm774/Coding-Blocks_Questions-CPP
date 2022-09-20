#include <iostream>

// Function to create n digit integers.
long long classAssignment(int n)
{
    // --> base case
    // If n becomes or is less than or equal to 2 then return n + 1.
    if (n <= 2)
    {
        return n + 1;
    }

    // --> recursive case
    // Add n - 1 and n - 2 elements
    return classAssignment(n - 1) + classAssignment(n - 2);
}

int main()
{
    // Input test case
    int test = 0;
    std::cin >> test;

    // Input n number of test cases
    for (int i = 1; i <= test; i++)
    {
        int n = 0;
        std::cin >> n;
        // Recursion call and print.
        std::cout << "#" << i << " : " << classAssignment(n) << std::endl;
    }

    return 0;
}
