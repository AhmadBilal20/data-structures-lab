//#include<iostream>
//using namespace std;
//class node {
//public:
//	int data;
//	node* next;
//	node* prev;
//	node(int d) {
//		this->data = d;
//		this->next = NULL;
//		this->prev = NULL;
//	}
//};
//class doublylinklist {
//	node* head;
//	node* tail;
//public:
//	doublylinklist() {
//		this->head = NULL;
//		this->tail = NULL;
//	}
//	void insertatstart(int value) {
//		node* newnode = new node(value);
//		if (head == NULL) {
//			head = newnode;
//			tail = newnode;
//			return;
//		}
//	
//		newnode->next = head;
//		head->prev = newnode;
//		head = newnode;
//
//	}
//	void insertatend(int value) {
//		node* newnode = new node(value);
//		if (head == NULL)
//		{
//			head = newnode;
//			tail = newnode;
//			return;
//		}
//		tail->next = newnode;
//		newnode->prev = tail;
//		tail = newnode;
//	}
//	void insertatpostion(int p, int d) {
//		if (p == 1)
//		{
//			insertatstart(d);
//			return;
//
//		}
//		node* temp = head;
//		int cnt = 1;
//		while (cnt < p - 1&&temp!=NULL) {
//			temp = temp->next;
//			cnt++;
//		}
//		if (temp == NULL || temp->next == NULL) {
//			insertatend(d);
//			return;
//		}
//		node* insertnewnode = new node(d);
//		insertnewnode->next = temp->next;
//		temp->next->prev = insertnewnode;
//		temp->next = insertnewnode;
//		insertnewnode->prev = temp;
//	}
//
//	void deleteByValue(int value) {
//
//		if (head == NULL) {
//			cout << "List is empty\n";
//			return;
//		}
//		node* temp = head;
//		while (temp != NULL && temp->data != value) {
//			temp = temp->next;
//		}
//
//		if (temp == NULL) {
//			cout << "Value not found\n";
//			return;
//		}
//
//		if (temp == head) {
//			head = head->next;
//
//			if (head != NULL)
//				head->prev = NULL;
//			else
//				tail = NULL;
//
//			delete temp;
//			return;
//		}
//
//		if (temp == tail) {
//			tail = tail->prev;
//			tail->next = NULL;
//
//			delete temp;
//			return;
//		}
//
//		temp->prev->next = temp->next;
//		temp->next->prev = temp->prev;
//
//		delete temp;
//	}
//
//	void printForward() {
//		node* temp = head;
//		cout << "Forward : ";
//		while (temp != NULL) {
//			cout << temp->data << " ";
//			temp = temp->next;
//		}
//
//		cout << endl;
//	}
//	void printReverse() {
//		node* temp = tail;
//
//		cout << "Reverse: ";
//
//		while (temp != NULL) {
//			cout << temp->data << " ";
//			temp = temp->prev;
//		}
//
//		cout << endl;
//	}
//};
//
//
//int main() {
//
//	doublylinklist l;
//
//	l.insertatend(10);
//	l.insertatend(20);
//	l.insertatend(30);
//
//	l.insertatpostion(2, 15);
//
//	l.printForward();
//	l.printReverse();
//
//	cout << "\nAfter deleting 10:\n";
//	l.deleteByValue(10);
//
//	l.printForward();
//	l.printReverse();
//
//	cout << "\nAfter deleting 40:\n";
//	l.deleteByValue(40);
//
//	l.printForward();
//	l.printReverse();
//
//	cout << "\nAfter deleting 20:\n";
//	l.deleteByValue(20);
//
//	l.printForward();
//	l.printReverse();
//
//	return 0;
//
//};