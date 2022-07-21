#include<iostream>

using namespace std;

int main() {
	int a,b,c,temp,largest;
	cin>>a>>b>>c;
	if (a>b && a>c){
		cout<<a;
	}
	else if (b>a && b>c){
		cout<<b;
	}
	else if (c>a && c>b){
		cout<<c;
	}
  else if (a==b && a>c){
		cout<<a;
	}
  else if (a==c && a>b){
		cout<<a;
	}
  else if (b==c && b>a){
		cout<<b;
	}
	return 0;
}
