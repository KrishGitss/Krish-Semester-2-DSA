#include <iostream>
#include <stack>

using namespace std;

int evaluatePostfix(const string &postfix) {
    stack<int> s;
    for (char c : postfix) {
        if (isdigit(c)) s.push(c - '0');  // Convert char to int
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            if (c == '+') s.push(a + b);
            else if (c == '-') s.push(a - b);
            else if (c == '*') s.push(a * b);
            else if (c == '/') s.push(a / b);
        }
    }
    return s.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;
    cout << "Result: " << evaluatePostfix(postfix) << endl;
    return 0;
}