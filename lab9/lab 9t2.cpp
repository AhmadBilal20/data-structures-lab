#include <iostream>
using namespace std;

class node {
public:
    int songID;
    string songName;
    float duration;

    node* next;
    node* prev;

    node(int id, string name, float dur) {
        songID = id;
        songName = name;
        duration = dur;

        next = NULL;
        prev = NULL;
    }
};

class linklist {
private:
    node* head;
    node* tail;
    node* current;

public:
    linklist() {
        head = NULL;
        tail = NULL;
        current = NULL;
    }

    void addSongatend(int id, string name, float dur) {

        node* newSong = new node(id, name, dur);

        if (head == NULL) {
            head = tail = current = newSong;
        }
        else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }

        cout << "Song Added Successfully!\n";
    }

    void deleteSong(string name) {

        if (head == NULL) {
            cout << "Playlist is Empty.\n";
            return;
        }

        node* temp = head;

        while (temp != NULL && temp->songName != name) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Song Not Found.\n";
            return;
        }

        if (temp == head) {
            head = head->next;

            if (head != NULL)
                head->prev = NULL;
            else
                tail = NULL;
        }

        else if (temp == tail) {
            tail = tail->prev;
            tail->next = NULL;
        }

        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        if (current == temp) {
            current = head;
        }

        delete temp;

        cout << "Song Deleted Successfully"<<endl;
    }

    void playCurrent() {

        if (current == NULL) {
            cout << "No song available" << endl;
            return;
        }

        cout << "\nCurrently Playing:" << endl;

    }

    void playNext() {

        if (current == NULL) {
            cout << "Playlist is Empty.\n";
            return;
        }

        if (current->next != NULL) {
            current = current->next;
            playCurrent();
        }

        else {
            cout << "This is the Last Song.\n";
        }
    }

    void playPrevious() {

        if (current == NULL) {
            cout << "Playlist is Empty.\n";
            return;
        }

        if (current->prev != NULL) {
            current = current->prev;
            playCurrent();
        }

        else {
            cout << "This is the First Song.\n";
        }
    }

    void reversePlaylist() {

        if (head == NULL) {
            cout << "Playlist is Empty.\n";
            return;
        }

        node* temp = NULL;
        node* currentNode = head;

        while (currentNode != NULL) {

            temp = currentNode->prev;
            currentNode->prev = currentNode->next;
            currentNode->next = temp;

            currentNode = currentNode->prev;
        }

        temp = head;
        head = tail;
        tail = temp;

        current = head;

        cout << "Playlist Reversed Successfully" << endl;
    }

    void displayPlaylist() {

        if (head == NULL) {
            cout << "Playlist is Empty" << endl;
            return;
        }

        node* temp = head;

        cout << "===== PLAYLIST =====" << endl;

        while (temp != NULL) {

            cout << "Song ID: " << temp->songID << "\nName: " << temp->songName << "\nDuration: " << temp->duration << " mins" << endl;

            temp = temp->next;
        }

        cout << "====================\n";
    }
};

int main() {

    linklist p;

    p.addSongatend(101, "Nach Punjaban ", 4.2);
    p.addSongatend(102, "Ja to chad gai ta ma kera jena chad ta", 3.5);
    p.addSongatend(103, "Sadgi to hamari zara dakhiya", 4.8);

    p.displayPlaylist();

    p.playCurrent();
    p.playNext();
    p.playNext();
    p.playPrevious();

    p.deleteSong("Nach Punjaban");

    p.displayPlaylist();

    p.reversePlaylist();

    p.displayPlaylist();

    return 0;
}