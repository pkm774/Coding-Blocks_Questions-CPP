#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int number, digit, sum = 0, i = 1;
    int min = INT_MAX, max = INT_MIN, mean;

    cin >> number;

    while (i <= number)
    {
        cin >> digit;
        sum += digit;
        if (digit >= max)
        {
            max = digit;
        }
        if (digit <= min)
        {
            min = digit;
        }
        i += 1;
    }
    mean = sum / number;
    cout << "mean " << mean << endl;
    cout << "max " << max << endl;
    cout << "min " << min << endl;
    return 0;
}
