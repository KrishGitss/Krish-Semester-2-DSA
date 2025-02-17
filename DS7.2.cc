#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
    Node *front, *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value) {
        Node* newNode = new Node(value);
        rear ? rear->next = newNode : front = newNode;
        rear = newNode;
        cout << value << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) return void(cout << "Queue underflow!\n");
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        cout << temp->data << " dequeued.\n";
        delete temp;
    }

    int peek() { return isEmpty() ? (cout << "Queue is empty!\n", -1) : front->data; }
    bool isEmpty() { return !front; }
    bool isFull() { return false; }

    void display() {
        for (Node* temp = front; temp; temp = temp->next) cout << temp->data << " ";
        cout << (isEmpty() ? "Queue is empty!" : "") << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10), q.enqueue(20), q.enqueue(30), q.display();
    cout << "Front element: " << q.peek() << endl;
    q.dequeue(), q.display();
    cout << "Queue is empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}