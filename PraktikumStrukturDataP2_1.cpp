#include <iostream>
#include <string> 
#include <vector>
#include <limits> // Untuk std::numeric_limits

// Mendefinisikan kelas Siswa
class Siswa {
public:
    std::string nama;
    std::string kelas;
    int nilai;

    Siswa(std::string nama, std::string kelas, int nilai) {
        this->nama = nama;
        this->kelas = kelas;
        this->nilai = nilai;
    }

    void tampilkanInfo() const {
        std::cout << "Nama: " << nama << ", Kelas: " << kelas
                  << ", Nilai: " << nilai << std::endl;
    }
};

// Fungsi untuk menambahkan siswa baru
void tambahSiswa(std::vector<Siswa>& daftarSiswa) {
    std::string nama, kelas;
    int nilai;

    std::cout << "\n--- Tambah Siswa Baru ---" << std::endl;
    std::cout << "Masukkan nama: ";
    std::getline(std::cin >> std::ws, nama);
    std::cout << "Masukkan kelas: ";
    std::getline(std::cin, kelas);
    std::cout << "Masukkan nilai: ";
    std::cin >> nilai;

    daftarSiswa.push_back(Siswa(nama, kelas, nilai));
    std::cout << "Siswa berhasil ditambahkan!" << std::endl;
}

// Fungsi untuk menampilkan semua siswa
void tampilkanSemuaSiswa(const std::vector<Siswa>& daftarSiswa) {
    std::cout << "\n--- Daftar Siswa ---" << std::endl;
    if (daftarSiswa.empty()) {
        std::cout << "Daftar siswa kosong." << std::endl;
    } else {
        for (const auto& siswa : daftarSiswa) {
            siswa.tampilkanInfo();
        }
    }
}

// Fungsi untuk mencari siswa berdasarkan nama
void cariSiswa(const std::vector<Siswa>& daftarSiswa) {
    std::string namaCari;
    bool ditemukan = false;

    std::cout << "\n--- Cari Siswa ---" << std::endl;
    std::cout << "Masukkan nama siswa yang dicari: ";
    std::getline(std::cin >> std::ws, namaCari);

    for (const auto& siswa : daftarSiswa) {
        if (siswa.nama == namaCari) {
            siswa.tampilkanInfo();
            ditemukan = true;
        }
    }

    if (!ditemukan) {
        std::cout << "Siswa dengan nama '" << namaCari << "' tidak ditemukan." << std::endl;
    }
}

int main() {
    std::vector<Siswa> daftarSiswa;
    int pilihan;

    do {
        std::cout << "\n=== MENU ===" << std::endl;
        std::cout << "1. Tambah Siswa" << std::endl;
        std::cout << "2. Tampilkan Semua Siswa" << std::endl;
        std::cout << "3. Cari Siswa" << std::endl;
        std::cout << "4. Keluar" << std::endl;
        std::cout << "Masukkan pilihan Anda: ";
        std::cin >> pilihan;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (pilihan) {
            case 1:
                tambahSiswa(daftarSiswa);
                break;
            case 2:
                tampilkanSemuaSiswa(daftarSiswa);
                break;
            case 3:
                cariSiswa(daftarSiswa);
                break;
            case 4:
                std::cout << "Program selesai." << std::endl;
                break;
            default:
                std::cout << "Pilihan tidak valid, silakan coba lagi." << std::endl;
                break;
        }
    } while (pilihan != 4);

    return 0;
}

