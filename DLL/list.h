#include <bits/stdc++.h>

using namespace std;

typedef int infotype;
typedef struct elmlist *address;
struct elmlist {
    int info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

bool isEmpty(List L);
void createList(List &L);
void createNewElmt(infotype X, address &P);
void insertFirst(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void insertLast(List &L, address P);
void deleteFirst(List &L, address P);
void deleteAfter(List &L, address Prec, address P);
void deleteLast(List &L, address P);
void concat(List L1, List L2, List &L3);
double median(List L);
void PrintInfo(List L);
address findElm(List L, int x);
void reversePrint(List L);
