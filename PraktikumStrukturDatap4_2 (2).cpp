#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;   // Kapasitas maksimal stack
    int S[MAX];           // Array stack
    int top = -1;         // Penanda posisi atas stack
    int data;

    cout << "=== Program PUSH dan POP Stack ===\n";
    cout << "Masukkan data (999 untuk berhenti):\n";

    // ======== PROSES PUSH ========
    while (true) {
        cout << "Input data: ";
        cin >> data;

        if (data == 999) {
            cout << "Input selesai (end of data)\n";
            break;
        }

        if (top < MAX - 1) {
            top++;
            S[top] = data;
            cout << "Data " << data << " dimasukkan ke stack (PUSH)\n";
        } else {
            cout << "Stack Penuh! Tidak bisa menambah data lagi.\n";
            break;
        }
    }

    // ======== PROSES POP ========
    cout << "\n=== Mengeluarkan isi stack (POP) ===\n";
    if (top < 0) {
        cout << "Stack Kosong!\n";
    } else {
        while (top >= 0) {
            cout << "Data " << S[top] << " dikeluarkan dari stack (POP)\n";
            top--;
        }
        cout << "Stack sekarang kosong.\n";
    }

    return 0;
}

