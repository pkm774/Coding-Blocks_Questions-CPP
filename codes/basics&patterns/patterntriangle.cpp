#include <iostream>

using namespace std;

int main(){
  int i,j,k,l,rownum=0,temp2;
  int num=2;
  cin>>rownum;
  for(i=1;i<=rownum;i++) {
    for(j=1;j<=rownum-i;j++){
      cout<<" "<<" ";
    }
    int temp=i;
    for(k=1;k<=i;k++) {
      cout<<temp<<" ";
      temp2=temp;
      temp+=1;
    }
    for(l=2;l<=i;l++) {
      temp2-=1;
      cout<<temp2<<" ";
    }
    cout<<endl;
  }
}
