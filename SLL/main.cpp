#include "list.h"

// to run this program, please make sure the header file and the file.cpp is in
// one folder/project and correctly compile it.

int main() {
    int n;    
    listed l;
    address p, now;
    cout << "Masukkan berapa angka yang ingin di input dalam list : ";
    cin >> n;

    int x;
    createList(l);
    for (int i = 0 ; i < n ; i++) {
        cin >> x; 
        now = create_Elm(x);
        insert_first(l, now);
    }
    print_info(l);

    cout << endl << "Masukkan angka yang ingin dicari dalam linked list : ";
    cin >> x;
    if (findElm(l, x) == NULL) {
        cout << "data not found";
    } else if (x == findElm(l, x) -> data) {
        cout << "data found! " << findElm(l, x) -> data;
    }
    cout << endl << endl;

    cout << endl << "Masukkan data yang ingin dimmasukkan : ";
    cin >> x;
    cout << "setelah data apa angka tersebut mau dimasukkan : ";
    cin >> n;

    insert_after(l, create_Elm(x), findElm(l, n));
    print_info(l);

    cout << "\n--------------\n\nSekarang kita akan mengeluarkan data paling pertama dari linked list\n";
    cout << "Linked List menjadi seperti ini : ";
    delete_first(l, now); 
    print_info(l);

    cout << "\n\nMasukkan angka di mana angka setelahnya mau di delete : ";
    cin >> x;
    
    delete_after(l, create_Elm(x), findElm(l, x));
    print_info(l);

    createList(l);
    cout << "\n\nsekarang keadaan list kosong\n\nkita akan melakukan insert data ke list dan langsung mengurutkan data list\n\n";
    for (int i = 0; i < 10; i++) {
        cout << "\n\nmasukkan input 1 angka : ";
        cin >> x;
        insert_sorted(l, x);
        cout << "berikut adalah hasil listnya (tidak ada data yang ter-duplicate):\n";
        print_info(l);
    }
    
    listed l2;
    cout << "\n\nsekarang keadaan list kosong\nkita akan merging 2 list menjadi 1 list yang terurut accesending";
    createList(l2);
    for (int i = 0; i < 5; i++) {
        cout << "\nmasukkan 1 angka : ";
        cin >> x;
        insert_sorted(l, x);
    }

    cout << "Semua fungsi sudah ada di dalam create_list.cpp . Silahkan\njika ingin melihat beberapa fungsi lain yang\ntidak di execute, lakukan pemanggilan sendiri\n\n--terima kasih--";
}