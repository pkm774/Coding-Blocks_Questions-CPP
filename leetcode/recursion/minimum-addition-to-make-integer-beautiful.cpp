#include <iostream>

class Solution
{
public:
    int sumDigits(long long n)
    {
        int res = 0;
        for (; n; n /= 10)
            res += n % 10;
        return res;
    }

    // Normal approach
    long long makeIntegerBeautiful(long long n, int target)
    {
        long long res = 0;
        for (long long mul = 1; sumDigits(n) > target; mul *= 10)
        {
            res += mul * (10 - n % 10);
            n = n / 10 + 1;
        }
        return res;
    }

    // Recursion variant
    long long makeIntegerBeautiful(long long n, int target)
    {
        if (sumDigits(n) <= target)
        {
            return 0;
        }

        return 10 - n % 10 + 10 * makeIntegerBeautiful(n / 10 + 1, target);
    }
};

// https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/discuss/2757973/Eat-from-right