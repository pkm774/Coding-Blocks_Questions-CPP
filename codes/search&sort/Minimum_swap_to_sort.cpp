#include <iostream>
#include <vector>
#include <algorithm>

int minSwaps(std::vector<int>& arr) {
    // Store array size in n
    int n = arr.size();

    // Create pair of size n in the heap
    std::pair<int, int>* pos = new std::pair<int, int>[n];
    // Fill up the pairs in the form :
    // First element = ith index
    // Second element = ith index element
    for (int i = 0; i < n; ++i) {
        pos[i].first = arr[i];
        pos[i].second = i;
    }
    // Sort the position pair with respect to
    // pos.firstelement
    sort(pos, pos + n);

    // Boolean vector of size n for checking
    // if element visited or not.
    std::vector<bool> visited(n, false);

    // ans for storing minimum swaps
    int ans = 0;
    // Check through every element of arr.
    for (int i = 0; i < n; i++) {
        // If element at i visited or second element
        // at i pair is equal to i
        if (visited[i] || pos[i].second == i) {
            // Continue the loop
            continue;
        }
        // else if not visited then
        // check till the element after i is not visited
        int cycle = 0, j = i;
        while (!visited[j]) {
            // mark jth container in visited as visited.
            visited[j] = 1;
            // Store the index of unvisited element in j.
            j = pos[j].second;
            // Increment in count
            cycle++;
        }

        // If cycle is a non zero variable
        if (cycle > 0) {
            // then it will be added in answer by decrementing with 1
            ans += (--cycle);
        }

    }
    delete[] pos;
    // answer will hold the minimum swaps
    return ans;
}

int main() {
    int size = 0;
    std::cin >> size;

    std::vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    std::cout << minSwaps(arr) << std::endl;

    return 0;
}
