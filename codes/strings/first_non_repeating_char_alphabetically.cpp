#include <iostream>

using namespace std;

int main() {
    int ascii[256] = {0};
	string input;
    int n = 0;
	int count = 0;

    cin >> n;
    fflush(stdin);
	cin >> input;

	for (int i = 0; i < input.length(); ++i) {
		++ascii[input[i]];
	}

    for (int i = 0; i < 256; ++i)
    {
        if (ascii[i] == 1)
            ++count;
        if (count == n)
        {
            cout << (char)i << " ";
            return 0;
        }
    }

    return 0;
}