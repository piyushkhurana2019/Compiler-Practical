#include <iostream>
#include <stack>
#include <string>

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

// Function to convert infix expression to postfix expression
std::string infixToPostfix(const std::string& infix) {
    std::string postfix;
    std::stack<char> operatorStack;

    for (char ch : infix) {
        if (std::isalnum(ch)) {
            // Operand, add to the postfix expression
            postfix += ch;
        } else if (ch == '(') {
            // Opening parenthesis, push onto the stack
            operatorStack.push(ch);
        } else if (ch == ')') {
            // Closing parenthesis, pop from the stack until an opening parenthesis is encountered
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            // Pop the remaining opening parenthesis
            if (!operatorStack.empty())
                operatorStack.pop();
        } else if (isOperator(ch)) {
            // Operator
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(ch)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(ch);
        }
    }

    // Pop any remaining operators from the stack
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    std::string infixExpression;

    // Get infix expression from the user
    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, infixExpression);

    // Convert infix to postfix
    std::string postfixExpression = infixToPostfix(infixExpression);

    // Display the result
    std::cout << "Postfix expression: " << postfixExpression << std::endl;

    return 0;
}
