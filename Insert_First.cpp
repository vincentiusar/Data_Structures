#include <iostream>

using namespace std;

typedef struct elmlist *address;

struct elmlist {
    int data;
    address next;
};

int main() {
    address head, now, pointer;
    now = new elmlist;
    head = now;
    pointer = now;
    cin >> now -> data;
    now = new elmlist;
    now -> next = pointer;
    cin >> now -> data;
    pointer = now;
    now = new elmlist;
    now -> next = pointer;
    cin >> now -> data;
    pointer = now;
    head -> next = NULL;
    cout << now -> data << " ";
    while (now -> next != NULL) {
        now = now -> next;
        cout << now -> data;
    }
}