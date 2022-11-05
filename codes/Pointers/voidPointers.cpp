#include <iostream>

using namespace std;

int main() {
	// Variables holding data
	int i = 10;
	float g = 10.101;
	char ch = 'A';
	string s = "lolo";

	// Void pointers pointing variables
	void* ptr = &i;
	void* ptr1 = &g;
	void* ptr2 = &ch;
	void* ptr3 = &s;

	// Dereferencing void pointers to store
	// previous data into new variables
	int a = *(int*)ptr;
	float b = *(float*)ptr1;
	char c = *(char*)ptr2;
	string d = *(string*)ptr3;

	// Printing data
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d;

	int* ne = new int[1];
	cout << ne;
}