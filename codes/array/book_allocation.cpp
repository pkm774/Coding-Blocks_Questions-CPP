#include <iostream>
#include <algorithm>
#include <vector>

bool isPossible(std::vector<int>& books, int n, int break_value, int m)
{
    int studentUsed = 1;
    int noOfPagesReading = 0;
    for (int i = 0; i < n; i++)
    {
        if (noOfPagesReading + books[i] > break_value)
        {
            studentUsed++;
            noOfPagesReading = books[i];
            if (studentUsed > m)
            {
                return 0;
            }
        }
        else
        {
            noOfPagesReading += books[i];
        }
    }
    return 1;
}

int main()
{
    int test = 0;
    std::cin >> test;

    while (test--)
    {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> books(n);
        int end = 0;

        if (n < m)
        {
            std::cout << -1 << std::endl;
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            std::cin >> books[i];
            end += books[i];
        }

        int start = books[n - 1], mid = 0;

        int ans = end;

        while (start <= end)
        {
            mid = (start + end) / 2;
            if (isPossible(books, n, mid, m))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = start + 1;
            }
        }
        std::cout << ans << std::endl;
    }
}
