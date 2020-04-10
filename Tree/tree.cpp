#include "tree.h"

adrRoot allocate(infotypeRoot x) {
    adrRoot R = new Node;
    R -> info = x;
    R -> left = NULL;
    R -> right = NULL;
    return R;
}

void insert(adrRoot &P, infotypeRoot Q) {
    if (P == NULL) P = allocate(Q);

    if (P -> left == NULL && Q < P -> info) {
        P -> left = allocate(Q);
    } else if (P -> right == NULL && Q > P -> info) {
        P -> right = allocate(Q);
    } else if (P -> left != NULL && Q < P -> info) {
        insert(P -> left, Q);
    } else if (P -> right != NULL && Q > P -> info) {
        insert(P -> right, Q);
    }
}

adrRoot searchRoot(adrRoot P, infotypeRoot x) {
    while (P != NULL && P -> info != x) {
        if (P -> info < x) {
            P = P -> right;
        } else {
            P = P -> left;
        }
    }
    return P;
}

bool fullBinaryTree(adrRoot T) {
    if (T == NULL) return 1;
    if (T -> left == NULL && T -> right == NULL) return 1;
    if (T -> left != NULL && T -> right != NULL) return (fullBinaryTree(T -> left) && fullBinaryTree(T -> right));
    return 0;
}

// bool completeBinaryTree(adrRoot T) {
//     //susah wkwkwkwk nanti baru dibuat lagi
// }

bool skewedBinaryTree(adrRoot T) {
    if (T -> right == NULL && T -> left == NULL) return 1;
    if (T -> right == NULL && T -> left != NULL) {
        return skewedBinaryTree(T -> left);
    } else if (T -> right != NULL && T -> left == NULL) {
        return skewedBinaryTree(T -> right);
    }
    return 0;
}

void inOrder(adrRoot P) {
    if (P == NULL) return;  //bisa diganti jadi...

    // if (P -> left == NULL)  //ini
    inOrder(P -> left);
    cout << P -> info << " ";
    // if (P -> right == NULL)  //ini
    inOrder(P -> right);
}       //print semua ini

void postOrder(adrRoot P) {
    if (P == NULL) return;

    // if (P -> left == NULL)  //ini
    postOrder(P -> left);
    // if (P -> right == NULL)  //ini
    inOrder(P -> right);
    cout << P -> info << " ";
}     //

void preOrder(adrRoot P) {
    if (P == NULL) return;

    cout << P -> info << " ";
    preOrder(P -> left);
    preOrder(P -> right);
}      //

void inOrderSucces(adrRoot P, adrRoot T) {
    if (P == T) P = P -> right;      //T adalah root awal, P adalah pencari root
    if (P -> left == NULL) {
        cout << P -> info;
    } else {
        inOrderSucces(P -> left, T);
    }
}

void inOrderPredes(adrRoot P, adrRoot T) {
    if (P == T) P = P -> left;      //T adalah root awal, P adalah pencari root
    if (P -> right == NULL) {
        cout << P -> info;
    } else {
        inOrderPredes(P -> right, T);
    }
}

// masih rusak

// void deleteRoot(adrRoot &P, infotypeRoot x) {
//     adrRoot Q = searchRoot(P, x);
//     if (Q != NULL) {
//         Q = P;
//         while (Q != NULL && Q -> left -> info != x && Q -> right -> info != x) {
//             if (Q -> info < x) {
//                 Q = Q -> right;
//             } else {
//                 Q = Q -> left;
//             }
//         }
//         if (searchRoot(P, x) == Q -> left && Q -> left -> left == NULL) {
//             Q -> left = Q -> left -> right;
//         } else if (searchRoot(P, x) == Q -> left && Q -> left -> left != NULL) {
//             Q -> info = Q -> right -> info;
//             Q -> right = NULL;
//         } else if (searchRoot(P, x) == Q -> right && Q -> left -> left == NULL) {
//             Q -> left = Q -> left -> right;
//         }
//     }
// }