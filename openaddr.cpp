#include <iostream>
#include <string>
using namespace std;

#define MAX 10

struct Node {
    string name;
    long int mn;
    Node* next;

    Node(string name = "", long int mn = 0) {
        this->name = name;
        this->mn = mn;
        this->next = NULL;
    }
};

class Dictionary {
    Node* table[MAX];

public:
    Dictionary() {
        for (int i = 0; i < MAX; ++i)
            table[i] = NULL;
    }

    int hashfun(long int key) {
        return key % MAX;
    }

    void insert() {
        string name;
        long int mn;
        cout << "Enter name and phone number: ";
        cin >> name >> mn;

        int idx = hashfun(mn);
        Node* newNode = new Node(name, mn);

        // Insert at the beginning of the linked list at index
        newNode->next = table[idx];
        table[idx] = newNode;
    }

    void search() {
        long int mn;
        cout << "Enter phone number to search: ";
        cin >> mn;
        int idx = hashfun(mn);

        Node* temp = table[idx];
        while (temp) {
            if (temp->mn == mn) {
                cout << "Phone number found: " << temp->name << ", Index: " << idx << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Phone number not found.\n";
    }

    void del() {
        long int mn;
        cout << "Enter phone number to delete: ";
        cin >> mn;
        int idx = hashfun(mn);

        Node* temp = table[idx];
        Node* prev = NULL;

        while (temp) {
            if (temp->mn == mn) {
                if (prev == NULL) {
                    table[idx] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Phone number deleted.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Phone number not found.\n";
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < MAX; ++i) {
            cout << "Index " << i << ": ";
            Node* temp = table[i];
            while (temp) {
                cout << "[" << temp->name << ", " << temp->mn << "] -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    Dictionary d;
    int choice;
    char cont;

    do {
        cout << "\n1. Insert\n2. Search\n3. Display\n4. Delete\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: d.insert(); break;
        case 2: d.search(); break;
        case 3: d.display(); break;
        case 4: d.del(); break;
        case 5: exit(0);
        default: cout << "Invalid choice.\n";
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> cont;
    } while (cont == 'y');

    return 0;
}