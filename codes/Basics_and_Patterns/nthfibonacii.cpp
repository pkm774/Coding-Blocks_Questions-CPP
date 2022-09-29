#include<iostream>

using namespace std;

int main() {
  int a=0,b=1,c=0,n,count=0;
  cin>>n;
  if(n==0){
    cout<<0;
  } else if (n==1){
    cout<<1;
  } else {
    while(count<n-1){
      c=a+b;
      a=b;
      b=c;
      count+=1;
    }
    cout<<c;
  }
	return 0;
}
