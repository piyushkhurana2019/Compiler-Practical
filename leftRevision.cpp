#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if a character is a non-terminal
bool isNonTerminal(char symbol) {
    return isupper(symbol);
}

// Function to remove left recursion from a given non-terminal
void removeLeftRecursion(vector<string>& productions, char nonTerminal) {
    vector<string> newProductions;
    vector<string> leftRecursiveProductions;
    vector<string> nonLeftRecursiveProductions;

    // Separate left-recursive and non-left-recursive productions
    for (const string& production : productions) {
        if (production[0] == nonTerminal) {
            if (production[3] == nonTerminal) {
                leftRecursiveProductions.push_back(production);
            } else {
                nonLeftRecursiveProductions.push_back(production);
            }
        } else {
            newProductions.push_back(production);
        }
    }

    if (!leftRecursiveProductions.empty()) {
        char newNonTerminal = nonTerminal + 1;
        while (find_if(productions.begin(), productions.end(),
                       [newNonTerminal](const string& prod) {
                           return prod[0] == newNonTerminal;
                       }) != productions.end()) {
            ++newNonTerminal;
        }

        // Create new productions for the left-recursive non-terminal
        for (const string& production : nonLeftRecursiveProductions) {
            string newProduction = production + newNonTerminal;
            newProductions.push_back(newProduction);
        }

        // Create new productions for the new non-terminal
        for (const string& production : leftRecursiveProductions) {
            string newProduction = production.substr(3);
            newProduction += newNonTerminal;
            newProductions.push_back(newProduction);
        }

        // Add epsilon production for the new non-terminal
        newProductions.push_back(string(1, newNonTerminal) + " -> @");
    }

    productions = newProductions;
}

int main() {
    // Example grammar productions
    vector<string> productions = {
        "A -> Aa",
        "A -> Ab",
        "A -> c",
        "B -> Ba",
        "B -> Bb",
        "B -> d",
    };

    char nonTerminal;
    cout << "Enter the non-terminal to remove left recursion: ";
    cin >> nonTerminal;

    // Remove left recursion for the specified non-terminal
    removeLeftRecursion(productions, nonTerminal);

    // Display the updated productions
    cout << "Updated Productions:\n";
    for (const string& production : productions) {
        cout << production << endl;
    }

    return 0;
}
