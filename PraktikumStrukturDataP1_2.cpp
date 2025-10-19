#include <iostream>
using namespace std;

int main() {
    float lebar, tinggi;

    cout << "Masukkan lebar: ";
    cin >> lebar;
    cout << "Masukkan tinggi: ";
    cin >> tinggi;

    float luas = lebar * tinggi;
    float keliling = 2 * (lebar + tinggi);

    cout << "Luas = " << luas << endl;
    cout << "Keliling = " << keliling << endl;

    return 0;
}

