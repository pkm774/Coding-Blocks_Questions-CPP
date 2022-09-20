#include <iostream>
#include <vector>
#include <algorithm>

// Function to multiply multiplicand with x.
void multiply(int x, std::vector<int> &multiplicand)
{
    // Initialize carry to 0
    int carry = 0;

    // Initialize iterator
    std::vector<int>::iterator i;

    for (i = multiplicand.begin(); i != multiplicand.end(); ++i)
    {
        // Multiply x with all digit of multiplicand.
        int prod = (*i) * x + carry;
        // Put only the last digit of product.
        *i = prod % 10;
        // Add remaining part with carry.
        carry = prod / 10;
    }

    // If carry is present then push it
    // in muplicand vector for further multiplication.
    while (carry)
    {
        multiplicand.push_back(carry % 10);
        carry = carry / 10;
    }
}

void factorial(int n)
{
    std::vector<int> result;

    // At first store 1 as result.
    result.push_back(1);

    // Multiply numbers 1*2*3*......*n.
    for (int i = 2; i <= n; i++)
    {
        multiply(i, result);
    }

    // Reverse the order of result.
    reverse(result.begin(), result.end());

    // Print result vector in reverse order.
    for (auto it : result)
    {
        std::cout << it;
    }
    std::cout << std::endl;
}

int main()
{
    int n;
    std::cin >> n;
    if (n < 1 || n > 500)
    {
        return 0;
    }
    factorial(n);
    return 0;
}
