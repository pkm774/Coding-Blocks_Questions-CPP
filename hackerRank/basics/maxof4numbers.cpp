#include <iostream>
#include <climits>

using namespace std;

int max_of_four(int a, int b, int c, int d){
    int max = INT_MIN;
    int* arr{new int[4]{a,b,c,d}};

    for(int i = 0; i < 4; ++i){
        if(arr[i] >= max){
            max = arr[i];
        }
    }

    return max;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    cout<<max_of_four(a, b, c, d)<<endl;
    return 0;
}
