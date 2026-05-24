#include <iostream>
using namespace std;

// Expression tree node 
class ExprNode
{
public:
    string data;
    ExprNode* left;
    ExprNode* right;
};

// Stack using CLASS 
class Stack
{
public:
    ExprNode* arr[100];
    int top;

    Stack()
    {
        top = -1;
    }

    void push(ExprNode* value)
    {
        arr[++top] = value;
    }

    ExprNode* pop()
    {
        return arr[top--];
    }

    bool empty()
    {
        return top == -1;
    }
};

// Node create function
ExprNode* createNode(string value)
{
    ExprNode* newNode = new ExprNode();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Check operator
bool isOperator(string c)
{
    return (c == "+" || c == "-" || c == "*");
}

// Build expression tree from postfix
ExprNode* buildTree(string postfix[], int size)
{
    Stack s;

    for (int i = 0; i < size; i++)
    {
        string symbol = postfix[i];

        if (!isOperator(symbol))
        {
            s.push(createNode(symbol));
        }
        else
        {
            ExprNode* right = s.pop();
            ExprNode* left = s.pop();

            ExprNode* newNode = createNode(symbol);
            newNode->left = left;
            newNode->right = right;

            s.push(newNode);
        }
    }

    return s.pop();
}

// Inorder 
void printInfix(ExprNode* root)
{
    if (root == NULL)
        return;

    if (root->left != NULL || root->right != NULL)
        cout << "( ";

    printInfix(root->left);
    cout << root->data << " ";
    printInfix(root->right);

    if (root->left != NULL || root->right != NULL)
        cout << ") ";
}

// Preorder
void printPrefix(ExprNode* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    printPrefix(root->left);
    printPrefix(root->right);
}

// Postorder
void printPostfix(ExprNode* root)
{
    if (root == NULL)
        return;

    printPostfix(root->left);
    printPostfix(root->right);
    cout << root->data << " ";
}

// char to int
int toInt(string s)
{
    return s[0] - '0';
}

// Evaluate tree
int evaluate(ExprNode* root)
{
    if (root->left == NULL && root->right == NULL)
        return toInt(root->data);

    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);

    if (root->data == "+")
        return leftVal + rightVal;

    if (root->data == "-")
        return leftVal - rightVal;

    if (root->data == "*")
        return leftVal * rightVal;

    return 0;
}

int main()
{
    string postfix[] = { "3", "5", "+", "8", "2", "-", "*" };
    int size = 7;

    ExprNode* root = buildTree(postfix, size);

    cout << "Infix Expression: ";
    printInfix(root);
    cout << endl;

    cout << "Prefix Expression: ";
    printPrefix(root);
    cout << endl;

    cout << "Postfix Expression: ";
    printPostfix(root);
    cout << endl << endl;

    cout << "Final Answer: " << evaluate(root);

    return 0;
}