#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;
};

void printList(Node* head) {
  
    if (head == NULL) {
        return;
    }

    cout << head->data << " ";

    printList(head->next);
}

int main() {
    

    Node* head = new Node{ 10, NULL};
    head->next = new Node{ 20, NULL };
    head->next->next = new Node{ 30, NULL };
    head->next->next->next = new Node{ 40, NULL };

    cout << "Linked List: ";
    printList(head);

    return 0;
}