#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

// Struktur data Mahasiswa (Node)
struct Mahasiswa {
    string nama;
    string nim;
    string gender;
    float nilai;
    Mahasiswa* next;
};

// Pointer TOP stack (tanpa head)
Mahasiswa* top = NULL;

// Fungsi delay untuk animasi sederhana
void animasi() {
    this_thread::sleep_for(chrono::milliseconds(600));
}

// PUSH / INSERT DATA
void insertData() {
    Mahasiswa* baru = new Mahasiswa;
    cin.ignore();
    cout << "Masukkan Nama   : "; getline(cin, baru->nama);
    cout << "Masukkan NIM    : "; getline(cin, baru->nim);
    cout << "Masukkan Gender : "; getline(cin, baru->gender);
    cout << "Masukkan Nilai  : "; cin >> baru->nilai;

    cout << "\nMenambahkan data ke Stack..." << endl;
    animasi();

    // Stack tanpa head: node baru langsung menunjuk TOP
    baru->next = top;
    top = baru;

    cout << "Data berhasil di-PUSH!" << endl;
}

// POP / HAPUS DATA
void hapusData() {
    if (top == NULL) {
        cout << "Stack kosong! Tidak ada data yang dihapus." << endl;
        return;
    }

    cout << "Menghapus data teratas (POP)..." << endl;
    animasi();

    Mahasiswa* hapus = top;
    top = top->next;

    cout << "Data yang dihapus:" << endl;
    cout << "Nama   : " << hapus->nama << endl;
    cout << "NIM    : " << hapus->nim << endl;
    cout << "Gender : " << hapus->gender << endl;
    cout << "Nilai  : " << hapus->nilai << endl;

    delete hapus;
}

// CETAK DATA STACK
void cetakData() {
    if (top == NULL) {
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "\nIsi Stack (TOP ke BOTTOM):" << endl;
    animasi();

    Mahasiswa* bantu = top;
    int no = 1;
    while (bantu != NULL) {
        cout << "\nData ke-" << no++ << endl;
        cout << "Nama   : " << bantu->nama << endl;
        cout << "NIM    : " << bantu->nim << endl;
        cout << "Gender : " << bantu->gender << endl;
        cout << "Nilai  : " << bantu->nilai << endl;
        cout << "------------------------" << endl;
        animasi();
        bantu = bantu->next;
    }
}

int main() {
    int pilihan;
    do {
        cout << "\n===== MENU STACK MAHASISWA (TANPA HEAD) =====" << endl;
        cout << "1. INSERT DATA" << endl;
        cout << "2. HAPUS DATA" << endl;
        cout << "3. CETAK DATA" << endl;
        cout << "4. EXIT" << endl;
        cout << "Pilih menu : "; cin >> pilihan;

        switch (pilihan) {
        case 1:
            insertData();
            break;
        case 2:
            hapusData();
            break;
        case 3:
            cetakData();
            break;
        case 4:
            cout << "Keluar dari program..." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}
