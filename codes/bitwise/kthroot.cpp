#include <iostream>

void findKth(long long n, long long k) {
    long long low = 1, high = 1e6, midium = 0;

    while (low < high)
    {
        // right shift with 1 to make it half
        midium = low + high + 1 >> 1;

        // breakpoint flag for value
        bool flag = 1;

        // checking value
        long long value = 1;
        for (int i = 1; i <= k; i++)
        {
            // multiply value with mid
            value *= midium;
            // check if value is greater than n
            // if yes then exit loop and set high to mid - 1
            if (value > n)
            {
                flag = 0;
                break;
            }
        }

        // check for breakpoint
        // if flag is 1 then set low to medium because value is smaller than n
        if (flag) {
            low = midium;
        }
        // if value is larger than n then set high to mid - 1
        else {
            high = midium - 1;
        }
    }

    // print high which will be the kth number
    std::cout << high << std::endl;
}

int main()
{
    int test = 0;
    std::cin >> test;
    while (test--)
    {
        long long n = 0, k = 0;
        std::cin >> n >> k;

        // check if kth is equal to 1
        if (k == 1)
        {
            std::cout << n << std::endl;
            continue;
        }
        else {
            findKth(n, k);
        }
    }
    return 0;
}
