#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

class Solution {
public:
    static bool isPalindrome(int x) {
        int mod = 0;
        long long newnum = 0;
        int input = x;

        while(input > 0){
            mod = input% 10;
            newnum = (newnum * 10) + mod;
            input = input / 10;
        }

        if(newnum == x){
            return true;
        }else{
            return false;
        }
    }
};


int main()
{
    int num = 0;
    cin >> num;
    if(Solution::isPalindrome(num)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}
