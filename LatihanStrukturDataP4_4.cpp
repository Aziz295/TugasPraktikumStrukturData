#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;   
    int S[MAX] = {10, 20, 30, 40, 50};  
    int top = 4;         

    cout << "=== POP Data dari Stack ===\n";

    while (top >= 0) {
        cout << "Data " << S[top] << " dikeluarkan dari stack (POP)\n";
        top--;  
    }

    cout << "Stack sekarang kosong.\n";

    return 0;
}

