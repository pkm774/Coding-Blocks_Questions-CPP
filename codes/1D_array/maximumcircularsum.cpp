#include<iostream>

using std::cin;
using std::cout;
using std::endl;

#include <algorithm>
using std::max;
using std::max_element;

// Calculate maximum subarray sum using Kadane algorithm
int max_contiguous_sum(int* arr, int size)
{
    int max_sum = 0, max_sum_calc = 0;

    for (int i = 0; i < size; i++)
    {
        // Add elements of array
        max_sum_calc = max_sum_calc + arr[i];
        // Check and save non-negative value
        max_sum_calc = max(max_sum_calc, 0);
        // Check and save max of max_sum and max_sum_calc
        max_sum = max(max_sum, max_sum_calc);
    }

    // if max sum is 0 then return the largest negative value as answer
    if (max_sum == 0) {
        max_sum = *max_element(arr, arr + size);
    }

    return max_sum;
}

// Calculate maximum circular sum
int maxCircularSum(int* arr, int size)
{
    // get the maximum sum using standard kadane's algorithm
    int max_ctg_sum = max_contiguous_sum(arr, size);

    if (max_ctg_sum < 0) {
        return max_ctg_sum;
    }

    // if max sum is non zero then find the maximum sum that includes
    // corner elements.
    int max_wrap_sum = 0;
    for (int i = 0; i < size; i++)
    {
        // Calculate array sum with corner elements
        max_wrap_sum += arr[i];
    }

    // invert the sign of the array values
    for (int i = 0; i < size; i++)
    {
        arr[i] = -arr[i];
    }
    // Calculate maximum subarray sum with inverted values
    int max_inv_sum = max_contiguous_sum(arr, size);

    // max sum with corner elements will be:
    // array_sum = max wrap sum + max subarray sum of inverted array
    int array_sum = max_wrap_sum + max_inv_sum;

    // The maximum circular sum will be maximum of two sums
    return (array_sum > max_ctg_sum) ? array_sum : max_ctg_sum;
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
        delete[] arr;
    }
    return 0;
}

