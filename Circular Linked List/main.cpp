#include "cdll.h"

/*
    Nama    : Vincentius Arnold Fridolin
    NIM     : 1301190221
*/

int main()
{
    List L;
    address P, Pointer;
    createList(L);
    createNewElmt('a', P);
    insertFirst(L, P);
    printInfo(L);
    createNewElmt('t', P);
    insertFirst(L, P);
    printInfo(L);
    createNewElmt('t', P);
    insertAfter(findElm(L, 'a'), P);
    printInfo(L);
    createNewElmt('c', P);
    insertAfter(findElm(L, 't'), P);
    printInfo(L);
    createNewElmt('a', P);
    insertAfter(L.first -> prev, P);
    printInfo(L);
    createNewElmt('s', P);
    insertAfter(L.first -> prev, P);
    printInfo(L);
    createNewElmt('c', P);
    insertAfter(L.first -> prev, P);
    printInfo(L);
    createNewElmt('a', P);
    insertAfter(L.first -> prev, P);
    printInfo(L);
    cout << countWord("cat", L) << endl;
    deleteFirst(L, P);
    cout << "Delete first elm : ";
    printInfo(L);
    deleteAfter(findElm(L, 'a'), P);
    cout << "Delete after a : ";
    printInfo(L);
    return 0;
}
