#include<iostream>
using namespace std;

class Package {
public:
    int id;
    string address;
    int startTime;
    int endTime;

    Package() {
        id = 0;
        address = "";
        startTime = 0;
        endTime = 0;
    }

    void setData(int i, string a, int s, int e) {
        id = i;
        address = a;
        startTime = s;
        endTime = e;
    }
};

class Queue {
public:
    Package* arr;
    int size;
    int front;
    int rear;

    Queue(int size) {
        this->size = size;
        arr = new Package[size];
        front = 0;
        rear = 0;
    }

    void enqueue(int id, string address, int start, int end) {
        if (rear == size) {
            cout << "Queue is full\n";
            return;
        }

        arr[rear].setData(id, address, start, end);
        rear++;
    }

    void frontPackage() {
        if (front == rear) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Front Package -> ID: " << arr[front].id
            << ", Address: " << arr[front].address
            << ", Time Window: [" << arr[front].startTime
            << ", " << arr[front].endTime << "]\n";
    }

    void dequeue() {
        if (front == rear) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Delivered Package ID: " << arr[front].id << endl;
        front++;
    }

    void timeToDeliver(int currentTime) {
        if (front == rear) {
            cout << "Queue is empty\n";
            return;
        }

        if (currentTime >= arr[front].startTime &&
            currentTime <= arr[front].endTime) {

            cout << "Package ID " << arr[front].id
                << " is ready for delivery\n";
        }
        else {
            cout << "Package ID " << arr[front].id
                << " expired/not valid → skipping\n";
            front++;
        }
    }

    void display() {
        if (front == rear) {
            cout << "Queue is empty\n";
            return;
        }

        for (int i = front; i < rear; i++) {
            cout << "ID: " << arr[i].id
                << ", Address: " << arr[i].address
                << ", Time: [" << arr[i].startTime
                << ", " << arr[i].endTime << "]\n";
        }
    }
};

int main() {
    Queue q(5);

    q.enqueue(1, "Lahore", 10, 15);
    q.enqueue(2, "Karachi", 12, 18);
    q.enqueue(3, "Islamabad", 8, 11);

    cout << "\n--- All Packages ---\n";
    q.display();

    cout << "\n--- Time Check (current time = 10) ---\n";
    q.timeToDeliver(10);

    cout << "\n--- Front Package ---\n";
    q.frontPackage();

    cout << "\n--- Dequeue ---\n";
    q.dequeue();

    cout << "\n--- Remaining ---\n";
    q.display();

    return 0;
}