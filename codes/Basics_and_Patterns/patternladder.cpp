#include <iostream>

using namespace std;

int main(){
  int rownum,i,j,num=1;
  cin>>rownum;
  for(i=0;i<rownum;i++){
    for(j=0;j<=i;j++){
      cout<<num<<" ";
      num+=1;
    }
    cout<<endl;
  }
  return 0;
}
