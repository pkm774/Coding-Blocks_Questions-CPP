#include <iostream>
#include <vector>
#include <cstring>
#include <string>

/// Summary:Take string as input in which elements are seperated by comma
/// Returns: String Array containing elements excluding comma</returns>
/// Example: Prabhat,Kumar,Mishra
/// Out: Prabhat
///      Kumar
///      Mishra
int main() {
    std::string name = " ";
    int length = 0;

    std::getline(std::cin, name);
    length = name.length();

    std::vector<std::string> names{};
    std::string temp{};
    char inp{};

    for (int i = 0; i <= length; ++i) {
        inp = name[i];

        if (inp == ',' || inp == '\0') {
            names.push_back(temp);
            temp = "";
        }
        else {
            temp += inp;
        }
    }

    for (int i = 0; i < names.size(); ++i) {
        std::cout << names[i] << std::endl;
    }

    return 0;
}
