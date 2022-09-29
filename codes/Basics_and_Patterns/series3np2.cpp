#include <iostream>

using namespace std;

int main(){
    int n1,n2,i=1,j=0,k=1;
    cin>>n1>>n2;
    while(i<=n1){
        j=(3*k)+2;
        if(j%n2==0){
            k+=1;
        }else{
            cout<<j<<endl;
            k+=1;
            i+=1;
        }
    }
    return 0;
}