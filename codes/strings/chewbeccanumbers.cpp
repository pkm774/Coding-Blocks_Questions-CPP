#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

int main()
{
    string x;

    cin >> x;

    for (auto &digit : x)
    {
        if (digit > '4') {
            digit = '9' - digit + '0';
        }
    }

    if (x.front() == '0') {
        x.front() = '9';
    }

    cout << x << endl;

    return 0;
}
