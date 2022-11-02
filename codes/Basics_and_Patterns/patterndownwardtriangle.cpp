#include<iostream>

#define endl '\n'

int main () {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n = 0;
	std::cin>>n;

	for(int i = 1; i <= n; ++i){
		for(int k = 1; k < i; ++k){
			std::cout<<" ";
		}
		for(int j = i; j <= n; ++j){
			std::cout<<"*"<<" ";
		}
		std::cout<<endl;
	}

	return 0;
}