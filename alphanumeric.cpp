#include <iostream>
#include <cctype> // for isalnum function

// Function to check if a character is an operator
bool isOperator(char ch) {
    // Define the set of operators you want to identify
    const std::string operators = "+-*/%=><&|^";

    return operators.find(ch) != std::string::npos;
}

int main() {
    std::string inputString;

    // Get input string from the user
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputString);

    // Process the string and identify alphanumeric characters and operators
    std::cout << "Tokens:\n";

    for (char ch : inputString) {
        if (std::isalnum(ch)) {
            std::cout << "Alphanumeric: " << ch << "\n";
        } else if (isOperator(ch)) {
            std::cout << "Operator: " << ch << "\n";
        }
        // You can add additional conditions for other types of tokens if needed
    }

    return 0;
}
