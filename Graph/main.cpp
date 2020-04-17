#include "grap.h"

void cleared() {
    system("cls");
}

int main() {
    Graph G;
    adrVertek P;
    adrEdge Q;
    string st1, st2;

    cout << "PEMBERITAHUAN! isi Node adalah String. Disarankan hanya menggunakan (A, B, C, dll)" << endl;
    cout << "Press enter to continue . . ."; cin.get(); cleared();

    int n = 0; cout << "Masukkan jumlah Node : "; cin >> n;

    createGraph(G);
    for (int i = 0; i < n; i++) {
        cout << "masukkan Node (" << i + 1 << ") : "; cin >> st1; 
        addNewNode(G, allocateNode(st1));
    }
    cout << "Node sebagai berikut : " << endl; showNeighbor(G);
    cout << endl << endl << "press enter to continue . . .";
    cin.get();
    cin.get();
    cleared();

    cout << "masukkan berapa kali anda ingin menghubungakan Node antar Node : "; cin >> n;
    for (int i = 0; i < n; i++) {
        cleared();
        cout << "masukkan pasangan node (A, B) : "; cin >> st1 >> st2;
        while (findNode(G, st1) == NULL || findNode(G, st2) == NULL) {
            cout << "MASUKKAN TIDAK VALID karena Node tidak ada. \nmasukkan pasangan node (A, B) : "; cin >> st1 >> st2;
        }
        connecting(G, st1, st2);
    }
    cout << "Node sebagai berikut : " << endl; showNeighbor(G);
	cout << "apakah " << G.Start -> info << " punya loop? " << hasLoop(G.Start) << " Multi Edge? " << hasMultiEdge(G.Start);
    cout << endl << endl << "press enter to continue . . .";
    cin.get();
    cin.get();
    cleared();

    cout << "masukkan berapa kali anda ingin memutus antar node (input constraint = x < " << n << ") : "; cin >> n;
    for (int i = 0; i < n; i++) {
        cleared();
        cout << "masukkan pasangan node (A, B) : "; cin >> st1 >> st2;
        while (findNode(G, st1) == NULL || findNode(G, st2) == NULL) {
            cout << "MASUKKAN TIDAK VALID karena Node tidak ada. \nmasukkan pasangan node (A, B) : "; cin >> st1 >> st2;
        }
        disconnecting(G, st1, st2);
    }
    cout << "Node sebagai berikut : " << endl; showNeighbor(G);
    cout << endl << endl << "End of Program . . .";
    cin.get();
    cin.get();
    cleared();
}
