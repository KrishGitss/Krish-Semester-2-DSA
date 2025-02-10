#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev, *next;
    Node(int new_data) : data(new_data), prev(nullptr), next(nullptr) {}
};

void insert_at_first(Node** head, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = *head;
    if (*head) (*head)->prev = new_node;
    *head = new_node;
}

void insert_at_end(Node** head, int new_data) {
    Node* new_node = new Node(new_data);
    if (!*head) {
        *head = new_node;
        return;
    }
    Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
}

void insert_at_middle(Node** head, int new_data) {
    Node *slow = *head, *fast = *head;
    Node* new_node = new Node(new_data);
    if (!*head) { *head = new_node; return; }
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    new_node->next = slow;
    new_node->prev = slow->prev;
    if (slow->prev) slow->prev->next = new_node;
    else *head = new_node;
    slow->prev = new_node;
}

void insert_after_node(Node** head, int given_node, int new_data) {
    Node* temp = *head;
    while (temp && temp->data != given_node) temp = temp->next;
    if (!temp) return;
    Node* new_node = new Node(new_data);
    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next) temp->next->prev = new_node;
    temp->next = new_node;
}

void display(Node* head) {
    for (Node* temp = head; temp; temp = temp->next) cout << temp->data << " ";
    cout << endl;
}

int main() {
    Node* head = nullptr;
    insert_at_first(&head, 20);
    insert_at_first(&head, 10);
    insert_at_end(&head, 30);
    insert_at_end(&head, 40);
    insert_at_middle(&head, 25);
    insert_after_node(&head, 30, 35);
    display(head);
    return 0;
}