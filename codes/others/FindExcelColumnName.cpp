//{ Driver Code Starts
#include<iostream>
#include<vector>
using namespace std;

char* FindExcelColumnName(int n) {
	// String Array Having All Alphabets
	string alphabets[] = { "-1", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };

	// Result for storing answer
	string result = "";


	while (n > 0) {
		int remainder = n % 26;
		if (remainder != 0) {
			result = alphabets[remainder] + result;
			n = n / 26;
		} else {
			// when remainder == 0, no values for a[0]
			// so we need to borrow some values from the
			// future values.
			result = alphabets[26] + result;
			n = (n / 26) - 1;
		}
	}

	// Now we have answer but in the
	// form of string.
	// For returning character array we have
	// to convert string to character array.

	// Get length of the result string
	int len = result.length();
	// Create a character array in heap
	// with size equal to result string
	char* ans = new char[len];

	// Fetch every single character from
	// the result string and  insert it into
	// character array ans.
	int i;
	for (i = 0; i < len; ++i) {
		ans[i] = result[i];
	}
	// Terminate ans with null value.
	ans[i] = '\0';

	// Return the character array ans
	return ans;
}

int main() {
	int n;
	cin >> n;

	cout << FindExcelColumnName(n);
	cout<<endl;
}