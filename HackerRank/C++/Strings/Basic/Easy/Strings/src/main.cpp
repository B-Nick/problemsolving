#include <iostream>
#include <string>
using namespace std;

int main() {
    // Complete the program
    std::string str0, str1;

    std::cin >> str0;
    std::cin >> str1;

    std::cout << str0.size() << " " << str1.size() << std::endl;
    std::cout << str0 + str1 << std::endl;
    const auto temp = str0.at(0);
    str0[0] = str1.at(0);
    str1[0] = temp;
    std::cout << str0 << " " << str1 << std::endl;

    return 0;
}
