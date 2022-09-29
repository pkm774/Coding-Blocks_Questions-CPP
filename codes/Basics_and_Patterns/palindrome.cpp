#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string Palindrome(string s){
    int j=s.size();
    int i=0;
    string print;

    for (int n = j - 1; n >= 0; n--) {
        if (s[i] == s[n])
            i++;
    }

    if (i == j) {
        return s;
    }

    string remain_rev = s.substr(i, j);
    reverse(remain_rev.begin(), remain_rev.end());
    print = remain_rev + Palindrome(s.substr(0, i)) + s.substr(i);
    return print;
}

int main(){
    string word;
    cin >> word;
    cout<<Palindrome(word)<<endl;
}