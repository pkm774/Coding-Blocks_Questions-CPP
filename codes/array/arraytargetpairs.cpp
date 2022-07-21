#include<iostream>

using namespace std;

void printTargetPairs(int a[], int size, int target)
{
    int j = 0, k = 0;

    for (j = 0; j < size - 1; ++j)
    {
        for (k = j + 1; k < size; ++k)
        {
            if (a[j] + a[k] == target)
            {
                if (a[j] > a[k]) {
                    cout << a[k] << " and " << a[j] << endl;
                }
                else {
                    cout << a[j] << " and " << a[k] << endl;
                }
            }
        }
    }
}

int main() {
    int arr[1000] = {};
    int size, i;
    int target;

    cin >> size;
    for (i = 0; i < size; ++i)
    {
        cin >> arr[i];
        cout << endl;
    }
    cin >> target;
    printTargetPairs(arr, size, target);
    return 0;
}
