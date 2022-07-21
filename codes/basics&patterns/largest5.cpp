#include <iostream>
#include <limits>

using namespace std;

int main(){
  int num,largest,i=1;
  largest=INT_MIN;
  while(i<=5){
    cin>>num;
    if(num>largest){
      largest=num;
    }
    i+=1;
  }
  cout<<largest;
  return 0;
}
