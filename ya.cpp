#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct identitas {
    string nama;
    string no_hp;
    int no_kamar;
    string tanggalMasuk;

    identitas* next;
    identitas* prev;
};

void simpanKeFile(identitas* head, const string& file){
    ofstream berkas(file);
    if(!berkas.is_open()){
        cout << "Gagal membuka file untuk menyimpan data." << endl;
        return;
    }

    identitas* current = head;
    while(current != nullptr){
        berkas << current->nama << endl;
        berkas << current->no_hp << endl;
        berkas << current->no_kamar << endl;
        berkas << current->tanggalMasuk << endl;
        current = current->next;
    }

    berkas.close();
    cout << "Data berhasil disimpan ke file." << endl;
}

void tambahDataPenghuni(identitas*& head, identitas*& tail){
    identitas* newNode = new identitas;
    cin.ignore(); // Bersihkan newline sebelum getline
    cout << "Masukkan nama: "; 
    getline(cin, newNode->nama);
    cout << "Masukkan no hp: "; 
    getline(cin, newNode->no_hp);
    cout << "Masukkan no kamar: ";
    cin >> newNode->no_kamar;
    cin.ignore(); // Tambahkan ini agar getline berikutnya tidak lompat
    cout << "Masukkan tanggal masuk: ";
    getline(cin, newNode->tanggalMasuk);

    newNode->next = nullptr;
    newNode->prev = tail;

    if(tail != nullptr){
        tail->next = newNode;
    } else {
        head = newNode; // Node pertama
    }
    tail = newNode;
}


int main(){
    identitas* head = nullptr;
    identitas* tail = nullptr;

    string name, no_hp, tanggalMasuk, file = "data.txt";
    int no_kamar;
    char pilihan;

    //tampilan menu
    cout << "Pilihan menu: " << endl;
    cout << "1. Tambahkan data penghuni" << endl;
    cout << "2. Tampilkan data penghuni" << endl;
    cout << "3. Hapus data" << endl;
    cout << "4. Cari data penghuni" << endl;
    cout << "5. keluar" << endl;
    cout << "Pilih:" ; cin >> pilihan;
    switch(pilihan){
        case '1':
            cout << "Tambahkan data penghuni" << endl;
            tambahDataPenghuni(head, tail);
            simpanKeFile(head, file);
            break;
        case '2':
            cout << "Tampilkan data penghuni" << endl;
            break;
        case '3':
            cout << "Hapus data" << endl;
            break;
        case '4':
            cout << "Cari data penghuni" << endl;
            break;
        case '5':
            cout << "ya";
            break;
    }
    return 0;
}