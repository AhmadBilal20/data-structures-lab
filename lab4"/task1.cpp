#include <iostream>
using namespace std;

template <typename T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual void display() const = 0;
    virtual ~AbstractQueue() {}
};

template <typename T>
class myQueue : public AbstractQueue<T> {
private:
    T* arr;
    int capacity;
    int frontIndex;
    int rearIndex;
    int currentSize;

public:
    myQueue(int size) {
        capacity = size;
        arr = new T[capacity];
        frontIndex = 0;
        rearIndex = -1;
        currentSize = 0;
    }

    ~myQueue() {
        delete[] arr;
    }

    void enQueue(T value) override {
        if (isFull()) {
            cout << "Queue is FULL! Cannot enqueue." << endl;
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = value;
        currentSize++;
        cout << "Enqueued: " << value << endl;
    }

    T deQueue() override {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Cannot dequeue." << endl;
            throw runtime_error("Queue is empty");
        }
        T temp = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;
        cout << "Dequeued: " << temp << endl;
        return temp;
    }

    T front() const override {
        if (isEmpty()) {
            cout << "Queue is EMPTY! No front element." << endl;
            throw runtime_error("Queue is empty");
        }
        return arr[frontIndex];
    }

    bool isEmpty() const override {
        return currentSize == 0;
    }

    bool isFull() const override {
        return currentSize == capacity;
    }

    void display() const override {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
            return;
        }

        cout << "Queue elements (front to rear): ";
        int count = 0;
        int tempFront = frontIndex;

        while (count < currentSize) {
            cout << arr[tempFront] << " ";
            tempFront = (tempFront + 1) % capacity;
            count++;
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter maximum size of queue: ";
    cin >> capacity;

    myQueue<int> queue(capacity);

    int choice;
    int value;

    do {
        cout << "\n=== QUEUE OPERATIONS MENU ===\n";
        cout << "1. EnQueue\n";
        cout << "2. DeQueue\n";
        cout << "3. Front\n";
        cout << "4. IsEmpty\n";
        cout << "5. IsFull\n";
        cout << "6. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            queue.enQueue(value);
            break;

        case 2:
            try {
                queue.deQueue();
            }
            catch (const exception& e) {
                cout << e.what() << endl;
            }
            break;

        case 3:
            try {
                cout << "Front element: " << queue.front() << endl;
            }
            catch (const exception& e) {
                cout << e.what() << endl;
            }
            break;

        case 4:
            cout << "Is Empty: " << (queue.isEmpty() ? "YES" : "NO") << endl;
            break;

        case 5:
            cout << "Is Full: " << (queue.isFull() ? "YES" : "NO") << endl;
            break;

        case 6:
            queue.display();
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}