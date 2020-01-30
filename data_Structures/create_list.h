#include <iostream>

using namespace std;

typedef struct elmlist *address;

struct elmlist {
    int data;
    address next;
};

struct listed {
    address first;
};

address create_Elm(int x);
void insert_last(listed &i, address p);
void insert_first(listed &l, address p);
void print_info(listed l);
int search_info(listed &l, int x);
void insert_after(listed &l, address p, address prev);
void delete_first(listed &l, address p);
void delete_after(listed &l, address p, address prev);