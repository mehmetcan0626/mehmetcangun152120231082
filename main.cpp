#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};


void addWord(Node*& head, const string& word) {
    Node* newNode = new Node;
    newNode->data = word;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void undo(Node*& head) {
    if (head == nullptr) {
        cout << "The list is already empty!" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        while (temp->next != nullptr && temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "[" << temp->data << "] -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    string input;

    while (true) {
        cout << "Enter a word (or type 'UNDO' to remove the last word, 'EXIT' to quit): ";
        getline(cin, input);

        if (input == "EXIT") {
            break;
        } else if (input == "UNDO") {
            undo(head);
        } else {
            addWord(head, input);
        }
        display(head);
    }

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
