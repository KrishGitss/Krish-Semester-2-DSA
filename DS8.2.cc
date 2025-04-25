#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularQueue {
private:
    Node* rear;
public:
    CircularQueue() : rear(nullptr) {}

    bool isEmpty() { return rear == nullptr; }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            rear = newNode;
            rear->next = rear;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued\n";
    }

    void dequeue() {
        if (isEmpty()) return void(cout << "Queue is empty\n");
        Node* front = rear->next;
        cout << front->data << " dequeued\n";
        if (rear == front) rear = nullptr;
        else rear->next = front->next;
        delete front;
    }

    int peek() {
        return isEmpty() ? (cout << "Queue is empty\n", -1) : rear->next->data;
    }

    void display() {
        if (isEmpty()) return void(cout << "Queue is empty\n");
        Node* temp = rear->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != rear->next);
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();
    cout << "Peek: " << cq.peek() << endl;
    cq.dequeue();
    cq.display();
    return 0;
}