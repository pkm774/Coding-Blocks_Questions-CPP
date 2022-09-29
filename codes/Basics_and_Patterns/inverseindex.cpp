#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int n,r=0,temp=0,no=0,count=0;
    int indx=1;
	cin>>n;
	while(n!=0){
		r=n%10;
        count=r;
        temp=indx;
        no=no+temp*pow(10,count-1);
		count=count+1;
		indx=indx+1;
		n=n/10;
	}
	cout<<no;
	return 0;
	
}