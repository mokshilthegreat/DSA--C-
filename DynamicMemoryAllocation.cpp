#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


Node* head = nullptr;


void append(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void display() {
    if (head == nullptr) {
        cout << "List is Empty!" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


void insert_at_beginning(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}


void Search(int key) {
    Node* temp = head;
    int pos = 1;

    while (temp != nullptr) {
        if (temp->data == key) {
            cout << key << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << key << " not found!" << endl;
}


void Delete_node(int key) {
    // if head is to delete
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << key << " deleted!" << endl;
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << key << " not found!" << endl;
        return;
    }

    prev->next = curr->next;
    delete curr;
    cout << key << " deleted!" << endl;
}

void reverse() {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    cout << "List Reversed!" << endl;
}

int main() {
    int choice, val;

    do {
        cout << "\n1. Append" << endl;
        cout << "2. Insert at Beginning" << endl;
        cout << "3. Display" << endl;
        cout << "4. Search" << endl;
        cout << "5. Delete" << endl;
        cout << "6. Reverse" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                append(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                insert_at_beginning(val);
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> val;
                Search(val);
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> val;
                Delete_node(val);
                break;
            case 6:
                reverse();
                display();
                break;
            case 0:
                cout << "Exit!" << endl;
                break;
        }

    } while (choice != 0);

    return 0;
}