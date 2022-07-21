#include <iostream>

using namespace std;

int main(){
    int i=0,n,arr[10];
    int largest;
    cout<<"Enter total elements of array:"<<" ";
    cin>>n;
    for(i=0;i<n;++i){
        cout<<"Enter element no "<<i+1<<":";
        cin>>arr[i];
        largest=arr[i];
    }
    while(i<n){
        if(arr[i]>largest){
            largest=arr[i];
        }
        i++;
    }
    cout<<"Largest value is :"<<largest;

    return 0;
}