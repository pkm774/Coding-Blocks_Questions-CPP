#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<char, int> umap{};
    string input;
    int n = 0, count = 0;

    cin >> n;
    fflush(stdin);
    getline(cin, input);

    int i = 0;
    int j = input.length() - 1;

    while (i <= j)
    {
        char ch = input[i];
        input[i] = input[j];
        input[j] = ch;

        ++i;
        --j;
    }

    for (int i = 0; i < input.length(); ++i)
    {
        umap[input[i]]++;
    }

    unordered_map<char, int>::iterator it;
    for (it = umap.begin(); it != umap.end(); ++it)
    {
        if (it->second == 1)
        {
            ++count;
            if (count == n)
            {
                cout << it->first;
                return 0;
            }
        }
    }

    return 0;
}