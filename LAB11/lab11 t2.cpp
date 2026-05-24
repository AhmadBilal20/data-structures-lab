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

// Naya node banane ka function
Node* createNode(int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Inorder Traversal
// Rule: Left -> Root -> Right
void inorder(Node* root)
{
    // Base condition
    // Agar node NULL ho to function wapas chala jaye
    if (root == NULL)
        return;

    // Pehle left subtree visit karo
    inorder(root->left);

    // Phir root node print karo
    cout << root->data << " ";

    // Phir right subtree visit karo
    inorder(root->right);
}

// Preorder Traversal
// Rule: Root -> Left -> Right
void preorder(Node* root)
{
    // Base condition
    // Agar node NULL ho to function end ho jaye
    if (root == NULL)
        return;

    // Sab se pehle root node print karo
    cout << root->data << " ";

    // then left subtree visit karo
    preorder(root->left);

    // last mein right subtree visit karo
    preorder(root->right);
}

int main()
{
    // Root node create karna
    Node* root = createNode(40);

    // Left aur right child add karna
    root->left = createNode(20);
    root->right = createNode(60);

    // Left subtree ke nodes
    root->left->left = createNode(10);
    root->left->right = createNode(30);

    // Right subtree ke nodes
    root->right->left = createNode(50);
    root->right->right = createNode(70);

    // Inorder traversal call
    cout << "Inorder Traversal: ";
    inorder(root);

    cout << endl;

    // Preorder traversal call
    cout << "Preorder Traversal: ";
    preorder(root);

    return 0;
}
//Preorder traversal prints the root node first.
//Inorder traversal visits the left subtree before printing the root.
//recursion suitable for tree traversal Because each subtree of a binary tree is itself a smaller tree, recursion naturally handles traversal easily and efficiently.
//if the base condition root == NULL is missing The function will continue calling itself endlessly and may cause a stack overflow or program crash.
