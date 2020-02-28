#include "list.h"

int main() {
    List L1, L2, L3;
    address P;

    createList(L1);
    cout << "Buat List L1 : \n";
    createNewElmt(10, P);
    insertFirst(L1, P);
    cout << "Insert first L1 : \n";
    PrintInfo(L1);
    createNewElmt(56, P);
    insertLast(L1, P);
    cout << "Insert last L1 : \n";
    PrintInfo(L1);
    createNewElmt(20, P);
    insertAfter(L1, findElm(L1, 10), P);
    cout << "Insert after 10 L1 : \n";
    PrintInfo(L1);
    createNewElmt(30, P);
    cout << "Insert after 99 L1 : \n";
    insertAfter(L1, findElm(L1, 99), P);
    PrintInfo(L1);
    cout << "karena tidak ada 99, maka tidak dimasukkan\n";
    createNewElmt(100, P);
    insertLast(L1, P);
    cout << "Insert last L1 : \n";
    PrintInfo(L1);
    deleteFirst(L1, P);
    cout << "Delete first L1 : \n";
    PrintInfo(L1);
    deleteLast(L1, P);
    cout << "Delete last L1 : \n";
    PrintInfo(L1);
    deleteAfter(L1, findElm(L1, 20), P);
    cout << "Delete after 20 L1 : \n";
    PrintInfo(L1);
    deleteLast(L1, P);
    cout << "Delete last L1 : \n";
    PrintInfo(L1);

    createList(L2);
    cout << "Create list L2 :\n";
    createNewElmt(67, P);
    insertFirst(L2, P);
    createNewElmt(53, P);
    insertFirst(L2, P);
    createNewElmt(40, P);
    insertFirst(L2, P);
    createNewElmt(27, P);
    insertFirst(L2, P);
    createNewElmt(13, P);
    insertFirst(L2, P);
    PrintInfo(L2);

    cout << "Median L2 : " << median(L2) << endl;
    deleteFirst(L2, P);
    cout << "Delete first L2 :\n";
    PrintInfo(L2);
    cout << "Median L2 : " << median(L2) << endl << endl;

    createNewElmt(10, P);
    insertFirst(L1, P);
    createNewElmt(56, P);
    insertLast(L1, P);
    createNewElmt(20, P);
    insertAfter(L1, findElm(L1, 10), P);
    createNewElmt(30, P);
    insertLast(L1, P);
    cout << "Berikut adalah L1 baru dan L2:\n";
    PrintInfo(L1);
    PrintInfo(L2);

    createList(L3);
    concat(L1, L2, L3);
    cout << "\nPenggabungan (concat) L1 dan L2 menjadi L3 :\n";
    PrintInfo(L3);
    cout << "\nMembalik L3 yang sudah diconcat :\n";
    reversePrint(L3);
    return 0;
}
