#include <bits/stdc++.h>

using namespace std;

typedef struct elmlist *address;
struct elmlist {
    int info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void insert_first(List &l, address p);
void insert_after(List &l, address p);
void delete_first(List &l, address p);
void delete_after(List &l, address p, address prec);
void insert_last(List &l, address p);
void delete_last(List &l, address p);