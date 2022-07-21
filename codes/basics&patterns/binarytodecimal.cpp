#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int b,num,newnum=0,pr=0,i;
    cin>>b;
    while(b != 0){
        i = b % 10;
        num = i * pow(2,pr);
        newnum += num;
        pr+=1;
        b/=10;
    }
    cout<<newnum<<endl;
    return 0;
}