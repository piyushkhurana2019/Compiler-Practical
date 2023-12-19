#include <iostream>
#include <stack>
#include <algorithm>

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Function to convert infix expression to prefix expression
std::string infixToPrefix(const std::string& infix) {
    std::string prefix;
    std::stack<char> operatorStack;

    // Reverse the infix expression
    std::string reversedInfix = infix;
    std::reverse(reversedInfix.begin(), reversedInfix.end());

    for (char ch : reversedInfix) {
        if (std::isalnum(ch)) {
            // Operand, add to the prefix expression
            prefix += ch;
        } else if (ch == ')') {
            // Closing parenthesis, push onto the stack
            operatorStack.push(ch);
        } else if (ch == '(') {
            // Opening parenthesis, pop from the stack until a closing parenthesis is encountered
            while (!operatorStack.empty() && operatorStack.top() != ')') {
                prefix += operatorStack.top();
                operatorStack.pop();
            }
            // Pop the remaining closing parenthesis
            if (!operatorStack.empty())
                operatorStack.pop();
        } else if (isOperator(ch)) {
            // Operator
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) > getPrecedence(ch)) {
                prefix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(ch);
        }
    }

    // Pop any remaining operators from the stack
    while (!operatorStack.empty()) {
        prefix += operatorStack.top();
        operatorStack.pop();
    }

    // Reverse the final prefix expression
    std::reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main() {
    std::string infixExpression;

    // Get infix expression from the user
    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, infixExpression);

    // Convert infix to prefix
    std::string prefixExpression = infixToPrefix(infixExpression);

    // Display the result
    std::cout << "Prefix expression: " << prefixExpression << std::endl;

    return 0;
}
