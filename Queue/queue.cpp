#include <iostream>
using namespace std;

typedef struct elmlist *address;
struct elmlist {
    int data;
    address next;
};

struct List {
    address head;
    address tail;
};

void create(List &L) {
    L.head = NULL;
    L.tail = NULL;
}

address allocate(int x) {
    address P = new elmlist;
    P -> data = x;
    P -> next = NULL;
    return P;
}

void push(List &L, address P) {
    if (L.head == NULL) {
        P -> next = L.head;
        L.head = P;
        L.tail = P;
    } else {
        L.tail -> next = P;
        L.tail = P;
    }
}

void pop(List &L) {
    address P = L.head;
    L.head = P -> next;
    P -> next = NULL;
    delete P;
}

void top(List L) {
    cout << "head : " << L.head -> data << endl;
}

void printData(List L) {
    address P = L.head;
    while (P != NULL) {
        cout << P -> data << "  ";
        P = P -> next;
    }
    cout << endl;
}

int size(List L) {
    address P = L.head;
    int sum = 0;
    while (P != NULL) {
        sum++;
        P = P -> next;
    }
    return sum;
}

int main() {
    List queue;
    address P;
    create(queue);

    push(queue, allocate(5));
    cout << "Push 5 = ";
    printData(queue);
    push(queue, allocate(13));
    cout << "Push 13 = ";
    printData(queue);
    push(queue, allocate(7));
    cout << "Push 7 = ";
    printData(queue);
    push(queue, allocate(17));
    cout << "Push 17 = ";
    printData(queue);
    push(queue, allocate(56));
    cout << "Push 56 = ";
    printData(queue);
    
    cout << endl << "size stack = " << size(queue) << endl << endl;
    top(queue);

    pop(queue);
    cout << "Pop = ";
    printData(queue);
    pop(queue);
    cout << "Pop = ";
    printData(queue);
}