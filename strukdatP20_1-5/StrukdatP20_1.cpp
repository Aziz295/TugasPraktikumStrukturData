#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // untuk sleep (Linux/WSL)

using namespace std;

int main() {
    int data[10];
    srand(time(0));

    for (int i = 0; i < 10; i++)
        data[i] = rand() % 100;

    cout << "Data awal: ";
    for (int i = 0; i < 10; i++)
        cout << data[i] << " ";
    cout << endl;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            cout << "Bandingkan " << data[j]
                 << " dan " << data[j + 1] << endl;

            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                cout << "Tukar -> ";
                for (int k = 0; k < 10; k++)
                    cout << data[k] << " ";
                cout << endl;
            }
            sleep(1);
        }
        cout << "Iterasi ke-" << i + 1 << " selesai\n\n";
    }

    cout << "Hasil akhir: ";
    for (int i = 0; i < 10; i++)
        cout << data[i] << " ";

    return 0;
}

