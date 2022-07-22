#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void multiply(int x, vector<int>& multiplicand) {    //multiply multiplicand with x
    int carry = 0;     // Initialize carry to 0
    vector<int>::iterator i;

    for (i = multiplicand.begin(); i != multiplicand.end(); i++) {   //multiply x with all digit of multiplicand
        int prod = (*i) * x + carry;
        *i = prod % 10;       //put only the last digit of product
        carry = prod / 10;    //add remaining part with carry
    }

    while (carry) {    //when carry is present
        multiplicand.push_back(carry % 10);
        carry = carry / 10;
    }
}

void factorial(int n) {
    vector<int> result;
    result.push_back(1);    //at first store 1 as result

    for (int i = 2; i <= n; i++)
        multiply(i, result);   //multiply numbers 1*2*3*......*n

    reverse(result.begin(), result.end());

    vector<int>::iterator it;    //reverse the order of result

    for (it = result.begin(); it != result.end(); it++)
        cout << *it;

    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    if (n < 1 || n > 500) {
        return 0;
    }
    factorial(n);
    return 0;
}
