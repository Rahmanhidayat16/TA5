#include <iostream>
using namespace std;

struct Node {
    int harga;
    string namaProduk;
    Node* left;
    Node* right;
    Node(int h, string n): harga(h), namaProduk(n), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int harga, string namaProduk) {
    if (!root) return new Node(harga, namaProduk);
    if (harga < root->harga) 
        root->left = insertNode(root->left, harga, namaProduk);
    else if (harga > root->harga) 
        root->right = insertNode(root->right, harga, namaProduk);
    return root;
}

bool searchNode(Node* root, int harga) {
    if (!root) return false;
    if (root->harga == harga) return true;
    if (harga < root->harga) return searchNode(root->left, harga);
    return searchNode(root->right, harga);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << "Nama: " << root->namaProduk << " | Harga: Rp" << root->harga << endl;
    inorder(root->right);
}

int findMin(Node* root) {
    if (!root) return -1;
    while (root->left) root = root->left;
    cout << "Produk termurah: " << root->namaProduk << " (Rp" << root->harga << ")" << endl;
    return root->harga;
}

int findMax(Node* root) {
    if (!root) return -1;
    while (root->right) root = root->right;
    cout << "Produk termahal: " << root->namaProduk << " (Rp" << root->harga << ")" << endl;
    return root->harga;
}

int main() {
    Node* root = nullptr;
    int pilih, harga;
    string nama;

    do {
        cout << "\n=== SISTEM KATALOG PRODUK ===\n";
        cout << "1. Tambah produk\n";
        cout << "2. Cari produk berdasarkan harga\n";
        cout << "3. Tampilkan seluruh produk (Inorder)\n";
        cout << "4. Tampilkan produk termurah\n";
        cout << "5. Tampilkan produk termahal\n";
        cout << "6. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Masukkan nama produk: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan harga produk: Rp";
            cin >> harga;
            root = insertNode(root, harga, nama);
        } 
        else if (pilih == 2) {
            cout << "Masukkan harga produk yang dicari: Rp";
            cin >> harga;
            if (searchNode(root, harga))
                cout << "Produk dengan harga Rp" << harga << " ditemukan dalam katalog.\n";
            else
                cout << "Produk dengan harga Rp" << harga << " tidak ditemukan.\n";
        } 
        else if (pilih == 3) {
            if (!root) cout << "Katalog masih kosong.\n";
            else {
                cout << "\n=== Daftar Produk (Harga Terurut) ===\n";
                inorder(root);
            }
        } 
        else if (pilih == 4) {
            if (!root) cout << "Katalog masih kosong.\n";
            else findMin(root);
        } 
        else if (pilih == 5) {
            if (!root) cout << "Katalog masih kosong.\n";
            else findMax(root);
        }

    } while (pilih != 6);

    return 0;
}