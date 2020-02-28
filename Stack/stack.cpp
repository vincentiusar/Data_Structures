#include <iostream>
using namespace std;

typedef struct elmlist *address;
struct elmlist {
    int data;
    address next;
};

struct List {
    address head;
};

void create(List &L) {
    L.head = NULL;
}

address allocate(int x) {
    address P = new elmlist;
    P -> data = x;
    P -> next = NULL;
    return P;
}

void push(List &L, address P) {
    P -> next = L.head;
    L.head = P;
}

void pop(List &L) {
    address P = L.head;
    L.head = P -> next;
    P -> next = NULL;
    delete P;
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

void top(List L) {
    cout << "head : " << L.head -> data << endl;
}

int main() {
    List stack;
    address P;
    create(stack);

    push(stack, allocate(5));
    cout << "Push 5 = ";
    printData(stack);
    push(stack, allocate(13));
    cout << "Push 13 = ";
    printData(stack);
    push(stack, allocate(7));
    cout << "Push 7 = ";
    printData(stack);
    push(stack, allocate(17));
    cout << "Push 17 = ";
    printData(stack);
    push(stack, allocate(56));
    cout << "Push 56 = ";
    printData(stack);
    
    cout << endl << "size stack = " << size(stack) << endl << endl;
    top(stack);

    pop(stack);
    cout << "Pop = ";
    printData(stack);
    pop(stack);
    cout << "Pop = ";
    printData(stack);
}