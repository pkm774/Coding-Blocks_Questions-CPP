#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    unordered_map<char, pair<int, int>> umap{};
    string input;

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
        umap[input[i]].first++;
        umap[input[i]].second = input.length() - i - 1;
    }

    unordered_map<char, pair<int, int>>::iterator it;
    for (it = umap.begin(); it != umap.end(); ++it)
    {
        if (it->second.first == 1)
        {
            // Store the base adress of index container in
            // addres pointer.
            int *addres = &it->second.second;
            // Dereference addres pointer to get value from the container.
            cout << *addres;
            return 0;
            // return *add; //for returning index
        }
    }

    return -1; // if no unique character exist
}