#include<iostream>

using namespace std;

int main(){
    int dec,mod,oct=0,place=1;
    cin>>dec;
    while(dec != 0){
        mod=dec%8;
        oct+=mod*place;
        dec/=8;
		place*=10;
    }
    cout<<oct<<endl;
    return 0;
}