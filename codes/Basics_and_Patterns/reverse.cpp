#include<iostream>

using namespace std;

int main() {
	int number,i;
	cin>>number;
	while(number!=0){
		i=number%10;
		cout<<i;
		number/=10;
	}
	return 0;
}
