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

void push(List &L, int x) {
    address p, p1 = L.head;
    p = L.head;
    if (p == NULL) {
        p = allocate(x);
        p -> next = L.head;
        L.head = p;
    } else {
        while (p != NULL && p -> data > x) {
            p1 = p;
            p = p -> next; 
        }
        if (p1 == p) {
            p = allocate(x);
            p -> next = L.head;
            L.head = p;
        } else {
            p = allocate(x);
            p -> next = p1 -> next;
            p1 -> next = p;
        }
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

    push(queue, 5);
    cout << "Push 5 = ";
    printData(queue);
    push(queue, 13);
    cout << "Push 13 = ";
    printData(queue);
    push(queue, 7);
    cout << "Push 7 = ";
    printData(queue);
    push(queue, 17);
    cout << "Push 17 = ";
    printData(queue);
    push(queue, 56);
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