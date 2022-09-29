#include <iostream>

using namespace std;

int main(){
    int row,i,j,k,l;
    int number,next,min;
    cin>>row;
    for(i=1;i<=row;i++){
        number=i;
        for(j=1;j<=row-i;j++){
            cout<<" ";
        }
        for(k=1;k<=i;k++){
            cout<<number;
            next=number;
            number+=1;
        }
        for(l=2;l<=i;l++){
            cout<<next-1;
            next-=1;
        }
        cout<<endl;
    }
    for(i=1;i<row;i++){
        number=row-i;
        for(j=0;j<i;j++){
            cout<<" ";
        }
        for(k=row-1;k>=i;k--){
            cout<<number;
            next=number;
            number+=1;
        }
        for(l=row-2;l>=i;l--){
            cout<<next-1;
            next-=1;
        }
        cout<<endl;
    }
    return 0;
}