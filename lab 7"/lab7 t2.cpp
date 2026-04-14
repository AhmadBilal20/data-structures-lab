#include <iostream>
using namespace std;

class Node {
public:
    int roll;
    string name;
    float marks;
    Node* next;

    Node(int r, string n, float m) {
        roll = r;
        name = n;
        marks = m;
        next = NULL;
    }
};

class StudentList {
    Node* head;

public:
    StudentList() {
        head = NULL;
    }

    void insertAtStart(int r, string n, float m) {
        Node* newNode = new Node(r, n, m);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int r, string n, float m) {
        Node* newNode = new Node(r, n, m);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAfterRoll(int key, int r, string n, float m) {
        Node* temp = head;
        while (temp != NULL && temp->roll != key) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Roll not found\n";
            return;
        }
        Node* newNode = new Node(r, n, m);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteByRoll(int key) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        if (head->roll == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->roll != key) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "Roll not found\n";
            return;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->roll << " " << temp->name << " " << temp->marks << endl;
            temp = temp->next;
        }
    }

    void search(int key) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->roll == key) {
                cout << temp->roll << " " << temp->name << " " << temp->marks << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found\n";
    }

    void update(int key) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->roll == key) {
                cout << "Enter new name: ";
                cin >> temp->name;
                cout << "Enter new marks: ";
                cin >> temp->marks;
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found\n";
    }

    void statistics() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        float max = head->marks, min = head->marks, sum = 0;
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->marks > max) max = temp->marks;
            if (temp->marks < min) min = temp->marks;
            sum += temp->marks;
            count++;
            temp = temp->next;
        }
        cout << "Highest: " << max << endl;
        cout << "Lowest: " << min << endl;
        cout << "Average: " << sum / count << endl;
    }
};

int main() {
    StudentList list;
    int choice, roll, key;
    string name;
    float marks;

    do {
        cout << "\n1.Insert Start\n2.Insert End\n3.Insert After Roll\n4.Delete\n5.Display\n6.Search\n7.Update\n8.Statistics\n9.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cin >> roll >> name >> marks;
            list.insertAtStart(roll, name, marks);
            break;
        case 2:
            cin >> roll >> name >> marks;
            list.insertAtEnd(roll, name, marks);
            break;
        case 3:
            cin >> key >> roll >> name >> marks;
            list.insertAfterRoll(key, roll, name, marks);
            break;
        case 4:
            cin >> roll;
            list.deleteByRoll(roll);
            break;
        case 5:
            list.display();
            break;
        case 6:
            cin >> roll;
            list.search(roll);
            break;
        case 7:
            cin >> roll;
            list.update(roll);
            break;
        case 8:
            list.statistics();
            break;
        }
    } while (choice != 9);

    return 0;
}