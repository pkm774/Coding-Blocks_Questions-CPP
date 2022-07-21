#include<iostream>

using namespace std;

int main() {
	int num,sum=0;
	do{
		cin>>num;
		sum+=num;
		if(sum==num || sum>0){
			cout<<num<<endl;
		}
		else{
			break;
		}
	}while((num>=-1000) && (num<=1000));
	return 0;
}
