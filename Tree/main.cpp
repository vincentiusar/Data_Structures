#include "tree.h"

void cleared() {
    system("cls");
}

int main() {
    adrRoot mainRoot = NULL, P;
    cout << "Tipe data yang digunakan adalah int.\nsilahkan dicoba!";
    cout << "Press enter to continue . . .";
    cin.get();
    cleared();

    cout << "MOHON DIPERHATIKAN BAHWA INI ADALAH BINARY TREE\n";
    cout << "Press enter to continue . . .";
    cin.get();
    cleared();

    int n; cout << "masukan angka untuk Root parent : "; cin >> n;
    mainRoot = allocate(n);
    cleared();

    int x; cout << "Untuk membuat tree, masukkan berapa banyak elmt yang ingin dimasukkan : "; cin >> n;
    n++;
    while (n--) {
        cleared();
        cout << "Masukkan angkanya : "; cin >> x;
        insert(mainRoot, x);
    }

    while (true) {
        cleared();
        cout << "Mau diapain?\n1. search root\n2. cek full binary tree\n3. cek complete binary tree (belum bisa)\n4. cek skewed binary tree\n5. print tree\n6. inOrder successor BST\n7. inOrder predecessor BST\n8. Delete Root (masih rusak)\n9. sum of elmt tree\n0. Exit\nCHOOSE : ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Masukkan root yang ingin dicari : "; cin >> x;
            cout << "ada? "  << searchRoot(mainRoot, x);
            if (searchRoot(mainRoot, x) == NULL) cout << " GADA";
            break;
        case 2:
            cout << boolalpha << fullBinaryTree(mainRoot);
            break;
        case 3:
            //cout << completeBinaryTree(mainRoot);
            break;
        case 4: 
            cout << boolalpha << skewedBinaryTree(mainRoot);
            break;
        case 5:
            cout << "1. inOrder\n2. postOrder\n3. preOrder\nCHOOSE : "; cin >> x;
            if (x == 1) {
                inOrder(mainRoot);
            } else if (x == 2) {
                postOrder(mainRoot);
            } else if (x == 3) {
                preOrder(mainRoot);
            } else {
                cout << "Bukan pilihan, Odol";
            }
            
            break;
        case 6:
            inOrderSucces(mainRoot, mainRoot);
            break;
        case 7:
            inOrderPredes(mainRoot, mainRoot);
            break;
        case 8:
            //cout << "Masukkan root yang dicari : "; cin >> x;
            //deleteRoot(mainRoot, x);
            break;
        case 9:
            cout << countInfoNode(mainRoot) << endl;
            break;
        }
        cout << "Press enter to continue . . .";
        cin.get();
        cin.get();
        if (n == 0) break;
    }
}