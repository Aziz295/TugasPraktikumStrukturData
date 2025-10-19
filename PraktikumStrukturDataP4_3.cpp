#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;   
    int S[MAX];           
    int top = -1;         
    int data;

    cout << "=== PUSH Data ke Stack ===\n";

    while (true) {
        if (top >= MAX - 1) {
            cout << "Stack Penuh! Tidak bisa menambah data lagi.\n";
            break;
        }

        cout << "Masukkan data: ";
        cin >> data;

        top++;
        S[top] = data;  // proses PUSH
        cout << "Data " << data << " berhasil dimasukkan ke stack.\n";
    }

    return 0;
}

