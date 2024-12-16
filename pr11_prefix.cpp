#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to get precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char ch : infix) {
        if (isalnum(ch)) {
            // If operand, add to postfix expression
            postfix += ch;
        } else if (ch == '(') {
            // If '(', push to stack
            s.push(ch);
        } else if (ch == ')') {
            // If ')', pop and add to postfix until '(' is found
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Remove '('
        } else if (isOperator(ch)) {
            // If operator, pop operators of higher or equal precedence
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // Pop remaining operators in the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    stack<int> s;

    for (char ch : postfix) {
        if (isalnum(ch)) {
            // If operand, push its integer value to stack
            s.push(ch - '0'); // Assuming single-digit operands
        } else if (isOperator(ch)) {
            // Pop two operands for the operator
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();

            // Perform the operation and push the result
            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }

    // The final result is at the top of the stack
    return s.top();
}

// Main function
int main() {
    string infix;

    // Input infix expression
    cout << "Enter an infix expression: ";
    cin >> infix;

    // Convert to postfix
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    // Evaluate postfix
    int result = evaluatePostfix(postfix);
    cout << "Result of evaluation: " << result << endl;

    return 0;
}
