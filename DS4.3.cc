#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
    Node(int data) : data(data), link(nullptr) {}
};

void array_to_linked_list(Node* head, int n, int array[], Node* current) {
    for (int i = 2; i < n; i++) {
        current->link = new Node(array[i]);
        current = current->link;
    }
}

void remove_duplicate(Node* head) {
    for (Node* current = head; current; current = current->link) {
        Node* prev = current;
        for (Node* next = current->link; next; next = next->link) {
            if (current->data == next->data) {
                prev->link = next->link;
                delete next;
                break;
            } else {
                prev = next;
            }
        }
    }
}

void print(Node* head) {
    for (Node* temp = head; temp; temp = temp->link) {
        cout << temp->data << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int* array = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    
    Node* head = new Node(array[0]);
    Node* current = head;
    array_to_linked_list(head, n, array, current);
    
    cout << "Contents of the list:" << endl;
    print(head);
    
    remove_duplicate(head);
    
    cout << "List after removing duplicates:" << endl;
    print(head);
    
    delete[] array;
    return 0;
}