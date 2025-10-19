#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;   // kapasitas maksimal stack
    int S[MAX];           // array stack
    int top = -1;         // penanda posisi atas stack
    int data;

    cout << "=== Program Stack (PUSH dan POP) ===\n";
    cout << "Masukkan data (999 untuk berhenti):\n";

    while (true) {
        cout << "Input data: ";
        cin >> data;

        // kondisi berhenti
        if (data == 999) {
            cout << "Proses selesai.\n";
            break;
        }

        // jika data >= 60 ? PUSH
        if (data >= 60) {
            if (top < MAX - 1) {
                top++;
                S[top] = data;
                cout << "Data " << data << " disimpan ke stack (PUSH).\n";
            } else {
                cout << "Stack Penuh!\n";
                break;
            }
        }

        // jika data < 60 ? POP
        else {
            if (top >= 0) {
                cout << "Data " << S[top] << " diambil dari stack (POP).\n";
                top--;
            } else {
                cout << "Stack Kosong!\n";
                break;
            }
        }
    }

    cout << "\n=== Isi Stack Akhir ===\n";
    if (top < 0)
        cout << "(Stack kosong)\n";
    else {
        for (int i = top; i >= 0; i--) {
            cout << S[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

