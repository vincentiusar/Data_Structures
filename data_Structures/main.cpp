#include "create_list.h"

// to run this program, please make sure the header file and the file.cpp is in
// one folder/project and correctly compile it.

int main() {
    int n;    
    listed l;
    address p, now;
    cout << "Masukkan berapa angka yang ingin di input dalam list : ";
    cin >> n;

    int x;
    cin >> x;
    p = create_Elm(x);
    l.first = p;

    for (int i = 0 ; i < n - 1; i++) {
        cin >> x; 
        now = create_Elm(x);
        // p -> next = now;     // Insert last
        // p = now;             // insert_last
        insert_first(l, now);
    }
    print_info(l);

    cout << endl << "Masukkan angka yang ingin dicari dalam linked list : ";
    cin >> x;
    if (search_info(l, x) != -1) {
        cout << search_info(l, x) << " Data found";
    } else {
        cout << "No Data Found!\n";
    }


    cout << endl << "Masukkan data yang ingin dimmasukkan : ";
    cin >> x;
    cout << "setelah data apa angka tersebut mau dimasukkan : ";
    cin >> n;
    
    // Do searching address
    address pointer;
    pointer = l.first;
    while (pointer != NULL && pointer -> data != n) {
        pointer = pointer -> next;
    }
    // If data found, Pointer is pointing to data before x

    insert_after(l, create_Elm(x), pointer);
    print_info(l);

    cout << "\n\nSekarang kita akan mengeluarkan data paling pertama dari linked list\n";
    cout << "Linked List menjadi seperti ini : ";
    delete_first(l, now); 
    print_info(l);

    cout << "\n\nMasukkan angka di mana angka setelahnya mau di delete : ";
    cin >> x;
    
    pointer = l.first;
    while (pointer != NULL && pointer -> data != x) {
        pointer = pointer -> next;
    }

    delete_after(l, create_Elm(x), pointer);
    print_info(l);
}