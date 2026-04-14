#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtPosition(int value, int pos) {
        Node* newNode = new Node(value);

        if (pos <= 1 || head == nullptr) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        int i = 1;

        while (temp->next != nullptr && i < pos - 1) {
            temp = temp->next;
            i++;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtPosition(int pos) {
        if (head == nullptr) return;

        Node* temp = head;

        if (pos == 1) {
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = nullptr;
        int i = 1;

        while (temp != nullptr && i < pos) {
            prev = temp;
            temp = temp->next;
            i++;
        }

        if (temp == nullptr) return;

        prev->next = temp->next;
        delete temp;
    }

    bool search(int value) {
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    int countNodes() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void display() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    int choice = 0;

    while (choice != 6) {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at Position\n";
        cout << "2. Delete at Position\n";
        cout << "3. Search Element\n";
        cout << "4. Count Nodes\n";
        cout << "5. Display List\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int value, pos;
            cout << "Enter value and position: ";
            cin >> value >> pos;
            list.insertAtPosition(value, pos);
        }
        else if (choice == 2) {
            int pos;
            cout << "Enter position: ";
            cin >> pos;
            list.deleteAtPosition(pos);
        }
        else if (choice == 3) {
            int value;
            cout << "Enter value to search: ";
            cin >> value;

            if (list.search(value))
                cout << "Found" << endl;
            else
                cout << "Not Found" << endl;
        }
        else if (choice == 4) {
            cout << "Total Nodes: " << list.countNodes() << endl;
        }
        else if (choice == 5) {
            list.display();
        }
    }

    return 0;
}