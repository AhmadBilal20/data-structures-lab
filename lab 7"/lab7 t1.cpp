#include <iostream>
#include <string>
using namespace std;

class Stack {
    char arr[100];
    int top;
public:
    Stack() { top = -1; }

    void push(char x) {
        if (top < 99) {
            arr[++top] = x;
        }
    }

    char pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return '\0';
    }

    char peek() {
        if (top >= 0) return arr[top];
        return '\0';
    }

    bool isEmpty() {
        return top == -1;
    }
};

string reverseString(string str) {
    Stack s;
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }
    string rev = "";
    while (!s.isEmpty()) {
        rev += s.pop();
    }
    return rev;
}

bool isBalanced(string exp) {
    Stack s;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(') {
            s.push(exp[i]);
        }
        else if (exp[i] == ')') {
            if (s.isEmpty()) return false;
            s.pop();
        }
    }
    return s.isEmpty();
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string exp) {
    Stack s;
    string result = "";
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if (isalnum(c)) {
            result += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                result += s.pop();
            }
            s.pop();
        }
        else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                result += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        result += s.pop();
    }
    return result;
}

int main() {
    string str = "Hello";
    cout << reverseString(str) << endl;

    string exp1 = "((a+b)*c)";
    string exp2 = "((a+b)";
    cout << (isBalanced(exp1) ? "Balanced" : "Not Balanced") << endl;
    cout << (isBalanced(exp2) ? "Balanced" : "Not Balanced") << endl;

    string infix = "(a+b)*c";
    cout << infixToPostfix(infix) << endl;

    return 0;
}