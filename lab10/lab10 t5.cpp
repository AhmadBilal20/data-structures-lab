#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

void printList(Node* head)
{
    if (head == NULL)
    {
        cout << "NULL" << endl;
        return;
    }

    cout << head->data << " -> ";
    printList(head->next);
}

void insertAtBeginning(Node*& head, int value)
{
    Node* newNode = new Node(value);

    newNode->next = head;
    head = newNode;

    cout << "After inserting at beginning: ";
    printList(head);
}

void insertAtEnd(Node*& head, int value)
{
    if (head == NULL)
    {
        head = new Node(value);

        cout << "After inserting at end: ";
        printList(head);
        return;
    }

    if (head->next == NULL)
    {
        head->next = new Node(value);

        cout << "After inserting at end: ";
        printList(head);
        return;
    }

    insertAtEnd(head->next, value);
}

void insertAtPosition(Node*& head, int value, int position)
{
    if (position <= 0)
    {
        cout << "Invalid Position" << endl;
        return;
    }

    if (position == 1)
    {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        cout << "After inserting at position: ";
        printList(head);
        return;
    }

    if (head == NULL)
    {
        cout << "Position out of range" << endl;
        return;
    }

    insertAtPosition(head->next, value, position - 1);
}

void deleteByValue(Node*& head, int value)
{
    if (head == NULL)
    {
        cout << "Value not found" << endl;
        return;
    }

    if (head->data == value)
    {
        Node* temp = head;

        head = head->next;
        delete temp;

        cout << "After deleting value: ";
        printList(head);
        return;
    }

    deleteByValue(head->next, value);
}

void deleteAtPosition(Node*& head, int position)
{
    if (head == NULL || position <= 0)
    {
        cout << "Invalid Position" << endl;
        return;
    }

    if (position == 1)
    {
        Node* temp = head;

        head = head->next;
        delete temp;

        cout << "After deleting at position: ";
        printList(head);
        return;
    }

    deleteAtPosition(head->next, position - 1);
}

int searchValue(Node* head, int value, int position = 1)
{
    if (head == NULL)
    {
        return -1;
    }

    if (head->data == value)
    {
        return position;
    }

    return searchValue(head->next, value, position + 1);
}

int main()
{
    Node* head = NULL;

    insertAtBeginning(head, 10);
    insertAtBeginning(head, 5);

    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    insertAtPosition(head, 15, 3);

    deleteByValue(head, 20);

    deleteAtPosition(head, 2);

    cout << "Final List: ";
    printList(head);

    int pos = searchValue(head, 15);

    if (pos != -1)
    {
        cout << "Value found at position: " << pos << endl;
    }
    else
    {
        cout << "Value not found" << endl;
    }

    return 0;
}