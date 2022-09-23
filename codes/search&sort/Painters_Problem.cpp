#include <iostream>
#include <vector>

int check_Possible_Time(std::vector<long int>& arr, long int mid, int n)
{
    int window = 0, time = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] + window <= mid)
        {
            window += arr[i];
        }
        else
        {
            time++;
            window = arr[i];
        }
    }
    return time;
}

int main()
{
    // Input N K T
    int n = 0, k = 0;
    long int t = 0;
    std::cin >> n >> k >> t;

    // Start and end for binary search.
    long int start = 0, end = 0;
    std::vector<long int> arr(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
        end += arr[i];
        start = std::max(start, arr[i]);
    }

    // Binary search implementation
    long int mid = 0, ans = start;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (k >= check_Possible_Time(arr, mid, n))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    std::cout << (ans * t) % 10000003 << std::endl;

    return 0;
}
