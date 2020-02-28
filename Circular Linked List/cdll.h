#ifndef CDLL_H_INCLUDED
#define CDLL_H_INCLUDED

#include <iostream>

using namespace std;

typedef char infotype;
typedef struct elmlist *address;
struct elmlist {
    infotype info;
    address prev;
    address next;
};
struct List {
    address first;
};

bool isEmpty(List L);
void createList(List &L);
void createNewElmt(infotype X, address &P);
void insertFirst(List &L, address P);
void insertAfter(address Prec, address P);
void deleteFirst(List &L, address &P);
void deleteAfter(address Prec, address &P);
int countWord(char data[], List L);
address findElm(List L, infotype X);
void printInfo(List L);

#endif // CDLL_H_INCLUDED
