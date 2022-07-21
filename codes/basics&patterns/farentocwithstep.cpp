#include <iostream>

using namespace std;

int main()
{
    int min, max, step;
    int faren, celcius;

    cin >> min >> max >> step;
    faren = min;
    while (faren >= min && faren <= max)
    {
        celcius = ((faren - 32) * 5) / 9;
        cout << faren << "  " << celcius << endl;
        faren += step;
    }
    

    return 0;
}