#include <iostream>

using namespace std;

bool fibo(int n)
{
    int a = 0, b = 1;
    int c = a + b;
    bool what;
    if (n == a || n == b)
    {
        what = true;
    }
    while (c <= n)
    {
        if (n == c)
        {
            what = true;
        }
        else
        {
            what = false;
        }
        a = b;
        b = c;
        c = a + b;
    }
    return what;
}

int main()
{
    int i;
    bool test;
    cout << "Enter a number : ";
    cin >> i;
    test = fibo(i);
    if (test)
    {
        cout << i << " is a Fibonacci number";
    }
    else
    {
        cout << i << " is not a Fibonacci number";
    }
}
