#include<iostream>

using namespace std;

int main() {
	int number,digit,count=0,i;
	cin>>number;
	cin>>digit;
	while(number!=0){
		i=number%10;
		if(i==digit){
			count+=1;
		}
		number/=10;
	}
  cout<<count;
	return 0;
}
