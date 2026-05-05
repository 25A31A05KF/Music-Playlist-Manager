#include <iostream>
using namespace std;

struct Node {
    string song;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* current = NULL;

void addSong(string name) {
    Node* newNode = new Node;
    newNode->song = name;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        current = head;
        cout << "Song added as first song.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    cout << "Song added successfully.\n";
}

void displayPlaylist() {
    if (head == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "\n--- Playlist ---\n";
    while (temp != NULL) {
        cout << temp->song << endl;
        temp = temp->next;
    }
}

void nextSong() {
    if (current == NULL) {
        cout << "No song is playing.\n";
        return;
    }

    if (current->next == NULL) {
        cout << "You are at the last song.\n";
        return;
    }

    current = current->next;
    cout << "Now playing: " << current->song << endl;
}

void previousSong() {
    if (current == NULL) {
        cout << "No song is playing.\n";
        return;
    }

    if (current->prev == NULL) {
        cout << "This is the first song.\n";
        return;
    }

    current = current->prev;
    cout << "Now playing: " << current->song << endl;
}

void showCurrent() {
    if (current == NULL) {
        cout << "No song is playing.\n";
    } else {
        cout << "Currently playing: " << current->song << endl;
    }
}

void deleteSong(string name) {
    if (head == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }

    Node* temp = head;

    while (temp != NULL && temp->song != name) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Song not found.\n";
        return;
    }

    if (temp == head) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    }
    else {
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
    }

    if (current == temp) {
        current = temp->next;
    }

    delete temp;
    cout << "Song deleted.\n";
}

void searchSong(string name) {
    Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->song == name) {
            cout << "Song found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Song not found.\n";
}

int main() {
    int choice;
    string name;

    while (true) {
        cout << "\n===== MUSIC PLAYLIST MENU =====\n";
        cout << "1. Add Song\n";
        cout << "2. Display Playlist\n";
        cout << "3. Next Song\n";
        cout << "4. Previous Song\n";
        cout << "5. Delete Song\n";
        cout << "6. Search Song\n";
        cout << "7. Current Song\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter song name: ";
            cin >> name;
            addSong(name);
            break;

        case 2:
            displayPlaylist();
            break;

        case 3:
            nextSong();
            break;

        case 4:
            previousSong();
            break;

        case 5:
            cout << "Enter song to delete: ";
            cin >> name;
            deleteSong(name);
            break;

        case 6:
            cout << "Enter song to search: ";
            cin >> name;
            searchSong(name);
            break;

        case 7:
            showCurrent();
            break;

        case 8:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}