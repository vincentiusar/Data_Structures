#include <bits/stdc++.h>

using namespace std;

vector<int> nilai;

void print(vector<int> nilai) {
    for (auto i = nilai.begin(); i < nilai.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

int main() {
    nilai.push_back(1);
    nilai.push_back(4);
    nilai.push_back(12);
    cout << "print biasa : ";
    print(nilai);
    cout << "apakah isi vektor kosong? " << boolalpha << nilai.empty() << endl;
    cout << "ukuran vektor : " << nilai.size() << endl << "nilai terdepan vektor : " << nilai.front() << endl << "nilai terakhir vektor : "<< nilai.back() << endl << nilai.max_size();
    cout << endl;
    cout << "revese print : ";
    for (auto i = nilai.rbegin(); i < nilai.rend(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    nilai.insert(nilai.begin() + 2, 3);
    print(nilai);
    nilai.push_back(3);
    print(nilai);
    nilai.erase(nilai.begin() + 3);
    print(nilai);
    for (auto i = nilai.begin(); i < nilai.end(); i++) {
        if (*i == 3) {
            cout << *i << " ";
        }
    }
    nilai.clear();
    print(nilai);
}