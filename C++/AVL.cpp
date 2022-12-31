#include <iostream>
#include <string>

using namespace std;

// Struct node AVL
struct Node {
  int no_rek;
  string nama;
  int height;
  Node *left;
  Node *right;
};

// Fungsi untuk menghitung ketinggian node
int getHeight(Node *node) {
  if (node == NULL) {
    return 0;
  }
  return node->height;
}

// Fungsi untuk menghitung balance factor node
int getBalance(Node *node) {
  if (node == NULL) {
    return 0;
  }
  return getHeight(node->left) - getHeight(node->right);
}

// Fungsi rotasi kanan
Node *rotateRight(Node *node) {
  Node *left = node->left;
  Node *leftRight = left->right;

  left->right = node;
  node->left = leftRight;

  node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
  left->height = max(getHeight(left->left), getHeight(left->right)) + 1;

  return left;
}

// Fungsi rotasi kiri
Node *rotateLeft(Node *node) {
  Node *right = node->right;
  Node *rightLeft = right->left;

  right->left = node;
  node->right = rightLeft;

  node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
  right->height = max(getHeight(right->left), getHeight(right->right)) + 1;

  return right;
}

// Fungsi untuk menambahkan node baru ke dalam AVL
void insert(Node *&root, int no_rek, string nama) {
  // Basis kasus: node tidak ada di dalam AVL
  if (root == NULL) {
    root = new Node();
    root->no_rek = no_rek;
    root->nama = nama;
    root->height = 1;
    root->left = NULL;
    root->right = NULL;
  }
  // Rekursif: node sudah ada di dalam AVL
  else if (no_rek < root->no_rek) {
    insert(root->left, no_rek, nama);
  }
  else {
    insert(root->right, no_rek, nama);
  }

  // Membalancing AVL
  root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
  int balance = getBalance(root);
  if (balance > 1 && no_rek < root->left->no_rek) {
    root = rotateRight(root);
  }
  if (balance < -1 && no_rek > root->right->no_rek) {
    root = rotateLeft(root);
  }
  if (balance > 1 && no_rek > root->left->no_rek) {
    root->left = rotateLeft(root->left);
    root = rotateRight(root);
  }
  if (balance < -1 && no_rek < root->right->no_rek) {
    root->right = rotateRight(root->right);
  root = rotateLeft(root);
    }
}

// Fungsi untuk mencari node dengan nomor rekening yang dicari di dalam AVL
Node *search(Node *root, int no_rek) {
  // Basis kasus: node tidak ada di dalam AVL
  if (root == NULL) {
    return NULL;
  }
  // Rekursif: node sudah ada di dalam AVL
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

// Fungsi untuk mencari node terkecil di dalam subtree
Node *findMinNode(Node *node) {
  while (node->left != NULL) {
    node = node->left;
  }
  return node;
}

// Fungsi untuk menghapus node dengan nomor rekening yang dicari di dalam AVL
void remove(Node *&root, int no_rek) {
  // Basis kasus: node tidak ada di dalam AVL
  if (root == NULL) {
    return;
  }
  // Rekursif: node sudah ada di dalam AVL
  if (no_rek < root->no_rek) {
    remove(root->left, no_rek);
  }
  else if (no_rek > root->no_rek) {
    remove(root->right, no_rek);
  }
  // Node ditemukan
  else {
    // Node tidak memiliki anak
    if (root->left == NULL && root->right == NULL) {
      delete root;
      root = NULL;
    }
    // Node hanya memiliki anak kiri
    else if (root->left != NULL && root->right == NULL) {
      Node *temp = root;
      root = root->left;
      delete temp;
    }
    // Node hanya memiliki anak kanan
    else if (root->left == NULL && root->right != NULL) {
      Node *temp = root;
      root = root->right;
      delete temp;
    }
    // Node memiliki kedua anak
    else {
      Node *temp = findMinNode(root->right);
      root->no_rek = temp->no_rek;
      root->nama = temp->nama;
      remove(root->right, temp->no_rek);
    }
  }

  // Membalancing AVL
  if (root == NULL) {
    return;
  }
  root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
  int balance = getBalance(root);
  if (balance > 1 && getBalance(root->left) >= 0) {
    root = rotateRight(root);
  }
  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = rotateLeft(root->left);
    root = rotateRight(root);
  }
  if (balance < -1 && getBalance(root->right) <= 0) {
    root = rotateLeft(root);
  }
  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rotateRight(root->right);
    root = rotateLeft(root);
  }
}

// Fungsi untuk mencetak data dari node
void printNode(Node *node) {
  cout << "Nomor rekening: " << node->no_rek << endl;
  cout << "Nama: " << node->nama << endl;
  cout << "Tinggi: " << node->height << endl;
}

// Fungsi rekursif untuk mencetak data dari seluruh node di dalam AVL
void printAVL(Node *root) {
  if (root != NULL) {
    printAVL(root->left);
    printNode(root);
    printAVL(root->right);
  }
}

int main() {
  // Inisialisasi AVL
  Node *root = NULL;

  // Menambahkan node baru ke dalam AVL
  insert(root, 123, "Siswa A");
  insert(root, 234, "Siswa B");
  insert(root, 345, "Siswa C");
  insert(root, 456, "Siswa D");
  insert(root, 567, "Siswa E");

  // Mencari node dengan nomor rekening 123 di dalam AVL
  Node *node = search(root, 123);
  if (node != NULL) {
    cout << "Nomor rekening: " << node->no_rek << endl;
    cout << "Nama: " << node->nama << endl;
  }
  else {
   cout << "Node tidak ditemukan." << endl;
  }

  // Menghapus node dengan nomor rekening 123 dari AVL
  remove(root, 123);

  // Mencari node dengan nomor rekening 123 di dalam AVL

  cout << "Setelah di hapus \n";
  node = search(root, 123);
  if (node != NULL) {
    cout << "Nomor rekening: " << node->no_rek << endl;
    cout << "Nama: " << node->nama << endl;
  }
  else {
    cout << "Node tidak ditemukan." << endl;
  }

  cout << "\n View Data \n";

  printAVL(root);

  return 0;
}


