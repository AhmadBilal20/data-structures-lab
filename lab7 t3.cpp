#include <iostream>
using namespace std;

class Queue {
    string arr[100];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(string x) {
        if (rear == 99) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    string dequeue() {
        if (isEmpty()) return "";
        string val = arr[front];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }
        return val;
    }

    void display() {
        if (isEmpty()) {
            cout << "Empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Airport {
    Queue emergencyQ, passengerQ, cargoQ;

public:
    void enqueue(string type, string id) {
        if (type == "E")
            emergencyQ.enqueue(id);
        else if (type == "P")
            passengerQ.enqueue(id);
        else if (type == "C")
            cargoQ.enqueue(id);
    }

    void dequeue() {
        if (!emergencyQ.isEmpty())
            cout << emergencyQ.dequeue() << " landed\n";
        else if (!passengerQ.isEmpty())
            cout << passengerQ.dequeue() << " landed\n";
        else if (!cargoQ.isEmpty())
            cout << cargoQ.dequeue() << " landed\n";
        else
            cout << "No flights\n";
    }

    void display() {
        cout << "Emergency: ";
        emergencyQ.display();
        cout << "Passenger: ";
        passengerQ.display();
        cout << "Cargo: ";
        cargoQ.display();
    }
};

int main() {
    Airport a;

    a.enqueue("P", "P1");
    a.enqueue("C", "C1");
    a.enqueue("E", "E1");
    a.enqueue("P", "P2");
    a.enqueue("C", "C2");
    a.enqueue("E", "E2");

    a.display();

    cout << "\nLanding Order:\n";
    for (int i = 0; i < 6; i++) {
        a.dequeue();
    }

    return 0;
}