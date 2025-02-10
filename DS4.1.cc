#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
    Node(int data) : data(data), link(nullptr) {}
};

void array_to_linked_list(Node* head, int n, int array[], Node** current) {
    for (int i = 2; i < n; i++) {
        *current = (*current)->link = new Node(array[i]);
    }
}

void rotate(Node** head, int k, int count) {
    if (k == 0) return;
    k %= count;
    if (k == 0) return;
    
    Node* current = *head;
    for (int i = 1; i < k; i++) current = current->link;
    
    Node* new_head = current->link;
    current->link = nullptr;
    
    Node* temp = new_head;
    while (temp->link) temp = temp->link;
    
    temp->link = *head;
    *head = new_head;
}

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->link;
    }
    cout << endl;
}

int main() {
    int n, k;
    cout << "Enter the number of nodes: ";
    cin >> n;
    
    int* array = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> array[i];
    }
    
    Node* head = new Node(array[0]);
    Node* current = new Node(array[1]);
    head->link = current;
    
    if (n > 2) array_to_linked_list(head, n, array, &current);
    
    cout << "Original list: ";
    print(head);
    
    cout << "Enter rotation value: ";
    cin >> k;
    
    rotate(&head, k, n);
    cout << "Rotated list: ";
    print(head);
    
    delete[] array;
    return 0;
}
