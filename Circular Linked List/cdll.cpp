#include "cdll.h"

/*
    Nama    : Vincentius Arnold Fridolin
    NIM     : 1301190221
*/

bool isEmpty(List L) {
    if (L.first == NULL) {
        return true;
    } else {
        return false;
    }
}

void createList(List &L) {
    L.first = NULL;
}

void createNewElmt(infotype X, address &P) {
    P = new elmlist;
    P -> info = X;
    P -> next = NULL;
    P -> prev = NULL;
}

void insertFirst(List &L, address P) {
    if (L.first == NULL) {
        P -> next = P;
        P -> prev = P;
        L.first = P;
    } else {
        L.first -> prev -> next = P;
        L.first -> prev = P;
        P -> next = L.first;
        P -> prev = L.first;
        L.first = P;
    }
}

/*
    Nama    : Vincentius Arnold Fridolin
    NIM     : 1301190221
*/

void insertAfter(address Prec, address P) {
    P -> next = Prec -> next;
    P -> prev = Prec;
    Prec -> next -> prev = P;
    Prec -> next = P;
}

void deleteFirst(List &L, address &P) {
    if (L.first -> next == NULL) {
        P = L.first;
        P -> next = NULL;
        P -> prev = NULL;
        L.first = NULL;
    } else {
        P = L.first;
        L.first = P -> next;
        L.first -> prev = P -> prev;
        P -> prev -> next = L.first;
        P -> next = NULL;
        P -> prev = NULL;
    }
}

void deleteAfter(address Prec, address &P) {
    P = Prec -> next;
    Prec -> next = P -> next;
    P -> next -> prev = Prec;
    P -> next = NULL;
    P -> prev = NULL;
}

int countWord(char data[], List L) {
    int jumlah = 0;
    address P = L.first;
    do {
        int i = 0;
        address Q = P;
        while (data[i] != NULL) {
            if (Q -> info != data[i]) {
                break;
            } else if (Q -> info == data[i]) {
                Q = Q -> next;
                i++;
            }
        }
        if (data[i] == NULL) {
            jumlah++;
        }
        P = P -> next;
    } while (P != L.first);
    return jumlah;
}

/*
    Nama    : Vincentius Arnold Fridolin
    NIM     : 1301190221
*/

address findElm(List L, infotype X) {
    address P = L.first;
    if (P -> info == X) {
        return P;
    } else {
        do {
            P = P -> next;
        } while (P != L.first && P -> info != X);
    }
    return P;
}

void printInfo(List L) {
    address P = L.first;
    do {
        cout << P -> info << " ";
        P = P -> next;
    } while (P != L.first);
    cout << endl;
}
