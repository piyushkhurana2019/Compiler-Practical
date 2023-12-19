#include <iostream>
#include <cctype> // for isdigit and isalpha functions

int main() {
    std::string inputString;

    // Get input string from the user
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputString);

    // Process the string and identify characters and digits
    std::cout << "Tokens:\n";

    for (char ch : inputString) {
        if (std::isdigit(ch)) {
            std::cout << "Digit: " << ch << "\n";
        } else if (std::isalpha(ch)) {
            std::cout << "Character: " << ch << "\n";
        }
        // You can add additional conditions for other types of tokens if needed
    }

    return 0;
}
