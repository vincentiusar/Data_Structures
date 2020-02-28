#include "list.h"

void insert_first(List &l, address p) {
    if (l.first != NULL) {
        p -> next = l.first;
        l.first -> prev = p;
        l.first = p;
    } else {
        l.first = p;
        l.last = p;
    }
}

void insert_after(List &l, address p, address prec) {
    p -> next = prec -> next;
    p -> prev = prec;
    prec -> next -> prev = p;
    prec -> next = p;
}

void delete_first(List &l, address p) {
    if (l.first != NULL) {
        p = l.first;
        l.first = p -> next;
        p -> next = NULL;
        l.first -> prev = NULL;
    } else if (l.first == l.last) {
        p = l.first;
        l.first = NULL;
        l.last = NULL;
    }
}

void delete_after(List &l, address p, address prec) {
    p = prec -> next;
    prec -> next = p -> next;
    p -> next -> prev = prec;
    p -> next = NULL;
    p -> prev = NULL;
}

void insert_last(List &l, address p) {
    if (l.first != NULL) {
        p -> prev = l.last;
        l.last -> next = p;
        l.last = p;
    } else {
        l.first = p;
        l.last = p;
    }
}

void delete_last(List &l, address p) {
    if (l.last != NULL) {
        p = l.last;
        l.last = p -> prev;
        p -> prev = NULL;
        l.last -> next = NULL;
    } else if (l.first == l.last) {
        p = l.first;
        l.first = NULL;
        l.last = NULL;
    }
}