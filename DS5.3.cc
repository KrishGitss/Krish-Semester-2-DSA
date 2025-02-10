#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

class Stack {
    Node* top = nullptr;
public:
    bool isEmpty() { return !top; }
    void push(int val) { top = new Node{val, top}; }
    void pop() { if (isEmpty()) cout << "Stack Underflow!\n"; else { cout << "Popped: " << top->data << "\n"; Node* temp = top; top = top->next; delete temp; } }
    int peek() { return isEmpty() ? (cout << "Stack is empty!\n", -1) : top->data; }
    void display() { for (Node* temp = top; temp; temp = temp->next) cout << temp->data << " "; cout << "\n"; }
};

int main() {
    Stack s; int choice, value;
    do {
        cout << "\n1.Push 2.Pop 3.Peek 4.IsEmpty 5.Display 0.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; s.push(value); break;
            case 2: s.pop(); break;
            case 3: cout << "Top element: " << s.peek() << "\n"; break;
            case 4: cout << (s.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n"); break;
            case 5: s.display(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice);
    return 0;
}
