#include <bits/stdc++.h>

using namespace std;

typedef int infotypeRoot;
typedef struct Node *adrRoot;

struct Node {
    infotypeRoot info;
    adrRoot left;
    adrRoot right;
};

// binary tree!

adrRoot allocate(infotypeRoot x);
void insert(adrRoot &P, infotypeRoot Q);
adrRoot searchRoot(adrRoot P, infotypeRoot x);
bool fullBinaryTree(adrRoot T);
// bool completeBinaryTree(adrRoot T);
bool skewedBinaryTree(adrRoot T);
void inOrder(adrRoot P);       //print semua ini
void postOrder(adrRoot P);     //
void preOrder(adrRoot P);      //
void inOrderSucces(adrRoot P, adrRoot T);
void inOrderPredes(adrRoot P, adrRoot T);
int countInfoNode(adrRoot P);
//void deleteRoot(adrRoot &P, infotypeRoot x);
//void BFS(adrRoot P, );
//void DFS(adrRoot P, );