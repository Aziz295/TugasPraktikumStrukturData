#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    string gender;
    float nilai;
    Mahasiswa* next;
};

Mahasiswa* top = NULL;

void delay() {
    this_thread::sleep_for(chrono::milliseconds(700));
}

void insertData() {
    Mahasiswa* baru = new Mahasiswa;
    cin.ignore();
    cout << "Masukkan Nama   : "; getline(cin, baru->nama);
    cout << "Masukkan NIM    : "; getline(cin, baru->nim);
    cout << "Masukkan Gender : "; getline(cin, baru->gender);
    cout << "Masukkan Nilai  : "; cin >> baru->nilai;

    cout << "\nMenambahkan data ke stack..." << endl;
    delay();

    baru->next = top;
    top = baru;

    cout << "Data berhasil di-push ke stack!" << endl;
}

void hapusData() {
    if (top == NULL) {
        cout << "Stack kosong! Tidak ada data yang bisa dihapus." << endl;
        return;
    }

    cout << "Menghapus data teratas (POP)..." << endl;
    delay();

    Mahasiswa* hapus = top;
    top = top->next;

    cout << "Data yang dihapus:" << endl;
    cout << "Nama   : " << hapus->nama << endl;
    cout << "NIM    : " << hapus->nim << endl;
    cout << "Gender : " << hapus->gender << endl;
    cout << "Nilai  : " << hapus->nilai << endl;

    delete hapus;
}

void cetakData() {
    if (top == NULL) {
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "\nMenampilkan isi stack (TOP ke BOTTOM):" << endl;
    delay();

    Mahasiswa* bantu = top;
    int i = 1;
    while (bantu != NULL) {
        cout << "\nData ke-" << i++ << endl;
        cout << "Nama   : " << bantu->nama << endl;
        cout << "NIM    : " << bantu->nim << endl;
        cout << "Gender : " << bantu->gender << endl;
        cout << "Nilai  : " << bantu->nilai << endl;
        cout << "--------------------------" << endl;
        delay();
        bantu = bantu->next;
    }
}

int main() {
    int pilih;
    do {
        cout << "\n===== MENU STACK MAHASISWA =====" << endl;
        cout << "1. INSERT DATA" << endl;
        cout << "2. HAPUS DATA" << endl;
        cout << "3. CETAK DATA" << endl;
        cout << "4. EXIT" << endl;
        cout << "Pilih menu : "; cin >> pilih;

        switch (pilih) {
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
    } while (pilih != 4);

    return 0;
}
