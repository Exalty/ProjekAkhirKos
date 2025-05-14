#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct identitas {
    string nama;
    string no_hp;
    string no_kamar;
    string tanggalMasuk;
    identitas* next;
    identitas* prev;
};

// void simpanFile(identitas* head){
//     ofstream file("data.txt");
//     identitas* bantu = head;

//     while(bantu != nullptr){
//         file << bantu->nama << endl;
//         file << bantu->no_hp << endl;
//         file << bantu->no_kamar << endl;
//         file << bantu->tanggalMasuk << endl;
//         bantu = bantu->next;
//     }
//     file.close();
// }

void tambahPenghuni(identitas*& head, identitas*& tail, string nama, string no_hp, string no_kamar, string tanggalMasuk) {
    identitas* baru = new identitas;

    baru->nama = nama;
    baru->no_hp = no_hp;
    baru->no_kamar = no_kamar;
    baru->tanggalMasuk = tanggalMasuk;
    baru->next = nullptr;
    baru->prev = tail;

    if(head == nullptr){
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

int main(){
    char pilihan;
    cout << '|' << setfill('=') << setw(55) << right << '|' << endl;
    cout << '|' << setfill(' ') << setw(33) << right << " KOS SAHABAT " << setw(22) << right << '|' << endl;
    cout << '|' << setfill('=') << setw(55) << right << '|' << endl;
    cout << '|' << setfill(' ') << setw(30) << left << "1.Tambah data" << '|' << endl;

    cout << "Piliihan: ";
    cin >> pilihan;

    switch(pilihan){
        case '1':

    }
}