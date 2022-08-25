#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#include <string>
using std::getline;

string replaceallpi(string s)
{
    // base case
    if (s.length() == 0)
    {
        return "";
    }
    if (s.length() == 1)
    {
        return s;
    }

    // recursive case
    string f = s.substr(0, 2);

    if (f == "pi")
    {
        return "3.14" + replaceallpi(s.substr(2));
    }
    else
    {
        return s[0] + replaceallpi(s.substr(1));
    }
}

int main()
{
    int n = 0;

    cin >> n;
    n += 1;

    while(n--) {
        string s = " ";
        // to clear buffer and remove enter(newline character);
        fflush(stdin);
        getline(cin, s);
        cout << replaceallpi(s) << endl;
    }

    return 0;
}
