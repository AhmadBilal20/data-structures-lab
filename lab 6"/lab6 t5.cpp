#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int priority;
    Student* next;

    Student(string n, int p) {
        name = n;
        priority = p;
        next = nullptr;
    }
};

class BookQueue {
private:
    string bookName;
    Student* head;

public:
    BookQueue(string name) {
        bookName = name;
        head = nullptr;
    }

    void addStudent(string name, int priority) {
        Student* newNode = new Student(name, priority);

        if (head == nullptr || priority < head->priority) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Student* temp = head;

        while (temp->next != nullptr && temp->next->priority <= priority) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void removeStudent(string name) {
        if (head == nullptr) return;

        if (head->name == name) {
            Student* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Student* temp = head;
        Student* prev = nullptr;

        while (temp != nullptr && temp->name != name) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        prev->next = temp->next;
        delete temp;
    }

    void updatePriority(string name, int newPriority) {
        if (head == nullptr) return;

        Student* temp = head;
        Student* prev = nullptr;

        while (temp != nullptr && temp->name != name) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        string studentName = temp->name;
        removeStudent(name);
        addStudent(studentName, newPriority);
    }

    void display() {
        cout << "\nBook: " << bookName << endl;

        Student* temp = head;

        while (temp != nullptr) {
            cout << temp->name << " (Priority " << temp->priority << ") -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    int countStudents() {
        int count = 0;
        Student* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void issueBook() {
        if (head == nullptr) {
            cout << "No reservations.\n";
            return;
        }

        Student* temp = head;
        cout << "Book issued to: " << head->name << endl;
        head = head->next;
        delete temp;
    }
};

int main() {
    BookQueue book1("Data Structures");
    BookQueue book2("Operating Systems");

    book1.addStudent("Ali", 2);
    book1.addStudent("Sara", 1);
    book1.addStudent("Usman", 3);

    book2.addStudent("Ayesha", 1);
    book2.addStudent("Hamza", 2);
    book2.addStudent("Zara", 3);

    cout << "Initial Reservation Lists:";
    book1.display();
    book2.display();

    cout << "\nUpdating priority of Usman in Book1 (to High)\n";
    book1.updatePriority("Usman", 1);

    book1.display();

    cout << "\nCancel reservation (Hamza from Book2)\n";
    book2.removeStudent("Hamza");

    book2.display();

    cout << "\nIssuing Book1:\n";
    book1.issueBook();

    book1.display();

    cout << "\nTotal students in Book1: " << book1.countStudents() << endl;
    cout << "Total students in Book2: " << book2.countStudents() << endl;

    return 0;
}