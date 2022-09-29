#include<iostream>

using namespace std;

int main(){
    int row,i,j,k,l,m;
    int pend=1,end=0,cop;
    cin>>row;

    for(i=1;i<=row;i++){
        int first=1;
        for(j=1;j<=i;j++){
            cout<<first<<' ';
            cop=first;
            first+=1;
        }
        for(k=1;k<=row-i;k++){
            cout<<' '<<' ';
        }
        for(l=row-2;l>=i;l--){
            cout<<' '<<' ';
        }
        for(m=1;m<=i;m++){
            while(cop!=0){
                if(cop==row){
                    cop=row-1;
                }
                cout<<cop<<' ';
                cop-=1;
            }
        }
        cout<<endl;
    }
    return 0;
}