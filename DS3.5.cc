#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int data) : data(data), next(nullptr) {}
};

void insertAtEnd(Node** head, int data) {
    Node* newNode = new Node(data);
    if (*head == nullptr) *head = newNode;
    else {
        Node* temp = *head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int* listToArray(Node* head, int& size) {
    int length = 0;
    Node* temp = head;
    while (temp) { length++; temp = temp->next; }

    int* arr = new int[length];
    temp = head;
    for (int i = 0; i < length; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }
    size = length;
    return arr;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    Node* head = nullptr;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    int size = 0;
    int* arr = listToArray(head, size);
    printArray(arr, size);

    delete[] arr;
    return 0;
}