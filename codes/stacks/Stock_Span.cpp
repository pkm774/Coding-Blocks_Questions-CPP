#include <iostream>
#include <vector>
#include <stack>

std::vector<int> stockSpan(std::vector<int>& price)
{
    // Store the size of the array in n
    int n = price.size();

    // Answer vector for storing index value
    std::vector<int> ans(n, 0);
    //Stack to store indices
    std::stack<int> s;

    // Initially push 0 in stack and 1 in answer vector
    s.push(0);
    ans[0] = 1;

    // Start from one
    for (int i = 1; i < n; i++)
    {
        // Pop element from stack untill new element
        // is greater than the element present at
        // the ith index from stack element i.
        while (!s.empty() && price[s.top()] <= price[i])
        {
            s.pop();
        }

        // If stack is empty then current
        // element is the greatest so far.
        if (s.empty())
        {
            ans[i] = i + 1;
        }
        // Current element is greater than elements after s.top()
        else
        {
            ans[i] = i - s.top();
        }

        // Push the current i in stack.
        s.push(i);
    }

    // Return answer vector.
    return ans;
}

int main() {
	int size = 0;
	std::cin >> size;

	std::vector<int> arr(size);
	for (int i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}

    std::vector<int> ans;
    ans = stockSpan(arr);

    for (auto i : ans) {
        std::cout << i << " ";
    }
    std::cout << "END" << std::endl;

	return 0;
}
