#include <iostream>
using namespace std;

class Patient {
public:
    string name;
    Patient* next;

    Patient(string n) {
        name = n;
        next = nullptr;
    }
};

class HospitalQueue {
private:
    Patient* head;

public:
    HospitalQueue() {
        head = nullptr;
    }

    void addPatient(string name) {
        Patient* newPatient = new Patient(name);

        if (head == nullptr) {
            head = newPatient;
            return;
        }

        Patient* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newPatient;
    }

    void removePatient(string name) {
        if (head == nullptr) return;

        if (head->name == name) {
            Patient* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Patient* temp = head;
        Patient* prev = nullptr;

        while (temp != nullptr && temp->name != name) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        prev->next = temp->next;
        delete temp;
    }

    void displayQueue() {
        Patient* temp = head;

        while (temp != nullptr) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int countPatients() {
        int count = 0;
        Patient* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }
};

int main() {
    HospitalQueue queue;

    queue.addPatient("Ali");
    queue.addPatient("Sara");
    queue.addPatient("Usman");
    queue.addPatient("Ayesha");

    cout << "Initial Queue:\n";
    queue.displayQueue();

    cout << "\nTotal Patients: " << queue.countPatients() << endl;

    cout << "\nRemoving Sara (canceled appointment)\n";
    queue.removePatient("Sara");

    cout << "\nUpdated Queue:\n";
    queue.displayQueue();

    cout << "\nTotal Patients: " << queue.countPatients() << endl;

    return 0;
}