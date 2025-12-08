#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *left, *right;
};

Node* createNode(char data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    // Membuat struktur pohon sesuai hasil soal
    
    Node* R = createNode('R');
    Node* A = createNode('A');
    Node* E = createNode('E');
    Node* S = createNode('S');
    Node* T = createNode('T');
    Node* I = createNode('I');

    // Menyusun pohon
    R->left = A;
    R->right = E;

    A->left = S;
    A->right = T;

    S->left = I;

    // Output
    cout << "PreOrder  : "; 
    preOrder(R); 
    cout << endl;

    cout << "InOrder   : ";
    inOrder(R); 
    cout << endl;

    cout << "PostOrder : ";
    postOrder(R); 
    cout << endl;

    return 0;
}

