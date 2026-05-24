#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node* left;
    Node* right;
};

// Stack class
class Stack
{
public:
    Node* arr[100];
    int top;
};

// Stack ko initialize karna
void init(Stack& s)
{
    s.top = -1;
}

// Push function
void push(Stack& s, Node* value)
{
    s.top++;
    s.arr[s.top] = value;
}

// Pop function
Node* pop(Stack& s)
{
    Node* temp = s.arr[s.top];
    s.top--;
    return temp;
}

// Check karna stack empty hai ya nahi
bool isEmpty(Stack& s)
{
    return s.top == -1;
}

// Naya node create karne ka function
Node* createNode(int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// DFS Traversal function
void DFS(Node* root)
{
    // Agar tree empty ho
    if (root == NULL)
    {
        cout << "Tree is empty";
        return;
    }

    // Stack create karna
    Stack s;
    init(s);

    // Root node ko stack mein push karna
    push(s, root);

    // Jab tak stack empty na ho
    while (!isEmpty(s))
    {
        // Top node ko pop karna
        Node* temp = pop(s);

        // Node print karna
        cout << temp->data << " ";

        // Right child ko pehle push karna
        if (temp->right != NULL)
        {
            push(s, temp->right);
        }

        // Left child ko baad mein push karna
        if (temp->left != NULL)
        {
            push(s, temp->left);
        }
    }
}

int main()
{
    // Binary tree create karna
    Node* root = createNode(40);

    root->left = createNode(20);
    root->right = createNode(60);

    root->left->left = createNode(10);
    root->left->right = createNode(30);

    root->right->left = createNode(50);
    root->right->right = createNode(70);

    // DFS traversal call
    cout << "DFS Traversal: ";
    DFS(root);

    return 0;
}
//A stack data structure is used in DFS.
//we push the right child before the left child because stack follows LIFO so the left child is processed first
//DFS different from BSF bcz DFS goes deep first while BFS visits nodes level by level.
//Yes preorder traversal is a form of DFS because it visits nodes deeply before returning.