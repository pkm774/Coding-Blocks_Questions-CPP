#include <iostream>

using namespace std;

int main(){
    int row,i,j,k,l,m;
    int rt,llt,lrt;
    cin>>row;

    // Upper pattern
    for(i=1;i<=row;++i){
        //u left triangle
        for(j=row;j>row-i;--j){
            cout<<j<<' ';
            rt=j;
        }
        //u left space
        for(k=1;k<=row-i;++k){
            cout<<' '<<' ';
        }
        // u Midle space column
        cout<<' '<<' ';
        // u right space
        for(l=1;l<=row-i;++l){
            cout<<' '<<' ';
        }
        // u right triangle
        for(m=row;m>row-i;--m){
            cout<<rt<<' ';
            rt=rt+1;
        }
        cout<<endl;
    }
    //Middle line
    // 5 4 3 2 1 0 1 2 3 4 5 
    for(i=row;i>=1;--i){
        cout<<i<<' ';
    }
    cout<<0<<' ';
    for(i=1;i<=row;++i){
        cout<<i<<' ';
    }
    cout<<endl;

    // Lower Pattern
    for(i=1;i<=row;++i){
        llt=row;
        for(j=0;j<=row-i;++j){
            cout<<llt<<' ';
            lrt=llt;
            llt-=1;
        }
        for(k=2;k<=i;++k){
            cout<<' '<<' ';
        }
        cout<<' '<<' ';
        for(l=2;l<=i;++l){
            cout<<' '<<' ';
        }
        for(m=0;m<=row-i;++m){
            cout<<lrt<<' ';
            lrt=lrt+1;
        }
        cout<<endl;
    }
}