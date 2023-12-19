#include <iostream>
#include <vector>

// Function to push an element onto the stack
void push(std::vector<int>& stackData, int element) {
    stackData.push_back(element);
    std::cout << "Pushed " << element << " onto the stack." << std::endl;
}

// Function to pop an element from the stack
void pop(std::vector<int>& stackData) {
    if (!stackData.empty()) {
        std::cout << "Popped " << stackData.back() << " from the stack." << std::endl;
        stackData.pop_back();
    } else {
        std::cout << "Stack underflow! Cannot pop from an empty stack." << std::endl;
    }
}

// Function to display the top element of the stack
void displayTop(const std::vector<int>& stackData) {
    if (!stackData.empty()) {
        std::cout << "Top element: " << stackData.back() << std::endl;
    } else {
        std::cerr << "Stack is empty. No top element." << std::endl;
    }
}

// Function to display the size of the stack
void displaySize(const std::vector<int>& stackData) {
    std::cout << "Size of the stack: " << stackData.size() << std::endl;
}

// Function to display the menu
void displayMenu() {
    std::cout << "Menu:\n"
              << "1. Push\n"
              << "2. Pop\n"
              << "3. Display Top\n"
              << "4. Display Size\n"
              << "5. Quit\n";
}

int main() {
    std::vector<int> myStack;

    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int element;
                std::cout << "Enter the element to push: ";
                std::cin >> element;
                push(myStack, element);
                break;
            }
            case 2:
                pop(myStack);
                break;
            case 3:
                displayTop(myStack);
                break;
            case 4:
                displaySize(myStack);
                break;
            case 5:
                std::cout << "Quitting the program.\n";
                break;
            default:
                std::cerr << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
