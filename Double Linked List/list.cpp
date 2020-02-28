#include "list.h"

bool isEmpty(List L) {
    if (L.first == NULL) {
        return true;
    } else {
        return false;
    }
}

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

void createNewElmt(infotype X, address &P) {
    P = new elmlist;
    P -> info = X;
    P -> next = NULL;
    P -> prev = NULL;
}

void insertFirst(List &L, address P) {
    if (!isEmpty(L)) {
        P -> next = L.first;
        L.first -> prev = P;
        L.first = P;
    } else {
        L.last = P;
        L.first = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (isEmpty(L)) {
        insertFirst(L, P);
    } else if (L.first != L.last && Prec != NULL) {
        P -> next = Prec -> next;
        P -> prev = Prec;
        Prec -> next -> prev = P;
        Prec -> next = P;
    } else if (Prec != NULL) {
        insertLast(L, P);
    }
}

void insertLast(List &L, address P) {
    if (isEmpty(L)) {
        insertFirst(L, P);
    } else {
        P -> prev = L.last;
        L.last -> next = P;
        L.last = P;
    }
}

void deleteFirst(List &L, address P) {
    if (L.first -> next == NULL) {
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        P = L.first;
        L.first = P -> next;
        P -> next = NULL;
        L.first -> prev = NULL;
    }
}

void deleteAfter(List &L, address Prec, address P) {
    if (L.first == L.last && Prec != NULL) {
        deleteFirst(L, P);
    } else if (Prec -> next != L.last && Prec != NULL) {
        P = Prec -> next;
        Prec -> next = P -> next;
        P -> next -> prev = Prec;
        P -> next = NULL;
        P -> prev = NULL;
    } else if (Prec != NULL) {
        deleteLast(L, P);
    }
}

void deleteLast(List &L, address P) {
    if (L.first != L.last) {
        P = L.last;
        L.last = P -> prev;
        P -> prev = NULL;
        L.last -> next = NULL;
    } else {
        deleteFirst(L, P);
    }
}
void concat(List L1, List L2, List &L3) {
    L1.last -> next = L2.first;
    L2.first -> prev = L1.last;
    L1.last = NULL;
    L3.first = L1.first;
    L3.last = L2.last;
}

double median(List L) {
    address P = L.first;
    address Q = L.last;
    while (P != Q && P -> next != Q) {
        P = P -> next;
        Q = Q -> prev;
    }
    if (P == Q) {
        return P -> info;
    } else {
        return double(P -> info + Q -> info) / 2;
    }
}

void PrintInfo(List L) {
    address P = L.first;
    if (isEmpty(L)) {
        cout << "list kosong" << endl;
    } else {
        while (P != NULL) {
            cout << P -> info << " ";
            P = P -> next;
        }
    }
    cout << endl;
}

address findElm(List L, int x) {
    address P = L.first;
    while (P != NULL && P -> info != x) {
        P = P -> next;
    }
    return P;
}

void reversePrint(List L) {
    address P = L.last;
    if (isEmpty(L)) {
        cout << "list kosong" << endl;
    } else {
        while (P != NULL) {
            cout << P -> info << " ";
            P = P -> prev;
        }
    }
    cout << endl;
}
