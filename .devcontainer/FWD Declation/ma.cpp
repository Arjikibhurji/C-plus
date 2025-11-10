// main.cpp
#include <iostream>

// forward declaration (prototype)
int doubleNumber(int x);

int main() {
    int num{};
    std::cout << "Enter a number: ";
    std::cin >> num;

    std::cout << "Double is: " << doubleNumber(num) << '\n';
    return 0;
}
