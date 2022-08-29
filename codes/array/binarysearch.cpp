#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int>& arr, int low, int high, int target)
{
    // either --> while (low<=high) | or
    while ((high - low) >= 0)
    {
        int medium = (high + low) / 2;

        // check if value at medium is equal to target
        if (arr[medium] == target) {
            return medium;
        }

        // check if value at medium is less than target then
        // low will be medium's next index
        if (arr[medium] < target) {
            low = medium + 1;
        }

        // check if value at medium is greater than target then
        // high will be medium - 1 index
        if (arr[medium] > target) {
            high = medium - 1;
        }
    }

    // return -1 if value not found
    return -1;
}

int main(void)
{
    int size = 0;
    cin >> size;

    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int target = 0;
    cin >> target;

    int result = binarySearch(arr, 0, size - 1, target);

    (result == -1) ? cout << -1 << endl : cout << result << endl;

    return 0;
}
