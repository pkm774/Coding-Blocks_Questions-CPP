#include <iostream>

using namespace std;

int main(){
    int row,i,j,k,l,m;
    int ult,ult2;
    cin>>row;
    ult=row;
    for(i=1;i<=row;++i){
        for(j=2;j<=i;++j){
            cout<<'_'<<' ';
        }
        for(k=(row-i)+1;k>=1;--k){
            cout<<k<<' ';
        }
        cout<<endl;
    }
}