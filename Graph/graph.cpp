#include "grap.h"

void createGraph(Graph &G) {
    G.Start = NULL;
}

adrVertek allocateNode(infotypeNode st) {
    adrVertek P = new elmtNode;
    P -> info = st;
    P -> nextNode = NULL;
    P -> firstEdge = NULL;
    return P;
}

adrEdge allocateEdge(infotypeEdge st) {
    adrEdge P = new elmtEdge;
    P -> info = st;
    P -> nextEdge = NULL;
    return P;
}

void addNewNode(Graph &G, adrVertek P) {
    adrVertek Q = G.Start;
    if (Q == NULL) {
        G.Start = P;
    } else {
        while (Q -> nextNode != NULL) {
            Q = Q -> nextNode;
        }
        Q -> nextNode = P;
    }
}

adrVertek findNode(Graph G, infotypeNode st) {
    adrVertek P = G.Start;
    while (P != NULL && P -> info != st) {
        P = P -> nextNode;
    }
    return P;
}

adrEdge findEdge(adrVertek P, infotypeEdge st) {
    adrEdge Q = P -> firstEdge;
    while (Q != NULL && Q -> info != st) {
        Q = Q -> nextEdge;
    }
    return Q;
}

void insertLastEdge(adrVertek &P, adrEdge Q) {
    adrEdge R = P -> firstEdge;
    if (R == NULL) {
        P -> firstEdge = Q;
    } else {
        while (R -> nextEdge != NULL) {
            R = R -> nextEdge;
        }
        R -> nextEdge = Q;
    }
}

void connecting(Graph &G, infotypeNode st1, infotypeEdge st2) {
    adrVertek P = findNode(G, st1), Q = findNode(G, st2);
    if (P != NULL && Q != NULL) {
        insertLastEdge(P, allocateEdge(st2));
        insertLastEdge(Q, allocateEdge(st1));
    }
}

void deleteEdge(adrVertek P, adrEdge Q) {
    if (Q != NULL) {
        if (Q == P -> firstEdge) {
            deleteFirstEdge(P, Q);
        } else if (Q -> nextEdge == NULL) {
            deleteLastEdge(P, Q);
        } else if (Q -> nextEdge != NULL) {
            adrEdge Prec = P -> firstEdge;
            while (P != NULL && Prec -> nextEdge != Q) {
                Prec = Prec -> nextEdge;
            }
            deleteAfterEdge(P, Prec, Q);
        }
        delete Q;
    }
}

void deleteFirstEdge(adrVertek &P, adrEdge &Q) {
    Q = P -> firstEdge;
    P -> firstEdge = Q -> nextEdge;
    Q -> nextEdge = NULL;
}

void deleteAfterEdge(adrVertek &P, adrEdge Prec, adrEdge &Q) {
    Q = Prec -> nextEdge;
    Prec -> nextEdge = Q -> nextEdge;
    Q -> nextEdge = NULL;
}

void deleteLastEdge(adrVertek &P, adrEdge &Q) {
    adrEdge temp = P -> firstEdge;
    while (temp -> nextEdge -> nextEdge != NULL) {
        temp = temp -> nextEdge;
    }
    Q = temp -> nextEdge;
    temp -> nextEdge = NULL;
}

void disconnecting(Graph &G, infotypeEdge st1, infotypeEdge st2) {
    adrVertek P = findNode(G, st1), Q = findNode(G, st2);
    if (P != NULL && Q != NULL) {
        deleteEdge(P, findEdge(P, st2));
        deleteEdge(Q, findEdge(Q, st1));
    }
}

void deleteNode(Graph &G, infotypeNode st) {
    adrVertek P = findNode(G, st);
    if (P != NULL) {
        if (P == G.Start) {
            G.Start = P -> nextNode;
            P -> nextNode = NULL;
        } else if (P -> nextNode != NULL) {
            adrVertek Prec = G.Start;
            while (P != NULL && Prec -> nextNode != P) {
                Prec = Prec -> nextNode;
            }
            P = Prec -> nextNode;
            Prec -> nextNode = P -> nextNode;
            P -> nextNode = NULL;
        } else if (P -> nextNode == NULL) {
            adrVertek Q = G.Start;
            while (Q -> nextNode -> nextNode != NULL) {
                Q = Q -> nextNode;
            }
            P = Q -> nextNode;
            Q -> nextNode = NULL;
        }
        for (adrVertek i = G.Start; i != NULL; i = i -> nextNode) {
            deleteEdge(i, findEdge(i, P -> info));
        }
        delete P;
    }
}


bool hasLoop(adrVertek P) {
    adrEdge Q = P -> firstEdge;
    while (Q != NULL) {
        if (Q -> info == P -> info) {
            return 1;
        }
        Q = Q -> nextEdge;
    }
    return 0;
}

bool hasMultiEdge(adrVertek P) {
    adrEdge Q = P -> firstEdge;
    while (Q != NULL) {
        adrEdge R = Q -> nextEdge;
        while (R != NULL) {
            if (Q -> info == P -> info) {
                return 1;
            }
            R = R -> nextEdge;
        }
        Q = Q -> nextEdge;
    }
    return 0;
}

bool isSimpleGraph(Graph G) {
    bool flag = 1;
    for (adrVertek P = G.Start; P != NULL; P = P -> nextNode) {
        if (hasMultiEdge(P) || hasLoop(P)) {
            flag = 0;
        }
    }
    return flag;
}


void showNeighbor(Graph G) {
    for (adrVertek P = G.Start; P != NULL; P = P -> nextNode) {
        cout << P -> info << " ||";
        for (adrEdge Q = P -> firstEdge; Q != NULL; Q = Q -> nextEdge) {
            cout << " -> " << Q -> info;
        }
        cout << endl;
    }
}