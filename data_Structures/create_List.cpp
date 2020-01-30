#include "create_list.h"

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

void insert_last(listed &l, address p) {
    address p1;
    p1 -> next = p;
    p1 = p;
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