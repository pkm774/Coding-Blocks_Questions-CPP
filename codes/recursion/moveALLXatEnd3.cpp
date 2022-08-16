#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#include <string>
using std::getline;

string moveallxatend(string s, int i, int len)
{
    // base case
    if (i == len)
    {
        return "";
    }

    // recursive case
    if (s[i] == 'x')
    {
        return moveallxatend(s, i + 1, len) + s[i];
    }
    else
    {
        return s[i] + moveallxatend(s, i + 1, len);
    }
}

int main()
{
    string s = " ";
    getline(cin, s);

    int len = s.size();
    cout << moveallxatend(s, 0, len);

    return 0;
}