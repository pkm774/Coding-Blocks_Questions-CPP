#include <iostream>

void FizzBuzz(int n) {
    for (int i = 1; i <= n; ++i) {

        if (i % 15 == 0) std::cout << "FizzBuzz";
        else if (i % 5 == 0) std::cout << "Buzz";
        else if (i % 3 == 0) std::cout << "Fizz";
        else std::cout << i;

        std::cout << std::endl;
    }
}

int main() {
    int n = 0;
    std::cin >> n;

    FizzBuzz(n);

    return 0;
}

// O(n);