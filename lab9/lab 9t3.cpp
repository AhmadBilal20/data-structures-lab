#include<iostream>
using namespace std;

class node {
public:

	int playerid;
	int score;
	node* next;
	node* prev;

	node(int id, int s) {
		this->playerid = id;
		this->score = s;
		this->next = NULL;
		this->prev = NULL;
	}
};

class circularlinklist {
private:
	node* tail;
	node* current;

public:

	circularlinklist() {
		this->tail = NULL;
		this->current = NULL;
	}

	void addplayer(int id, int score) {

		node* newnode = new node(id, score);

		if (tail == NULL) {
			tail = newnode;
			tail->next = tail;
			tail->prev = tail;
			current = tail;
		}
		else {

			newnode->next = tail->next;
			newnode->prev = tail;

			tail->next->prev = newnode;
			tail->next = newnode;

			tail = newnode;
		}

		cout << "Player " << id << " added" << endl;
	}

	void removeplayer(int id) {

		if (tail == NULL) {
			cout << "List is empty" << endl;
			return;
		}

		node* temp = tail->next;

		do {

			if (temp->playerid == id) {

				if (temp == tail && temp->next == tail) {
					tail = NULL;
					current = NULL;
				}
				else {

					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;

					if (temp == tail) {
						tail = temp->prev;
					}

					if (temp == current) {
						current = temp->next;
					}
				}

				delete temp;

				cout << "Player " << id << " removed" << endl;
				return;
			}

			temp = temp->next;

		} while (temp != tail->next);

		cout << "Player not found" << endl;
	}

	void nextturn() {

		if (current == NULL) {
			cout << "No players" << endl;
			return;
		}

		current = current->next;

		cout << "Turn of Player "
			<< current->playerid << endl;
	}

	void skipplayer() {

		if (current == NULL) {
			cout << "No players" << endl;
			return;
		}

		cout << "Player "
			<< current->next->playerid
			<< " skipped" << endl;

		current = current->next->next;

		cout << "Now Turn of Player "
			<< current->playerid << endl;
	}

	void display() {

		if (tail == NULL) {
			cout << "List is empty" << endl;
			return;
		}

		node* temp = tail->next;

		do {

			cout << "Player ID: "
				<< temp->playerid
				<< " Score: "
				<< temp->score << endl;

			temp = temp->next;

		} while (temp != tail->next);
	}

	void winner() {

		if (tail != NULL && tail->next == tail) {

			cout << "Winner is Player "
				<< tail->playerid << endl;
		}
	}
};

int main() {

	circularlinklist game;

	game.addplayer(1, 100);
	game.addplayer(2, 200);
	game.addplayer(3, 300);
	game.addplayer(4, 400);

	cout << endl;

	game.display();

	cout << endl;

	game.nextturn();
	game.nextturn();

	cout << endl;

	game.skipplayer();

	cout << endl;

	game.removeplayer(2);
	game.removeplayer(3);
	game.removeplayer(4);

	cout << endl;

	game.display();

	cout << endl;

	game.winner();

	return 0;
}