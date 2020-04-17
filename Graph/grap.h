#include <bits/stdc++.h>

using namespace std;

typedef string infotypeNode;
typedef string infotypeEdge;
typedef struct elmtNode *adrVertek;
typedef struct elmtEdge *adrEdge;

struct elmtEdge {
    infotypeEdge info;
    adrEdge nextEdge;
};

struct elmtNode {
    infotypeNode info;
    adrEdge firstEdge;
    adrVertek nextNode;
};

struct Graph {
    adrVertek Start;
};

void createGraph(Graph &G);
adrVertek allocateNode(infotypeNode st);
adrEdge allocateEdge(infotypeEdge st);
void addNewNode(Graph &G, adrVertek P);
adrVertek findNode(Graph G, infotypeNode st);
adrEdge findEdge(adrVertek P, infotypeEdge st);
void insertLastEdge(adrVertek &P, adrEdge Q);
void connecting(Graph &G, infotypeNode st1, infotypeEdge st2);
void deleteEdge(adrVertek P, adrEdge Q);
void deleteFirstEdge(adrVertek &P, adrEdge &Q);
void deleteAfterEdge(adrVertek &P, adrEdge Prec, adrEdge &Q);
void deleteLastEdge(adrVertek &P, adrEdge &Q);
void disconnecting(Graph &G, infotypeEdge st1, infotypeEdge st2);
void deleteNode(Graph &G, infotypeNode st);
bool hasLoop(adrVertek P);
bool hasMultiEdge(adrVertek P);
bool isSimpleGraph(Graph G);
void showNeighbor(Graph G);