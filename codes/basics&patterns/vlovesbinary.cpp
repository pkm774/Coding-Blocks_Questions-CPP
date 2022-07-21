#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int num,i=1;
    cin>>num;
    while(i<=num){
        int b,number,decimal=0,pr=0,j=0;
        cin>>b;
        while(b != 0){
            j = b % 10;
            number = j * pow(2,pr);
            decimal += number;
            pr+=1;
            b/=10;
        }
        cout<<decimal<<endl;
        i+=1;
    }
    return 0;
}