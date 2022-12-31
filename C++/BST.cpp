#include <iostream>
#include <string>

using namespace std;

// Struct node BST
struct Node {
  int no_rek;
  string nama;
  Node *left;
  Node *right;
};

// Fungsi untuk menambahkan node baru ke dalam BST
void insert(Node *&root, int no_rek, string nama) {
  // Basis kasus: node tidak ada di dalam BST
  if (root == NULL) {
    root = new Node();
    root->no_rek = no_rek;
    root->nama = nama;
    root->left = NULL;
    root->right = NULL;
  }
  // Rekursif: node sudah ada di dalam BST
  else if (no_rek < root->no_rek) {
    insert(root->left, no_rek, nama);
  }
  else {
    insert(root->right, no_rek, nama);
  }
}

// Fungsi untuk mencari node dengan nomor rekening yang dicari di dalam BST
Node *search(Node *root, int no_rek) {
  // Basis kasus: node tidak ada di dalam BST
  if (root == NULL) {
    return NULL;
  }
  // Rekursif: node sudah ada di dalam BST
  else if (no_rek < root->no_rek) {
    return search(root->left, no_rek);
  }
  else if (no_rek > root->no_rek) {
    return search(root->right, no_rek);
  }
  else {
    return root;
  }
}

// Fungsi untuk menghapus node dengan nomor rekening yang dicari di dalam BST
void remove(Node *&root, int no_rek) {
  // Basis kasus: node tidak ada di dalam BST
  if (root == NULL) {
    return;
  }
  // Rekursif: node sudah ada di dalam BST
  else if (no_rek < root->no_rek) {
    remove(root->left, no_rek);
  }
  else if (no_rek > root->no_rek) {
    remove(root->right, no_rek);
  }
  else {
    // Kondisi 1: node tidak memiliki anak
    if (root->left == NULL && root->right == NULL) {
      delete root;
      root = NULL;
    }
    // Kondisi 2: node memiliki satu anak
    else if (root->left == NULL) {
      Node *temp = root;
      root = root->right;
      delete temp;
    }
    else if (root->right == NULL) {
      Node *temp = root;
      root = root->left;
      delete temp;
    }
    // Kondisi 3: node memiliki dua anak
    else {
      Node *temp = root->right;
      while (temp->left != NULL) {
        temp = temp->left;
      }
      root->no_rek = temp->no_rek;
      root->nama = temp->nama;
      remove(root->right, temp->no_rek);
    }
  }
}
int main() {
  Node *root = NULL;

  // Menambahkan node baru ke dalam BST
  insert(root, 123456, "Siswa 1");
  insert(root, 789123, "Siswa 2");
  insert(root, 456789, "Siswa 3");
  insert(root, 987654, "Siswa 4");

  // Mencari node dengan nomor rekening yang dicari
  Node *node = search(root, 789123);
  if (node != NULL) {
    cout << "Nomor rekening: " << node->no_rek << endl;
    cout << "Nama: " << node->nama << endl;
  }
  else {
    cout << "Node tidak ditemukan" << endl;
  }

  // Menghapus node dengan nomor rekening yang dicari
  remove(root, 123456);

  return 0;
}

