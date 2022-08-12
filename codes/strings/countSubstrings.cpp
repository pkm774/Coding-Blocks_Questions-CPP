#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstring>
using std::string;

#include <string>
using std::getline;

bool isPalindromic(string s, int i, int j)
{
    if (i > j)
        return 1;

    if (s[i] != s[j])
        return  0;

    return isPalindromic(s, i + 1, j - 1);
}

int main() {
    string input = " ";

    getline(cin, input);

    int count = 0;

    for (int i = 0; i < input.length(); i++) {
        for (int j = i; j < input.length(); j++) {
            if (isPalindromic(input, i, j)) {
                count++;
            }
        }
    }

    cout << count;

    return 0;
}
