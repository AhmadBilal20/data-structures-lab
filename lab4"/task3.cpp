#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class MyQueue {
private:
    queue<int> q;

public:
    void enqueue(int value) {
        q.push(value);
    }

    int dequeue() {
        if (isEmpty())
            throw runtime_error("Queue is Empty");
        int value = q.front();
        q.pop();
        return value;
    }

    int front() {
        if (isEmpty())
            throw runtime_error("Queue is Empty");
        return q.front();
    }

    bool isEmpty() {
        return q.empty();
    }

    int size() {
        return q.size();
    }

    void display() {
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    void reverseFirstK(int k) {
        int n = size();

        if (k <= 1 || k > n)
            k = min(k, n);

        stack<int> s;

        for (int i = 0; i < k; i++)
            s.push(dequeue());

        while (!s.empty()) {
            enqueue(s.top());
            s.pop();
        }

        for (int i = 0; i < n - k; i++)
            enqueue(dequeue());
    }
};

int main() {
    MyQueue q;
    int n, value, k;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter queue elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }

    cout << "Queue: ";
    q.display();

    cout << "Enter K: ";
    cin >> k;

    q.reverseFirstK(k);

    cout << "Output: ";
    q.display();

    return 0;
}