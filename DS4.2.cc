#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
    Node(int data) : data(data), link(nullptr) {}
};

void array_to_linked_list(Node* head, int n, int array[], Node** current) {
    for (int i = 2; i < n; i++) {
        (*current)->link = new Node(array[i]);
        *current = (*current)->link;
    }
}

void remove_duplicate(Node* head) {
    Node* current = head;
    while (current) {
        Node* prev = current;
        Node* next = current->link;
        while (next) {
            if (current->data == next->data) {
                prev->link = next->link;
                delete next;
                next = prev->link;
            } else {
                prev = next;
                next = next->link;
            }
        }
        current = current->link;
    }
}

void print(Node* head) {
    for (Node* temp = head; temp; temp = temp->link) {
        cout << temp->data << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int* array = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    Node* head = new Node(array[0]);
    Node* current = head;
    array_to_linked_list(head, n, array, &current);
    
    cout << "Original list: ";
    print(head);
    
    remove_duplicate(head);
    
    cout << "List after removing duplicates: ";
    print(head);
    
    delete[] array;
    return 0;
}
