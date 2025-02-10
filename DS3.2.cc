#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertBeginning(Node*& head, int data) {
    head = new Node(data); {data, head};
}

void displayList(Node* head) {
    while (head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    int n, data;
    cout << "Enter number of nodes: ";
    cin >> n;
    while (n-- && cin >> data) insertBeginning(head, data);
    displayList(head);
    return 0;
}