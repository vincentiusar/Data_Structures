#include "create_list.h"

void createList(listed &l) {
    l.first = NULL;
}

address create_Elm(int x) {
    address p;
    p = new elmlist;
    p -> data = x;
    p -> next = NULL;
    return p;
}

void insert_first(listed &l, address p) {
    p -> next = l.first;
    l.first = p;
}

void insertLast(listed &l, address P) {
    address pointer; 
    pointer = l.first;
    while (pointer -> next != NULL) {
        pointer = pointer -> next;
    }
    pointer -> next = P;
}

void print_info(listed l) {
    address p;
    p = l.first;
    while (p != NULL) {
        if (p -> next != NULL) {            // if TO make output more beautifull and pretty
            cout << p -> data << " - ";
        } else {
            cout << p -> data;
        }
        p = p -> next;
    }
}

int search_info(listed &l, int x) {
    address p;
    p = l.first;
    while (p != NULL && p -> data != x) {
        p = p -> next;
    }
    if (p != NULL) {
        return p -> data;
    } else {
        return -1;
    }
}

address findElm(listed l, int x) {
    address P;
    P = l.first;
    while (P != NULL && P -> data != x) {
        P = P -> next;
    }
    return P;
}

void insert_after(listed &l, address p, address prev) {
    p -> next = prev -> next;
    prev -> next = p;
}

void delete_first(listed &l, address p) {
    p = l.first;
    l.first = p -> next;
    p -> next = NULL;
}

void delete_after(listed &l, address p, address prev) {
    p = prev -> next;
    prev -> next = p -> next;
    p -> next = NULL;
}

void deleteLast(listed &l, address &p) {
    address pointer;
    pointer = l.first;
    if (pointer -> next == NULL) {
        delete_first(l,p);
    } else {
        while ((pointer -> next -> next) != NULL) {
            pointer = pointer -> next;
        }
        p = pointer -> next;
        pointer -> next = NULL;
    }
}

void deallocate(address &p) {
    delete(p);
}

void insert_sorted(listed &l, int x) {
    address p, p1;
    p = l.first;
    if (p == NULL || p -> data > x) {
        insert_first(l, create_Elm(x));
    } else if (findElm(l, x) == NULL) {
        while (p != NULL && p -> data < x) {
            p1 = p;
            p = p -> next; 
        }
        insert_after(l, create_Elm(x), p1);
    }
}