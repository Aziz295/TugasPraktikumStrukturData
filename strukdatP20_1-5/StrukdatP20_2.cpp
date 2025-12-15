#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* tail = NULL;

void insert(int data) {
    Node* baru = new Node;
    baru->data = data;

    if (tail == NULL) {
        tail = baru;
        baru->next = baru;
    } else {
        baru->next = tail->next;
        tail->next = baru;
        tail = baru;
    }
    cout << "Insert " << data << endl;
}

void hapus(int data) {
    if (tail == NULL) return;

    Node* curr = tail->next;
    Node* prev = tail;

    do {
        if (curr->data == data) {
            prev->next = curr->next;
            if (curr == tail)
                tail = prev;
            delete curr;
            cout << "Hapus " << data << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);
}

void traverse() {
    if (tail == NULL) return;

    Node* curr = tail->next;
    cout << "Isi list: ";
    do {
        cout << curr->data << " -> ";
        curr = curr->next;
    } while (curr != tail->next);
    cout << "(kembali ke awal)\n";
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    traverse();
    hapus(20);
    traverse();
}

