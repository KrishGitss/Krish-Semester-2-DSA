#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
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
    while (n--) {
        cin >> data;
        insertEnd(head, data);
    }
    displayList(head);
    return 0;
}