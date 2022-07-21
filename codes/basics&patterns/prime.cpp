#include <iostream>

using namespace std;

int main()
{
  int number, div, i, flag = 0;
  cin >> number;
  for (i = 2; i < number; i++)
  {
    if (number % i == 0)
    {
      flag = 1;
    }
  }
  if (flag == 1)
  {
    cout << "Not Prime";
  }
  else
  {
    cout << "Prime";
  }
  return 0;
}
