#include <iostream>

using namespace std;

int printfibo(int n){
    int a,b=1;
    int c=0;
    while (c<=n){
        cout<<c<<endl;
        a=b;
        b=c;
        c=a+b;
    }
    return 0;
}

int main(){
    int i;
    cout<<"Enter a number for limit: ";
    cin>>i;
    printfibo(i);
    return 0;
}