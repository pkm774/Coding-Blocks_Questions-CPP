#include <iostream>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int size = 0;
    cin >> size;

    int* arr = new int[size]{0};

    for(int i = 0; i < size; ++i){
        cin>>arr[i];
    }

    for(int i = size - 1; i >= 0; --i){
        cout<<arr[i]<<' ';
    }

    return 0;
}
