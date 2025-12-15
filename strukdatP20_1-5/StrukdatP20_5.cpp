#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(string data) {
    Node* baru = new Node;
    baru->data = data;
    baru->next = NULL;

    if (rear == NULL)
        front = rear = baru;
    else {
        rear->next = baru;
        rear = baru;
    }
    cout << "Masuk antrian: " << data << endl;
}

void dequeue() {
    if (front == NULL) {
        cout << "Antrian kosong\n";
        return;
    }
    Node* temp = front;
    cout << "Keluar antrian: " << front->data << endl;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    delete temp;
}

void display() {
    Node* curr = front;
    cout << "Antrian: ";
    while (curr) {
        cout << curr->data << " <- ";
        curr = curr->next;
    }
    cout << "NULL\n";
}

int main() {
    enqueue("A");
    enqueue("B");
    enqueue("C");
    display();
    dequeue();
    display();
}

