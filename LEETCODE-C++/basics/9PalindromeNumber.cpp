class Solution {
public:
    bool isPalindrome(int x) {
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
