#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    string arr[100];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == 99;
    }

    void push(string val) {
        if (!isFull()) {
            arr[++topIndex] = val;
        }
    }

    string pop() {
        if (!isEmpty()) {
            return arr[topIndex--];
        }
        return "";
    }

    string top() {
        if (!isEmpty()) {
            return arr[topIndex];
        }
        return "";
    }

    void clear() {
        topIndex = -1;
    }
};

class TextEditor {
private:
    string text;
    Stack undoStack;
    Stack redoStack;

public:
    void type(char ch) {
        undoStack.push(text);
        text += ch;
        redoStack.clear();
    }

    void del() {
        if (text.empty()) {
            cout << "Nothing to delete\n";
            return;
        }
        undoStack.push(text);
        text.erase(text.length() - 1);
        redoStack.clear();
    }

    void undo() {
        if (undoStack.isEmpty()) {
            cout << "Nothing to undo\n";
            return;
        }
        redoStack.push(text);
        text = undoStack.pop();
    }

    void redo() {
        if (redoStack.isEmpty()) {
            cout << "Nothing to redo\n";
            return;
        }
        undoStack.push(text);
        text = redoStack.pop();
    }

    void display() {
        cout << "Current Text: " << text << endl;
    }
};

int main() {
    TextEditor editor;
    int choice = -1;
    char ch;

    while (choice != 6) {
        cout << "\n1 Type Character\n2 Delete Character\n3 Undo\n4 Redo\n5 Display Text\n6 Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter character: ";
            cin >> ch;
            editor.type(ch);
        }
        else if (choice == 2) {
            editor.del();
        }
        else if (choice == 3) {
            editor.undo();
        }
        else if (choice == 4) {
            editor.redo();
        }
        else if (choice == 5) {
            editor.display();
        }
    }

    return 0;
}