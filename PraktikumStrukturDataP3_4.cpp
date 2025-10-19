#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Buku {
    string judul;
    string penulis;
    int jumlah;
};

void tampilkanInformasiBuku(const Buku &buku) {
    cout << "\nJudul  : " << buku.judul << endl;
    cout << "Penulis: " << buku.penulis << endl;
    cout << "Jumlah : " << buku.jumlah << endl;
}

void tambahBuku(vector<Buku> &perpustakaan) {
    Buku bukuBaru;
    cout << "\nMasukkan judul buku   : ";
    getline(cin, bukuBaru.judul);
    cout << "Masukkan nama penulis : ";
    getline(cin, bukuBaru.penulis);
    cout << "Masukkan jumlah buku  : ";
    cin >> bukuBaru.jumlah;
    cin.ignore();

    perpustakaan.push_back(bukuBaru);
    cout << "\nBuku berhasil ditambahkan!\n";
}

void tampilkanBukuPenulis(const vector<Buku> &perpustakaan) {
    string penulis;
    cout << "\nMasukkan nama penulis: ";
    getline(cin, penulis);
    bool ditemukan = false;

    for (const auto &b : perpustakaan) {
        if (b.penulis == penulis) {
            tampilkanInformasiBuku(b);
            ditemukan = true;
        }
    }

    if (!ditemukan)
        cout << "\nTidak ada buku dari penulis tersebut.\n";
}

void tampilkanJumlahJudul(const vector<Buku> &perpustakaan) {
    string judul;
    cout << "\nMasukkan judul buku: ";
    getline(cin, judul);
    bool ditemukan = false;

    for (const auto &b : perpustakaan) {
        if (b.judul == judul) {
            cout << "\nJumlah buku \"" << b.judul << "\": " << b.jumlah << endl;
            ditemukan = true;
        }
    }

    if (!ditemukan)
        cout << "\nBuku dengan judul tersebut tidak ditemukan.\n";
}

void tampilkanTotalBuku(const vector<Buku> &perpustakaan) {
    int total = 0;
    for (const auto &b : perpustakaan)
        total += b.jumlah;

    cout << "\nJumlah total semua buku di perpustakaan: " << total << endl;
}

void terbitkanBuku(vector<Buku> &perpustakaan) {
    string judul;
    cout << "\nMasukkan judul buku yang ingin diterbitkan: ";
    getline(cin, judul);
    bool ditemukan = false;

    for (auto &b : perpustakaan) {
        if (b.judul == judul) {
            if (b.jumlah > 0) {
                b.jumlah--;
                cout << "\nBuku \"" << b.judul << "\" berhasil diterbitkan. Jumlah tersisa: " << b.jumlah << endl;
            } else {
                cout << "\nStok buku \"" << b.judul << "\" sudah habis!\n";
            }
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan)
        cout << "\nBuku dengan judul tersebut tidak ditemukan.\n";
}

int main() {
    vector<Buku> perpustakaan;
    int pilihan;

    do {
        cout << "\n===== MENU PERPUSTAKAAN =====\n";
        cout << "1. Tampilkan informasi buku\n";
        cout << "2. Tambahkan buku baru\n";
        cout << "3. Tampilkan semua buku penulis tertentu\n";
        cout << "4. Tampilkan jumlah buku dengan judul tertentu\n";
        cout << "5. Tampilkan jumlah total buku\n";
        cout << "6. Terbitkan buku\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: {
                if (perpustakaan.empty()) {
                    cout << "\nBelum ada buku dalam perpustakaan.\n";
                } else {
                    cout << "\n=== Daftar Buku ===\n";
                    for (const auto &b : perpustakaan)
                        tampilkanInformasiBuku(b);
                }
                break;
            }
            case 2: tambahBuku(perpustakaan); break;
            case 3: tampilkanBukuPenulis(perpustakaan); break;
            case 4: tampilkanJumlahJudul(perpustakaan); break;
            case 5: tampilkanTotalBuku(perpustakaan); break;
            case 6: terbitkanBuku(perpustakaan); break;
            case 0: cout << "\nTerima kasih telah menggunakan sistem perpustakaan!\n"; break;
            default: cout << "\nPilihan tidak valid, coba lagi.\n";
        }

    } while (pilihan != 0);

    return 0;
}

