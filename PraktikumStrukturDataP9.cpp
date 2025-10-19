#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int INFO;
    Node *LINK;
};

Node *FIRST = NULL;

Node* buatNode(int data) {
    Node *P = (Node*)malloc(sizeof(Node));
    P->INFO = data;
    P->LINK = NULL;
    return P;
}

void insertAkhir(int data) {
    Node *P = buatNode(data);
    if (FIRST == NULL)
        FIRST = P;
    else {
        Node *Q = FIRST;
        while (Q->LINK != NULL)
            Q = Q->LINK;
        Q->LINK = P;
    }
    cout << "Data " << data << " berhasil ditambahkan.\n";
}

// Menampilkan seluruh isi list
void tampilList() {
    Node *Q = FIRST;
    if (Q == NULL) {
        cout << "List kosong.\n";
        return;
    }
    cout << "Isi Linked List: ";
    while (Q != NULL) {
        cout << Q->INFO << " ";
        Q = Q->LINK;
    }
    cout << endl;
}

// Menghapus node pertama
void hapusDepan() {
    if (FIRST == NULL) {
        cout << "List kosong, tidak ada yang dihapus.\n";
        return;
    }
    Node *Hapus = FIRST;
    FIRST = FIRST->LINK;
    cout << "Data " << Hapus->INFO << " dihapus.\n";
    free(Hapus);
}

int main() {
    insertAkhir(10);
    insertAkhir(20);
    insertAkhir(30);
    tampilList();
    hapusDepan();
    tampilList();
    return 0;
}

