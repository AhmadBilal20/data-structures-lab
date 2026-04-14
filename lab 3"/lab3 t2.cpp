#include <iostream>
using namespace std;

template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() {}
};

template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    T* minArr;
    int maxSize;
    int topIndex;
    int minTop;

public:
    myStack(int size) {
        maxSize = size;
        arr = new T[maxSize];
        minArr = new T[maxSize];
        topIndex = -1;
        minTop = -1;
    }

    ~myStack() {
        delete[] arr;
        delete[] minArr;
    }

    void push(T value) override {
        if (isFull()) {
            cout << "Stack is full\n";
            return;
        }

        arr[++topIndex] = value;

        if (minTop == -1 || value <= minArr[minTop]) {
            minArr[++minTop] = value;
        }
    }

    T pop() override {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return T();
        }

        T removed = arr[topIndex--];

        if (removed == minArr[minTop]) {
            minTop--;
        }

        return removed;
    }

    T top() const override {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return T();
        }
        return arr[topIndex];
    }

    bool isEmpty() const override {
        return topIndex == -1;
    }

    bool isFull() const override {
        return topIndex == maxSize - 1;
    }

    T getMin() const {
        if (minTop == -1) {
            cout << "Stack is empty\n";
            return T();
        }
        return minArr[minTop];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        int i = topIndex;
        while (i >= 0) {
            cout << arr[i] << endl;
            i--;
        }
    }
};

int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    myStack<int> stack(size);

    int choice = -1;
    int value;

    while (choice != 7) {
        cout << "\n1 Push\n2 Pop\n3 Top\n4 isEmpty\n5 isFull\n6 Display\n7 Show Min & Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            stack.push(value);
        }
        else if (choice == 2) {
            cout << stack.pop() << endl;
        }
        else if (choice == 3) {
            cout << stack.top() << endl;
        }
        else if (choice == 4) {
            cout << (stack.isEmpty() ? "Empty\n" : "Not Empty\n");
        }
        else if (choice == 5) {
            cout << (stack.isFull() ? "Full\n" : "Not Full\n");
        }
        else if (choice == 6) {
            stack.display();
        }
        else if (choice == 7) {
            cout << "Minimum element: " << stack.getMin() << endl;
        }
    }

    return 0;
}