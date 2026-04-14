#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> stack1;
    stack<int> stack2;

    void transferStacks() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

public:
    void enqueue(int value) {
        stack1.push(value);
    }

    int dequeue() {
        if (stack2.empty()) {
            if (stack1.empty())
                throw runtime_error("Queue is Empty");
            transferStacks();
        }
        int value = stack2.top();
        stack2.pop();
        return value;
    }

    int front() {
        if (stack2.empty()) {
            if (stack1.empty())
                throw runtime_error("Queue is Empty");
            transferStacks();
        }
        return stack2.top();
    }

    void display() {
        if (stack1.empty() && stack2.empty()) {
            cout << "Queue is Empty\n";
            return;
        }

        stack<int> temp1 = stack1;
        stack<int> temp2 = stack2;
        stack<int> reverseStack;

        while (!temp2.empty()) {
            cout << temp2.top() << " ";
            temp2.pop();
        }

        while (!temp1.empty()) {
            reverseStack.push(temp1.top());
            temp1.pop();
        }

        while (!reverseStack.empty()) {
            cout << reverseStack.top() << " ";
            reverseStack.pop();
        }

        cout << endl;
    }
};

int main() {
    QueueUsingStacks q;
    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n0. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            try {
                cout << q.dequeue() << endl;
            }
            catch (exception& e) {
                cout << e.what() << endl;
            }
            break;
        case 3:
            try {
                cout << q.front() << endl;
            }
            catch (exception& e) {
                cout << e.what() << endl;
            }
            break;
        case 4:
            q.display();
            break;
        }
    } while (choice != 0);

    return 0;
}