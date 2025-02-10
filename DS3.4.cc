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

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void arrayToList(int arr[], int size, Node** head) {
    for (int i = 0; i < size; i++) insertAtEnd(head, arr[i]);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    Node* head = nullptr;
    
    arrayToList(arr, sizeof(arr) / sizeof(arr[0]), &head);
    printList(head);
    
    return 0;
}