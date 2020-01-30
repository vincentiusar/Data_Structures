#include <iostream>

using namespace std;

typedef struct elmlist *address;

struct elmlist {
    int data;
    address next;
};

int main() {
    address first, p1, now;
    now = new elmlist;
    first = now;
    cin >> now -> data;
    p1 = now;
    while (now -> data != 9) {
        now = new elmlist;
        p1 -> next = now;
        cin >> now -> data;
        p1 = now;
    }
    now -> next = NULL;
    p1 = first;
    cout << p1 -> data << " ";
    while (p1 -> next != NULL) {
        p1 = p1 -> next;
        cout << p1 -> data << " ";
    } 
}