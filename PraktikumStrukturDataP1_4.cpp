#include <iostream>
#include <cmath> // untuk sqrt dan pow
using namespace std;

int main() {
    float x1, y1, x2, y2;

    cout << "Masukkan koordinat titik A (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Masukkan koordinat titik B (x2 y2): ";
    cin >> x2 >> y2;

    float jarak = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    cout << "Jarak antara A dan B = " << jarak << endl;

    return 0;
}

