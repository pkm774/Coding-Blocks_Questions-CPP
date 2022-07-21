#include <iostream>

using namespace std;

int main()
{
  int row, i, j, k;
  cin >> row;
  for (i = 0; i < row; i++)
  {
    int first = 1;
    for (j = 1; j <= (row - i); j++)
    {
      cout << " ";
    }
    for (k = 0; k <= i; k++)
    {
      cout << " " << first;
      first = first * (i - k) / (k + 1);
    }
    cout << endl;
  }
}
