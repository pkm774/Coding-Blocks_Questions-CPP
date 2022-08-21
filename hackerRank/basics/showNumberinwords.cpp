#include <iostream>

using namespace std;

string num[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a, b ;

    cin >> a >> b ;

    for (int i = a; i <= b; ++i) {
        if(i >= 1 && i<=9) {
            cout << num[i-1] << endl;
        }
        else if (i>9) {
            if(i % 2 == 0) {
                cout<< "even" << endl;
            }
            else
            {
                cout<< "odd" << endl;
            }
        };

    };
    return 0;
}


// Question link;
// https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem?isFullScreen=true&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
