#include <iostream>
using namespace std;

struct Mahasiswa {
    string nim, nama;
    float nilai;
    Mahasiswa* next;
};

Mahasiswa* head = NULL;

void insertData() {
    Mahasiswa* baru = new Mahasiswa;
    cout << "NIM   : "; cin >> baru->nim;
    cout << "Nama  : "; cin >> baru->nama;
    cout << "Nilai : "; cin >> baru->nilai;

    baru->next = head;
    head = baru;
}

void tampilNilai90() {
    Mahasiswa* bantu = head;
    bool ada = false;

    while (bantu != NULL) {
        if (bantu->nilai == 90) {
            cout << bantu->nim << " "
                 << bantu->nama << " "
                 << bantu->nilai << endl;
            ada = true;
        }
        bantu = bantu->next;
    }

    if (!ada)
        cout << "Tidak ada mahasiswa dengan nilai 90" << endl;
}

void tampilSemua() {
    Mahasiswa* bantu = head;

    if (bantu == NULL) {
        cout << "Data kosong" << endl;
        return;
    }

    while (bantu != NULL) {
        cout << bantu->nim << " "
             << bantu->nama << " "
             << bantu->nilai << endl;
        bantu = bantu->next;
    }
}

void hapusNIM(string target) {
    Mahasiswa* bantu = head;
    Mahasiswa* prev = NULL;

    while (bantu != NULL && bantu->nim != target) {
        prev = bantu;
        bantu = bantu->next;
    }

    if (bantu == NULL) {
        cout << "NIM tidak ditemukan" << endl;
        return;
    }

    if (prev == NULL)
        head = bantu->next;
    else
        prev->next = bantu->next;

    delete bantu;
    cout << "Data berhasil dihapus" << endl;
}

void rataRata() {
    Mahasiswa* bantu = head;
    float total = 0;
    int jumlah = 0;

    while (bantu != NULL) {
        total += bantu->nilai;
        jumlah++;
        bantu = bantu->next;
    }

    if (jumlah == 0)
        cout << "Data kosong" << endl;
    else
        cout << "Rata-rata nilai kelas: " << total / jumlah << endl;
}

int main() {
    int pilih;
    string nim;

    do {
        cout << "\nMENU\n";
        cout << "1. Insert Data\n";
        cout << "2. Tampil Nilai 90\n";
        cout << "3. Tampil Semua Data\n";
        cout << "4. Hapus Data (NIM)\n";
        cout << "5. Nilai Rata-rata\n";
        cout << "6. Exit\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: insertData(); break;
            case 2: tampilNilai90(); break;
            case 3: tampilSemua(); break;
            case 4:
                cout << "Masukkan NIM: ";
                cin >> nim;
                hapusNIM(nim);
                break;
            case 5: rataRata(); break;
        }
    } while (pilih != 6);

    return 0;
}

