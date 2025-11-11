#include <iostream>
#include <string>
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
Mahasiswa* tail = NULL;

Mahasiswa* buatNode(string nama, string nim, string gender, float nilai) {
    Mahasiswa* nodeBaru = new Mahasiswa;
    nodeBaru->nama = nama;
    nodeBaru->nim = nim;
    nodeBaru->gender = gender;
    nodeBaru->nilai = nilai;
    nodeBaru->next = NULL;
    nodeBaru->prev = NULL;
    return nodeBaru;
}

void insertData() {
    string nama, nim, gender;
    float nilai;
    cout << "\nMasukkan NIM     : ";
    cin >> nim;
    cout << "Masukkan Nama    : ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan Gender  : ";
    cin >> gender;
    cout << "Masukkan Nilai   : ";
    cin >> nilai;

    Mahasiswa* baru = buatNode(nama, nim, gender, nilai);

    if (head == NULL) {
        head = tail = baru;
    } else if (nim < head->nim) {
        baru->next = head;
        head->prev = baru;
        head = baru;
    } else {
        Mahasiswa* temp = head;
        while (temp->next != NULL && temp->next->nim < nim)
            temp = temp->next;

        baru->next = temp->next;
        baru->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = baru;
        else
            tail = baru;

        temp->next = baru;
    }
    cout << "Data berhasil ditambahkan!\n";
}

void hapusData() {
    if (head == NULL) {
        cout << "Linked list kosong!\n";
        return;
    }

    string nimHapus;
    cout << "Masukkan NIM yang akan dihapus: ";
    cin >> nimHapus;

    Mahasiswa* temp = head;
    while (temp != NULL && temp->nim != nimHapus)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Data dengan NIM tersebut tidak ditemukan!\n";
        return;
    }

    if (temp == head)
        head = head->next;
    if (temp == tail)
        tail = tail->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
    cout << "Data berhasil dihapus!\n";
}

void cetakData() {
    if (head == NULL) {
        cout << "Linked list kosong!\n";
        return;
    }

    Mahasiswa* temp = head;
    cout << "\nDaftar Mahasiswa:\n";
    cout << "-----------------------------------------\n";
    while (temp != NULL) {
        cout << "NIM    : " << temp->nim << endl;
        cout << "Nama   : " << temp->nama << endl;
        cout << "Gender : " << temp->gender << endl;
        cout << "Nilai  : " << temp->nilai << endl;
        cout << "-----------------------------------------\n";
        temp = temp->next;
    }
}

int main() {
    int pilihan;

    do {
        cout << "\n===============================\n";
        cout << "LIN. DOUBLY LINKED LIST\n";
        cout << "===============================\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "Pilihan (1-4): ";
        cin >> pilihan;

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
            cout << "Keluar dari program...\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}

