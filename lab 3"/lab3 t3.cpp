#include <iostream>
#include <string>
using namespace std;

class myCarStack {
private:
    string arr[8];
    int topIndex;

public:
    myCarStack() {
        topIndex = -1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == 7;
    }

    void push(string car) {
        if (isFull()) {
            cout << "Parking is full\n";
            return;
        }
        arr[++topIndex] = car;
        cout << "Car parked: " << car << endl;
    }

    string pop() {
        if (isEmpty()) {
            cout << "Parking is empty\n";
            return "";
        }
        return arr[topIndex--];
    }

    string top() {
        if (isEmpty()) {
            return "";
        }
        return arr[topIndex];
    }

    int count() {
        return topIndex + 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "No cars parked\n";
            return;
        }
        int i = topIndex;
        cout << "Cars in parking (top to bottom):\n";
        while (i >= 0) {
            cout << arr[i] << endl;
            i--;
        }
    }

    bool search(string car) {
        int i = topIndex;
        while (i >= 0) {
            if (arr[i] == car) {
                return true;
            }
            i--;
        }
        return false;
    }

    void removeCar(string car) {
        if (isEmpty()) {
            cout << "Parking is empty\n";
            return;
        }

        myCarStack temp;
        bool found = false;

        while (!isEmpty()) {
            if (top() == car) {
                pop();
                found = true;
                cout << "Car removed: " << car << endl;
                break;
            }
            else {
                temp.push(pop());
            }
        }

        while (!temp.isEmpty()) {
            push(temp.pop());
        }

        if (!found) {
            cout << "Car not found\n";
        }
    }
};

int main() {
    myCarStack parking;
    int choice = -1;
    string car;

    while (choice != 6) {
        cout << "\n1 Park Car\n2 Remove Car\n3 Show Cars\n4 Total Cars\n5 Search Car\n6 Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter car number: ";
            cin >> car;
            parking.push(car);
        }
        else if (choice == 2) {
            cout << "Enter car number to remove: ";
            cin >> car;
            parking.removeCar(car);
        }
        else if (choice == 3) {
            parking.display();
        }
        else if (choice == 4) {
            cout << "Total cars: " << parking.count() << endl;
        }
        else if (choice == 5) {
            cout << "Enter car number to search: ";
            cin >> car;
            if (parking.search(car))
                cout << "Car found\n";
            else
                cout << "Car not found\n";
        }
    }

    return 0;
}