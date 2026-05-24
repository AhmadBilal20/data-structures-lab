#include <iostream>
#include <queue>
using namespace std;

// Node class
class Node
{
public:

    int data;
    Node* left;
    Node* right;
};

// Naya node create karne ka function
Node* createNode(int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// BFS / Level Order Traversal function
void BFS(Node* root)
{
    // Agar tree empty ho
    if (root == NULL)
    {
        cout << "Tree is empty";
        return;
    }

    // Queue create karna
    queue<Node*> q;

    // Sab se pehle root node queue mein insert karo
    q.push(root);

    // Jab tak queue empty na ho loop chalega
    while (!q.empty())
    {
        // Front node ko lena
        Node* temp = q.front();

        // Front node ko queue se remove karna
        q.pop();

        // Node ka data print karna
        cout << temp->data << " ";

        // Agar left child exist karta ho to queue mein add karo
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }

        // Agar right child exist karta ho to queue mein add karo
        if (temp->right != NULL)
        {
            q.push(temp->right);
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

    // BFS traversal call
    cout << "BFS / Level-Order Traversal: ";
    BFS(root);

    return 0;
}
//queue is used in BFS.
//BFS print nodes level by level.Because BFS visits nodes in the order they are added to the queue.
//the first node inserted into the queue is root node(40).
//After printing 40 the queue contains 20 60.