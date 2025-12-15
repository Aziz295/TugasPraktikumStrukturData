#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int kiri = 0, kanan = n - 1, langkah = 0;

    while (kiri <= kanan) {
        langkah++;
        int mid = (kiri + kanan) / 2;

        cout << "Langkah " << langkah
             << ": cek index " << mid
             << " (nilai " << arr[mid] << ")\n";

        if (arr[mid] == target) {
            cout << "Jumlah langkah: " << langkah << endl;
            return mid;
        }
        else if (arr[mid] < target)
            kiri = mid + 1;
        else
            kanan = mid - 1;
    }
    cout << "Jumlah langkah: " << langkah << endl;
    return -1;
}

int main() {
    int data[15] = {3, 7, 10, 14, 18, 22, 27, 30, 35, 40, 45, 50, 55, 60, 65};
    int cari = 30;

    int hasil = binarySearch(data, 15, cari);

    if (hasil != -1)
        cout << "Data ditemukan di index " << hasil << endl;
    else
        cout << "Data tidak ditemukan\n";
}

