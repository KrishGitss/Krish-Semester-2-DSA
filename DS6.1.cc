#include <iostream>
#include <stack>

using namespace std;

int precedence(char op) { return (op == '+' || op == '-') ? 1 : (op == '*' || op == '/') ? 2 : 0; }
bool isOperator(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }

string infixToPostfix(const string &infix) {
    stack<char> s;
    string postfix;
    for (char c : infix) {
        if (isalnum(c)) postfix += c;
        else if (c == '(') s.push(c);
        else if (c == ')') { while (!s.empty() && s.top() != '(') postfix += s.top(), s.pop(); s.pop(); }
        else { while (!s.empty() && precedence(s.top()) >= precedence(c)) postfix += s.top(), s.pop(); s.push(c); }
    }
    while (!s.empty()) postfix += s.top(), s.pop();
    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;
    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    return 0;
}
