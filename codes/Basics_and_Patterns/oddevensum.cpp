#include <iostream>

using namespace std;

int main(){
  int number,osum=0,esum=0,i,j=1;
  cin>>number;
  while(number != 0){
    i=number%10;
    if(j%2==0){
      esum+=i;
    }
    else{
      osum+=i;
    }
    j+=1;
    number/=10;
  }
  cout<<osum<<endl;
  cout<<esum;
  return 0;
}
