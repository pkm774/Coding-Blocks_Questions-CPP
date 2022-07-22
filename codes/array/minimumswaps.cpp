#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSwaps(int a[], int n) {
    pair<int, int> pos[100000];

    for (int i = 0; i < n; i++) {
        pos[i].first = a[i];
        pos[i].second = i;
    }
    vector<bool> vis(n, false);
    sort(pos, pos + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {

        if (vis[i] || pos[i].second == i) continue;
        int cycle = 0;
        int j = i;
        while (!vis[j]) {
            vis[j] = 1;
            j = pos[j].second;
            cycle++;
        }
        if (cycle > 0) {
            ans += (cycle - 1);
        }

    }
    return ans;
}

int main() {
    int siz = 0;

    cin >> siz;

    int* arr{ new int[siz] { 0 } };

    for (int i = 0; i < siz; ++i) {
        cin >> arr[i];
    }

    cout << minSwaps(arr, siz) << endl;

    return 0;
}
