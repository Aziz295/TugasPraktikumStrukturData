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
    Mahasiswa* prev;
};

Mahasiswa* head = NULL;

void animasi() {
    this_thread::sleep_for(chrono::milliseconds(600));
}

void insertData() {
    Mahasiswa* baru = new Mahasiswa;
    cin.ignore();
    cout << "Nama   : "; getline(cin, baru->nama);
    cout << "NIM    : "; getline(cin, baru->nim);
    cout << "Gender : "; getline(cin, baru->gender);
    cout << "Nilai  : "; cin >> baru->nilai;

    cout << "\nMenambahkan data..." << endl;
    animasi();

    if (head == NULL) {
        head = baru;
        baru->next = head;
        baru->prev = head;
    } else {
        Mahasiswa* last = head->prev;
        baru->next = head;
        baru->prev = last;
        last->next = baru;
        head->prev = baru;
    }

    cout << "Data berhasil ditambahkan" << endl;
}

void hapusData() {
    if (head == NULL) {
        cout << "Data kosong" << endl;
        return;
    }

    string target;
    cin.ignore();
    cout << "Masukkan NIM yang dihapus: "; getline(cin, target);

    cout << "\nMenghapus data..." << endl;
    animasi();

    Mahasiswa* bantu = head;
    do {
        if (bantu->nim == target) {
            if (bantu->next == bantu) {
                delete bantu;
                head = NULL;
            } else {
                bantu->prev->next = bantu->next;
                bantu->next->prev = bantu->prev;
                if (bantu == head)
                    head = bantu->next;
                delete bantu;
            }
            cout << "Data berhasil dihapus" << endl;
            return;
        }
        bantu = bantu->next;
    } while (bantu != head);

    cout << "NIM tidak ditemukan" << endl;
}

void cetakData() {
    if (head == NULL) {
        cout << "Data kosong" << endl;
        return;
    }

    cout << "\nIsi Circular Doubly Linked List:" << endl;
    animasi();

    Mahasiswa* bantu = head;
    int no = 1;
    do {
        cout << "\nData ke-" << no++ << endl;
        cout << "Nama   : " << bantu->nama << endl;
        cout << "NIM    : " << bantu->nim << endl;
        cout << "Gender : " << bantu->gender << endl;
        cout << "Nilai  : " << bantu->nilai << endl;
        cout << "-----------------------" << endl;
        animasi();
        bantu = bantu->next;
    } while (bantu != head);
}

int main() {
    int pilih;
    do {
        cout << "\nCIRCULAR DOUBLY LINKED LIST" << endl;
        cout << "===========================" << endl;
        cout << "1. INSERT DATA" << endl;
        cout << "2. HAPUS DATA" << endl;
        cout << "3. CETAK DATA" << endl;
        cout << "4. EXIT" << endl;
        cout << "Pilihan (1 - 4): ";
        cin >> pilih;

        switch (pilih) {
            case 1: insertData(); break;
            case 2: hapusData(); break;
            case 3: cetakData(); break;
            case 4: cout << "Keluar dari program" << endl; break;
            default: cout << "Pilihan tidak valid" << endl;
        }
    } while (pilih != 4);

    return 0;
}
