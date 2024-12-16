#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to clean the string (remove punctuation, spaces, and convert to lowercase)
string cleanString(const string& str) {
    string cleaned;
    for (char ch : str) {
        if (isalnum(ch)) { // Check if the character is alphanumeric
            cleaned += tolower(ch); // Convert to lowercase
        }
    }
    return cleaned;
}

// Function to reverse a string using a stack
string reverseString(const string& str) {
    stack<char> charStack;
    string reversed;

    // Push all characters onto the stack
    for (char ch : str) {
        charStack.push(ch);
    }

    // Pop characters from the stack to form the reversed string
    while (!charStack.empty()) {
        reversed += charStack.top();
        charStack.pop();
    }

    return reversed;
}

// Function to check if a string is a palindrome
bool isPalindrome(const string& str) {
    string cleaned = cleanString(str);
    string reversed = reverseString(cleaned);
    return cleaned == reversed;
}

// Main function
int main() {
    string input;

    // Input the string
    cout << "Enter a string: ";
    getline(cin, input);

    // Clean the input string
    string cleanedInput = cleanString(input);

    // Reverse the string
    string reversedString = reverseString(cleanedInput);

    // Display the original and reversed strings
    cout << "\nOriginal String (cleaned): " << cleanedInput << endl;
    cout << "Reversed String: " << reversedString << endl;

    // Check if the string is a palindrome
    if (isPalindrome(input)) {
        cout << "\nThe given string is a palindrome." << endl;
    } else {
        cout << "\nThe given string is not a palindrome." << endl;
    }

    return 0;
}
