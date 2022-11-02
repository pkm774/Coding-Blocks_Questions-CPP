#include <iostream>

#define endl '\n'

void print_rhombhus(int n)
{
    int odd = 1;

    for (int i = n - 1; i > 0; --i)
    {
        for (int j = 1; j <= i; ++j)
        {
            std::cout << " ";
        }

        for (int i = 1; i <= odd; ++i)
        {
            std::cout << ".";
        }

        for (int j = 1; j <= i; ++j)
        {
            std::cout << " ";
        }

        odd = odd + 2;
        std::cout << endl;
    }

    for (int i = 1; i <= odd; ++i)
    {
        std::cout << ".";
    }
    std::cout << endl;

    for (int i = 1; i <= n - 1; ++i)
    {
        odd = odd - 2;
        for (int j = 1; j <= i; ++j)
        {
            std::cout << " ";
        }

        for (int i = 1; i <= odd; ++i)
        {
            std::cout << ".";
        }

        for (int j = 1; j <= i; ++j)
        {
            std::cout << " ";
        }
        std::cout << endl;
    }
}

int main()
{
    int n;
    std::cin >> n;

    print_rhombhus(n);

    return 0;
}