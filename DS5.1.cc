#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() : head(nullptr) {}

    void insertAtPosition(int value, int position) {
        Node* newNode = new Node(value);
        if (!head) { newNode->next = newNode; head = newNode; return; }
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp->next != head; i++) temp = temp->next;
        newNode->next = temp->next; temp->next = newNode;
    }

    void insertAtBeginning(int value) {
        insertAtPosition(value, 1);
        head = head->next;
    }

    void insertAtEnd(int value) {
        insertAtPosition(value, 1000);
    }

    void deleteFromPosition(int position) {
        if (!head) return;
        Node *temp = head, *prev = nullptr;
        if (position == 1) { deleteFirst(); return; }
        for (int i = 1; i < position && temp->next != head; i++) { prev = temp; temp = temp->next; }
        if (temp == head) return;
        prev->next = temp->next;
        delete temp;
    }

    void deleteFirst() {
        if (!head) return;
        Node* temp = head;
        if (head->next == head) { delete head; head = nullptr; return; }
        Node* last = head;
        while (last->next != head) last = last->next;
        head = head->next; last->next = head; delete temp;
    }

    void deleteLast() {
        deleteFromPosition(1000);
    }

    void display() {
        if (!head) { cout << "List is empty!\n"; return; }
        Node* temp = head;
        do { cout << temp->data << " -> "; temp = temp->next; } while (temp != head);
        cout << "(head)" << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int choice, value, position;
    do {
        cout << "\n1.Insert at position 2.Insert at beginning 3.Insert at end";
        cout << " 4.Delete from position 5.Delete first 6.Delete last 7.Display 0.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Value, Position: "; cin >> value >> position; cll.insertAtPosition(value, position); break;
            case 2: cout << "Value: "; cin >> value; cll.insertAtBeginning(value); break;
            case 3: cout << "Value: "; cin >> value; cll.insertAtEnd(value); break;
            case 4: cout << "Position: "; cin >> position; cll.deleteFromPosition(position); break;
            case 5: cll.deleteFirst(); break;
            case 6: cll.deleteLast(); break;
            case 7: cll.display(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}
