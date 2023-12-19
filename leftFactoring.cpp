#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform left factoring on a given grammar
void leftFactor(vector<string>& productions, char nonTerminal) {
    vector<string> commonPrefixes;

    // Group productions based on their common prefixes
    for (const string& production : productions) {
        if (production[0] == nonTerminal) {
            string suffix = production.substr(3);
            if (find(commonPrefixes.begin(), commonPrefixes.end(), suffix) == commonPrefixes.end()) {
                commonPrefixes.push_back(suffix);
            }
        }
    }

    // Create new productions for common prefixes
    for (const string& commonSuffix : commonPrefixes) {
        vector<string> group;
        for (const string& production : productions) {
            if (production[0] == nonTerminal && production.substr(3) == commonSuffix) {
                group.push_back(production);
            }
        }

        if (group.size() > 1) {
            // Common prefix found, create a new non-terminal
            char newNonTerminal = 'A'; // You can customize the new non-terminal
            while (find_if(productions.begin(), productions.end(),
                           [newNonTerminal](const string& prod) {
                               return prod[0] == newNonTerminal;
                           }) != productions.end()) {
                ++newNonTerminal;
            }

            // Update the original productions
            for (const string& production : group) {
                productions.erase(remove(productions.begin(), productions.end(), production), productions.end());
                string newProduction = nonTerminal + " -> " + commonSuffix + newNonTerminal;
                if (!commonSuffix.empty() && commonSuffix != "@") {
                    newProduction += commonSuffix;
                }
                productions.push_back(newProduction);
            }
            // Add the new non-terminal production
            string newNonTerminalProduction = newNonTerminal + " -> " + commonSuffix;
            productions.push_back(newNonTerminalProduction);
        }
    }
}

int main() {
    char nonTerminal;
    vector<string> productions;

    int choice;
    do {
        cout << "\nMenu:\n"
             << "1. Enter Productions\n"
             << "2. Perform Left Factoring\n"
             << "3. Display Productions\n"
             << "4. Quit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter the number of productions: ";
                int numProductions;
                cin >> numProductions;
                cout << "Enter the productions:\n";
                for (int i = 0; i < numProductions; ++i) {
                    string production;
                    cin >> production;
                    productions.push_back(production);
                }
                break;
            }
            case 2: {
                cout << "Enter the non-terminal to perform left factoring: ";
                cin >> nonTerminal;
                leftFactor(productions, nonTerminal);
                cout << "Left factoring completed.\n";
                break;
            }
            case 3:
                cout << "Current Productions:\n";
                for (const string& production : productions) {
                    cout << production << endl;
                }
                break;
            case 4:
                cout << "Quitting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
