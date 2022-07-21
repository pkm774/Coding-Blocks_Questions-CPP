#include <iostream>

using namespace std;

int main (){
    int row = 0,i=1,num=1;
    cout<<"Enter row number: ";
    cin>>row;
    while(i<=row){
        int j=1;
        while(j<=i){
            cout<<num<<" ";
            num+=1;
            j+=1;
        }
        cout<<endl;
        i+=1;
    }
}