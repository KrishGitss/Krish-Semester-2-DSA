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

void traverseList(Node* head) {
    while (head) cout << head->data << " -> ", head = head->next;
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    for (int n, data; cout << "Enter number of nodes: ", cin >> n && n--; )
        cin >> data, insertBeginning(head, data);
    traverseList(head);
}