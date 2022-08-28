#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int kthSmallest(int arr[], int r, int k) {
        sort(arr, arr + r);
        return arr[k - 1];
    }
};

int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        int number_of_elements;
        cin >> number_of_elements;
        int* a{ new int[number_of_elements] { 0 } };

        for (int i = 0; i < number_of_elements; i++)
            cin >> a[i];

        int k;
        cin >> k;
        Solution ob;
        cout << ob.kthSmallest(a, number_of_elements, k) << endl;
    }
    return 0;
}
