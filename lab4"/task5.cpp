#include <iostream>
#include <string>
using namespace std;

class PrintQueue {
private:
    string arr[100];
    int frontIndex;
    int rearIndex;
    int capacity;

public:
    PrintQueue() {
        frontIndex = -1;
        rearIndex = -1;
        capacity = 100;
    }

    bool isEmpty() {
        return (frontIndex == -1 || frontIndex > rearIndex);
    }

    bool isFull() {
        return (rearIndex == capacity - 1);
    }

    void enqueue(string document_name) {
        if (isFull()) {
            cout << "Print Queue is Full\n";
            return;
        }

        if (frontIndex == -1)
            frontIndex = 0;

        rearIndex++;
        arr[rearIndex] = document_name;
        cout << "Added: " << document_name << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Print Queue is Empty\n";
            return;
        }

        cout << "Printing: " << arr[frontIndex] << endl;
        frontIndex++;

        if (frontIndex > rearIndex) {
            frontIndex = rearIndex = -1;
        }
    }

    void front() {
        if (isEmpty()) {
            cout << "Print Queue is Empty\n";
            return;
        }

        cout << "Front Document: " << arr[frontIndex] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Print Queue is Empty\n";
            return;
        }

        cout << "Remaining Print Jobs:\n";
        for (int i = frontIndex; i <= rearIndex; i++) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    PrintQueue pq;
    int choice;
    string document;

    do {
        cout << "\n1. Add Print Job\n";
        cout << "2. Print Document\n";
        cout << "3. Check Front Document\n";
        cout << "4. Display Print Queue\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter document name: ";
            getline(cin, document);
            pq.enqueue(document);
            break;
        case 2:
            pq.dequeue();
            break;
        case 3:
            pq.front();
            break;
        case 4:
            pq.display();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}