#include <iostream>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n = 0, q = 0;

    cin>>n>>q;

    int** a=new int*[n];

    for(int i = 0; i < n; ++i){
            int k = 0;
            cin >> k;
            a[i]=new int[k];
            for(int j = 0; j < k; ++j){
                    cin>>a[i][j];
            }
    }

    for(int v = 0; v < q; ++v){
            int i = 0, j = 0;
            cin >> i >> j;
            cout<<a[i][j]<<endl;
    }

    return 0;
}

// question link
// https://www.hackerrank.com/challenges/variable-sized-arrays/problem?isFullScreen=true
