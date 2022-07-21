#include <iostream>

using namespace std;

int main(){
    int row,i,j,k,l;
    cin>>row;

    for(i=1;i<=row;i++){
        for(j=1;j<=row-i;j++){
            cout<<" ";
        }
        cout<<"*";
        for(k=1;k<=3;k++){
            if(i==1 || i==row){
                for(k=1;k<=(row-2);k++){
                    cout<<"*";
                }
            }
            else{
                for(k=1;k<=(row-2);k++){
                    cout<<" ";
                }
            }
        }
        cout<<"*";
        cout<<endl;
    }
    return 0;
}