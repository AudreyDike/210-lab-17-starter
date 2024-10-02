#include <iostream>
#include <cstdlib> // For rand()
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// Function prototypes
void output(Node *);
void addToFront(Node *&, float);
void addToTail(Node *&, float);
void deleteNode(Node *&, int);
void insertAfter(Node *&, int, float);
void deleteList(Node *&);

int main() {
    Node *head = nullptr;

    // Create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        addToFront(head, tmp_val);  // Add new value to the front
    }
    output(head);

    // Deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    deleteNode(head, entry);
    output(head);

    // Insert a node
    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    insertAfter(head, entry, 10000);
    output(head);

    // Deleting the linked list
    deleteList(head);
    output(head);

    return 0;
}

// Function to output the linked list
void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

// Function to add a node to the front of the list
void addToFront(Node *&head, float value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
}

// Function to add a node to the tail of the list
void addToTail(Node *&head, float value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (!head) {
        head = newNode; // If the list is empty, newNode becomes the head
    } else {
        Node *current = head;
        while (current->next) {
            current = current->next; // Traverse to the end
        }
        current->next = newNode; // Attach newNode at the end
    }
}

// Function to delete a node at a specific position
void deleteNode(Node *&head, int position) {
    if (!head) return; // If the list is empty

    Node *current = head;
    Node *prev = nullptr;

    if (position == 1) { // Special case: delete head
        head = current->next; // Change head
        delete current; // Free old head
        return;
    }

    // Traverse to find the node to delete
    for (int i = 1; current != nullptr && i < position; i++) {
        prev = current;
        current = current->next;
    }

    if (!current) return; // If position is more than number of nodes

    prev->next = current->next; // Unlink the node from the list
    delete current; // Free memory
}

// Function to insert a node after a given position
void insertAfter(Node *&head, int position, float value) {
    Node *current = head;
    Node *newNode = new Node;
    newNode->value = value;

    if (position == 1) { // Insert at the head
        newNode->next = head;
        head = newNode;
        return;
    }

    for (int i = 1; current != nullptr && i < position; i++) {
        current = current->next; // Traverse to the position
    }

    if (current) {
        newNode->next = current->next; // Link newNode to current's next
        current->next = newNode; // Link current to newNode
    } else {
        delete newNode; // If position is out of bounds, free memory
    }
}

// Function to delete the entire linked list
void deleteList(Node *&head) {
    Node *current = head;
    while (current) {
        Node *nextNode = current->next;
        delete current; // Delete current node
        current = nextNode; // Move to the next node
    }
    head = nullptr; // Set head to nullptr
}
