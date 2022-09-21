#include <iostream>
#include <vector>

int checkTimePossible(std::vector<long int>& arr, long int mid, int n)
{
    int res = 1, window = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] + window <= mid)
        {
            window += arr[i];
        }
        else
        {
            res++;
            window = arr[i];
        }
    }
    return res;
}

int main()
{
    int k = 0, n = 0;
    long int t = 0;
    std::cin >> n >> k >> t;

    long int start = 0, end = 0;
    std::vector<long int> arr(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
        end += arr[i];
        start = std::max(start, arr[i]);
    }

    long int mid = 0, ans = start;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (k >= checkTimePossible(arr, mid, n))
        {
            end = mid - 1;
            ans = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    std::cout << (ans * t) % 10000003 << std::endl;

    return 0;
}