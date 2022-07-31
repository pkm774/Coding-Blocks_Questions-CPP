#include<iostream>

using std::cin;
using std::cout;
using std::endl;

// Standard Kadane's algorithm to find maximum subarray sum
int kadane(int a[], int n)
{
    int max_so_far = 0, max_ending_here = 0;

    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }

    return max_so_far;
}

// The function returns maximum circular contiguous sum in a[]
int maxCircularSum(int a[], int n)
{
    // Case 1: get the maximum sum using standard kadane's algorithm
    int max_kadane = kadane(a, n);

    // Case 2: Now find the maximum sum that includes
    // corner elements.
    int max_wrap = 0, i;
    for (i = 0; i < n; i++)
    {
        max_wrap += a[i];     // Calculate array-sum
        a[i] = -a[i];       // invert the array (change sign)
    }

    // max sum with corner elements will be:
    // array-sum - (-max subarray sum of inverted array)
    max_wrap = max_wrap + kadane(a, n);

    // The maximum circular sum will be maximum of two sums
    return (max_wrap > max_kadane) ? max_wrap : max_kadane;
}


/* Driver program to test maxCircularSum() */
int main()
{
    int test = 0;

    cin >> test;

    for (int i = 0; i < test; i++)
    {
        int size;
        cin >> size;
        int* arr{ new int[size] {0} };
        for (int j = 0; j < size; j++)
        {
            cin >> arr[j];
        }
        cout << maxCircularSum(arr, size) << endl;
    }
    return 0;
}
