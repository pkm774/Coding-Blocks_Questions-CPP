#include <iostream>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = 0, temp = 0;
        string ans = "";
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != ' ')
                ++count;
            else if (s[i] == ' ' && count > 0)
            {
                temp = count;
                count = 0;
            }
            else
                count = 0;
        }
        return (count > 0) ? count : temp;
    }
};