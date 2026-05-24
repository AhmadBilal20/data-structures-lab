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

// Naya node create karne ka function
ExprNode* createNode(string value)
{
    ExprNode* newNode = new ExprNode();

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Infix expression print karna
void printInfix(ExprNode* root)
{
    if (root == NULL)
        return;

    // Operator node ke liye bracket
    if (root->left != NULL || root->right != NULL)
        cout << "( ";

    // Left subtree
    printInfix(root->left);

    // Root print karna
    cout << root->data << " ";

    // Right subtree
    printInfix(root->right);

    // Closing bracket
    if (root->left != NULL || root->right != NULL)
        cout << ") ";
}

// Prefix expression
void printPrefix(ExprNode* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";

    printPrefix(root->left);
    printPrefix(root->right);
}

// Postfix expression
void printPostfix(ExprNode* root)
{
    if (root == NULL)
        return;

    printPostfix(root->left);
    printPostfix(root->right);

    cout << root->data << " ";
}

// Character digit ko integer mein convert karna
int toInt(string value)
{
    return value[0] - '0';
}

// Expression evaluate karna
int evaluate(ExprNode* root)
{
    // Agar operand ho
    if (root->left == NULL && root->right == NULL)
    {
        return toInt(root->data);
    }

    // Left aur right subtree evaluate karna
    int leftValue = evaluate(root->left);
    int rightValue = evaluate(root->right);

    // Operators perform karna
    if (root->data == "+")
        return leftValue + rightValue;

    if (root->data == "-")
        return leftValue - rightValue;

    if (root->data == "*")
        return leftValue * rightValue;

    return 0;
}

int main()
{
    // Expression tree create karna
    ExprNode* root = createNode("*");

    root->left = createNode("+");
    root->right = createNode("-");

    root->left->left = createNode("3");
    root->left->right = createNode("5");

    root->right->left = createNode("8");
    root->right->right = createNode("2");

    // Infix expression print
    cout << "Infix Expression: ";
    printInfix(root);

    cout << endl;

    // Prefix expression print
    cout << "Prefix Expression: ";
    printPrefix(root);

    cout << endl;

    // Postfix expression print
    cout << "Postfix Expression: ";
    printPostfix(root);

    cout << endl << endl;

    // Evaluation steps
    cout << "Evaluation:" << endl;
    cout << "3 + 5 = 8" << endl;
    cout << "8 - 2 = 6" << endl;
    cout << "8 * 6 = 48" << endl;

    // Final answer
    cout << "Final Answer: " << evaluate(root);

    return 0;
}
//In an expression tree Operators are usually stored in internal nodes.
//Preorder traversal gives prefix expression
//Postorder traversal gives postfix expression
//Brackets be added in inorder expression output bcz brackets make the order of operations clear
//the final answer of the given expression tree is 48