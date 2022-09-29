#include <iostream>
using namespace std;
int main()
{
  int n1, n2;
  char ch;
  while (true)
  {
    cin >> ch;
    if (ch == 'x' || ch == 'X')
    {
      break;
    }
    else if (ch == '+')
    {
      cin >> n1 >> n2;
      cout << n1 + n2 << endl;
    }
    else if (ch == '-')
    {
      cin >> n1 >> n2;
      cout << n1 - n2 << endl;
    }
    else if (ch == '*')
    {
      cin >> n1 >> n2;
      cout << n1 * n2 << endl;
    }
    else if (ch == '/')
    {
      cin >> n1 >> n2;
      cout << n1 / n2 << endl;
    }
    else if (ch == '%')
    {
      cin >> n1 >> n2;
      cout << n1 % n2 << endl;
    }
    else
    {
      cout << "Invalid operation. Try again." << endl;
    }
  }
  return 0;
}