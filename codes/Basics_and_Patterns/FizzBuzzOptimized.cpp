#include <iostream>
#include <string>

void FizzBuzz(int n) {
    std::string s = "";
    int m3 = 0, m5 = 0;

    for (int i = 1; i <= n; ++i) {

        ++m3, ++m5;
        if (m3 == 3) { s += "Fizz"; m3 = 0; }
        if (m5 == 5) { s += "Buzz"; m5 = 0; }

        if (s.empty()) std::cout << i;
        else std::cout << s;

        s = "";

        std::cout << std::endl;
    }
}

int main() {
    int n = 0;
    std::cin >> n;

    FizzBuzz(n);

    return 0;
}
// O(n)
// Without % operator
