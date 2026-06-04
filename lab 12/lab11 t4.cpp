#include <iostream>
#include <string>
using namespace std;

class BSTNode
{
public:
    int isbn;
    string title;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int i, string t)
    {
        isbn = i;
        title = t;
        left = NULL;
        right = NULL;
    }
};

class ListNode
{
public:
    int isbn;
    string title;
    ListNode* next;

    ListNode(int i, string t)
    {
        isbn = i;
        title = t;
        next = NULL;
    }
};

BSTNode* insertBST(BSTNode* root, int isbn, string title)
{
    if (root == NULL)
        return new BSTNode(isbn, title);

    if (isbn < root->isbn)
        root->left = insertBST(root->left, isbn, title);
    else
        root->right = insertBST(root->right, isbn, title);

    return root;
}

void convertToList(BSTNode* root, ListNode*& head, ListNode*& tail)
{
    if (root == NULL)
        return;

    convertToList(root->left, head, tail);

    ListNode* newNode = new ListNode(root->isbn, root->title);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }

    convertToList(root->right, head, tail);
}

void printList(ListNode* head)
{
    while (head != NULL)
    {
        cout << "ISBN: " << head->isbn
            << "  Title: " << head->title << endl;
        head = head->next;
    }
}

int main()
{
    BSTNode* root = NULL;

    root = insertBST(root, 1050, "Data Structures");
    root = insertBST(root, 1020, "Programming Fundamentals");
    root = insertBST(root, 1080, "Database Systems");
    root = insertBST(root, 1010, "Computer Networks");
    root = insertBST(root, 1040, "Operating Systems");
    root = insertBST(root, 1070, "Artificial Intelligence");
    root = insertBST(root, 1100, "Software Engineering");

    ListNode* head = NULL;
    ListNode* tail = NULL;

    convertToList(root, head, tail);

    cout << "Library Catalog Sorted by ISBN\n\n";
    printList(head);

    return 0;
}