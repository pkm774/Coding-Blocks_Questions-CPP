#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        // Declare answer string ns
        string ns = "";
        // Get length of the string s
        int leng = s.length();

        for (int i = 0; i < leng; ++i)
        {
            // Convert capital to small
            if (s[i] >= 65 && s[i] <= 90)
            {
                s[i] = s[i] + 32;
            }
            // Add only if s[i] is number or lowercase
            if ((s[i] >= 48 && s[i] <= 57) || (s[i] >= 97 && s[i] <= 122))
            {
                ns += s[i];
            }
        }

        // i for ns starting index
        int i = 0;
        // j for ns last index
        int j = ns.length() - 1;

        // return false only when characters do not match
        while (i <= j)
        {
            if (ns[i] != ns[j])
            {
                return false;
            }
            ++i, --j;
        }

        // Control is here means string is palindrome
        return true;
    }
};
