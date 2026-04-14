#include <iostream>
using namespace std;

class TicketQueue {
private:
    int* arr;
    int frontIndex;
    int rearIndex;
    int capacity;
    int count;

public:
    TicketQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    ~TicketQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    void enqueue(int ticket_id) {
        if (isFull()) {
            cout << "Queue is full. Cannot add more tickets.\n";
            return;
        }

        if (ticket_id < 1000 || ticket_id > 9999) {
            cout << "Invalid Ticket ID. Enter a 4-digit number.\n";
            return;
        }

        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = ticket_id;
        count++;
        cout << "Ticket " << ticket_id << " added successfully.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No tickets to resolve.\n";
            return;
        }

        int resolved = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        cout << "Ticket " << resolved << " resolved and removed.\n";
    }

    void front() {
        if (isEmpty()) {
            cout << "No pending tickets.\n";
            return;
        }

        cout << "Next ticket to resolve: " << arr[frontIndex] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "No pending tickets.\n";
            return;
        }

        cout << "Pending Tickets: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(frontIndex + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter maximum number of tickets: ";
    cin >> size;

    TicketQueue tq(size);

    int choice, ticket_id;

    do {
        cout << "\n1. Add Ticket\n";
        cout << "2. Resolve Ticket\n";
        cout << "3. View Next Ticket\n";
        cout << "4. Display Pending Tickets\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter 4-digit Ticket ID: ";
            cin >> ticket_id;
            tq.enqueue(ticket_id);
            break;

        case 2:
            tq.dequeue();
            break;

        case 3:
            tq.front();
            break;

        case 4:
            tq.display();
            break;

        case 0:
            cout << "Exiting system...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}