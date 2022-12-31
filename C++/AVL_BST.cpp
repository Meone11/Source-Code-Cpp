#include <iostream>
#include <string>
using namespace std;

struct AVL
{
    int no_rek;
    string nama;
    int height;
    AVL *left;
    AVL *right;
};

struct BST {
  int no_rek;
  string nama;
  BST *left;
  BST *right;
};


//Fungsi untuk AVL

// Fungsi untuk menghitung ketinggian node
int getHeight(AVL *avl) {
  if (avl == NULL) {
    return 0;
  }
  return avl->height;
}

// Fungsi untuk menghitung balance factor node
int getBalance(AVL *avl) {
  if (avl == NULL) {
    return 0;
  }
  return getHeight(avl->left) - getHeight(avl->right);
}

// Fungsi rotasi kanan
AVL *rotateRight(AVL *avl) {
  AVL *left = avl->left;
  AVL *leftRight = left->right;

  left->right = avl;
  avl->left = leftRight;

  avl->height = max(getHeight(avl->left), getHeight(avl->right)) + 1;
  left->height = max(getHeight(left->left), getHeight(left->right)) + 1;

  return left;
}

// Fungsi rotasi kiri
AVL *rotateLeft(AVL *avl) {
  AVL *right = avl->right;
  AVL *rightLeft = right->left;

  right->left = avl;
  avl->right = rightLeft;

  avl->height = max(getHeight(avl->left), getHeight(avl->right)) + 1;
  right->height = max(getHeight(right->left), getHeight(right->right)) + 1;

  return right;
}

// Fungsi untuk menambahkan node baru ke dalam AVL
void insertAVL(AVL *&root, int no_rek, string nama) {
  // Basis kasus: node tidak ada di dalam AVL
  if (root == NULL) {
    root = new AVL();
    root->no_rek = no_rek;
    root->nama = nama;
    root->height = 1;
    root->left = NULL;
    root->right = NULL;
  }
  // Rekursif: node sudah ada di dalam AVL
  else if (no_rek < root->no_rek) {
    insertAVL(root->left, no_rek, nama);
  }
  else {
    insertAVL(root->right, no_rek, nama);
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
AVL *searchAVL(AVL *root, int no_rek) {
  // Basis kasus: node tidak ada di dalam AVL
  if (root == NULL) {
    return NULL;
  }
  // Rekursif: node sudah ada di dalam AVL
  else if (no_rek < root->no_rek) {
    return searchAVL(root->left, no_rek);
  }
  else if (no_rek > root->no_rek) {
    return searchAVL(root->right, no_rek);
  }
  else {
    return root;
  }
}

// Fungsi untuk mencari node terkecil di dalam subtree
AVL *findMinNode(AVL *node) {
  while (node->left != NULL) {
    node = node->left;
  }
  return node;
}

// Fungsi untuk menghapus node dengan nomor rekening yang dicari di dalam AVL
void removeAVL(AVL*&root, int no_rek) {
  // Basis kasus: node tidak ada di dalam AVL
  if (root == NULL) {
    return;
  }
  // Rekursif: node sudah ada di dalam AVL
  if (no_rek < root->no_rek) {
    removeAVL(root->left, no_rek);
  }
  else if (no_rek > root->no_rek) {
    removeAVL(root->right, no_rek);
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
      AVL *temp = root;
      root = root->left;
      delete temp;
    }
    // Node hanya memiliki anak kanan
    else if (root->left == NULL && root->right != NULL) {
      AVL *temp = root;
      root = root->right;
      delete temp;
    }
    // Node memiliki kedua anak
    else {
      AVL *temp = findMinNode(root->right);
      root->no_rek = temp->no_rek;
      root->nama = temp->nama;
      removeAVL(root->right, temp->no_rek);
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
void printNodeAVL(AVL *node) {
  cout << "Nomor rekening: " << node->no_rek << endl;
  cout << "Nama: " << node->nama << endl;
  cout << "Tinggi: " << node->height << endl;
}

// Fungsi rekursif untuk mencetak data dari seluruh node di dalam AVL
void printAVL(AVL *root) {
  if (root != NULL) {
    printAVL(root->left);
    printNodeAVL(root);
    printAVL(root->right);
  }
}


//Fungsi Untuk BST

// Fungsi untuk menambahkan node baru ke dalam BST
void insertBST(BST *&root, int no_rek, string nama) {
  // Basis kasus: node tidak ada di dalam BST
  if (root == NULL) {
    root = new BST();
    root->no_rek = no_rek;
    root->nama = nama;
    root->left = NULL;
    root->right = NULL;
  }
  // Rekursif: node sudah ada di dalam BST
  else if (no_rek < root->no_rek) {
    insertBST(root->left, no_rek, nama);
  }
  else {
    insertBST(root->right, no_rek, nama);
  }
}

// Fungsi untuk mencari node dengan nomor rekening yang dicari di dalam BST
BST *searchBST(BST *root, int no_rek) {
  // Basis kasus: node tidak ada di dalam BST
  if (root == NULL) {
    return NULL;
  }
  // Rekursif: node sudah ada di dalam BST
  else if (no_rek < root->no_rek) {
    return searchBST(root->left, no_rek);
  }
  else if (no_rek > root->no_rek) {
    return searchBST(root->right, no_rek);
  }
  else {
    return root;
  }
}

// Fungsi untuk menghapus node dengan nomor rekening yang dicari di dalam BST
void removeBST(BST *&root, int no_rek) {
  // Basis kasus: node tidak ada di dalam BST
  if (root == NULL) {
    return;
  }
  // Rekursif: node sudah ada di dalam BST
  else if (no_rek < root->no_rek) {
    removeBST(root->left, no_rek);
  }
  else if (no_rek > root->no_rek) {
    removeBST(root->right, no_rek);
  }
  else {
    // Kondisi 1: node tidak memiliki anak
    if (root->left == NULL && root->right == NULL) {
      delete root;
      root = NULL;
    }
    // Kondisi 2: node memiliki satu anak
    else if (root->left == NULL) {
      BST *temp = root;
      root = root->right;
      delete temp;
    }
    else if (root->right == NULL) {
      BST *temp = root;
      root = root->left;
      delete temp;
    }
    // Kondisi 3: node memiliki dua anak
    else {
      BST *temp = root->right;
      while (temp->left != NULL) {
        temp = temp->left;
      }
      root->no_rek = temp->no_rek;
      root->nama = temp->nama;
      removeBST(root->right, temp->no_rek);
    }
  }
}

// Fungsi untuk mencetak data dari node
void printNodeBST(BST *node) {
  cout << "Nomor rekening: " << node->no_rek << endl;
  cout << "Nama: " << node->nama << endl;
}

// Fungsi rekursif untuk mencetak data dari seluruh node di dalam BST
void printBST(BST *root) {
  if (root != NULL) {
    printBST(root->left);
    printNodeBST(root);
    printBST(root->right);
  }
}

void Menu(){
    cout << "==================================\n";
    cout << "====== Welcome To MyProgram ======\n";
    cout << "==================================\n";
    cout << "1. AVL\n";
    cout << "2. BST\n";
    cout << "3. Exit\n";
}

void SubMenu(){
    cout << "==================================\n";
    cout << "====== Welcome To MyProgram ======\n";
    cout << "==================================\n";
    cout << "1. Insert Data\n";
    cout << "2. Search Data\n";
    cout << "3. Delete Data\n";
    cout << "4. View Data\n";
    cout << "5. Exit\n";
}

int main(){
    BST *rootBst = NULL;
    AVL *rootAvl = NULL;

    AVL *nodeAvl;
    BST *nodeBST;

    int menu, menuAvl, menuBst;
    bool keluar = true;
    bool keluarSubAvl = true;
    bool keluarSubBst = true;


    int dataAvl, dataBst;
    int rek;
    int cariBst, cariAvl;
    int deleteBst, deleteAvl;
    string Name;

    do
    {
        system("clear");
        Menu();
        cout << "Pilihan : "; cin >> menu;

        switch (menu)
        {
        case 1:
            do
            {
                SubMenu();
                cout << "Pilihan : "; cin >> menuAvl;

                switch (menuAvl)
                {
                case 1:
                    cout << "Masukan Banyak Data : "; cin >>dataAvl;
                    for (int i = 0; i < dataAvl; i++)
                    {
                        cin.ignore();
                        cout << "Nama : "; getline(cin, Name);
                        cout << "Nomor Rekening : "; cin >> rek;

                        insertAVL(rootAvl, rek, Name);
                    }

                    cout << "\nData Berhasil Di input!\n";
                    
                    break;
                case 2:
                    cout << "Masukan Rekening ayng akan dicari : "; cin >> cariAvl;
                    nodeAvl = searchAVL(rootAvl, cariAvl);

                    if (nodeAvl != NULL) {
                        cout << "Nomor rekening: " << nodeAvl->no_rek << endl;
                        cout << "Nama: " << nodeAvl->nama << endl;
                    }
                    else {
                        cout << "Node tidak ditemukan." << endl;
                    }
                    break;
                case 3:
                    cout << "Masukan Nomor Rekening yang akan dihapus : "; cin >> deleteAvl;

                    removeAVL(rootAvl, deleteAvl);

                    cout <<"Data berhasil dihapus!\n";
                    break;
                case 4:
                    printAVL(rootAvl);
                    break;
                case 5:
                    keluarSubAvl = false;
                    break;
                
                default:
                    break;
                }
            } while (keluarSubAvl);
            
            break;
        case 2:
            do
            {
                SubMenu();
                cout << "Pilihan : "; cin >> menuAvl;

                switch (menuAvl)
                {
                case 1:
                    cout << "Masukan Banyak Data : "; cin >>dataBst;
                    for (int i = 0; i < dataBst; i++)
                    {
                        cin.ignore();
                        cout << "Nama : "; getline(cin, Name);
                        cout << "Nomor Rekening : "; cin >> rek;

                        insertBST(rootBst, rek, Name);
                    }

                    cout << "\nData Berhasil Di input!\n";
                    break;
                case 2:
                    cout << "Masukan Rekening ayng akan dicari : "; cin >> cariBst;
                    nodeBST = searchBST(rootBst, cariBst);

                    if (nodeBST != NULL) {
                        cout << "Nomor rekening: " << nodeBST->no_rek << endl;
                        cout << "Nama: " << nodeBST->nama << endl;
                    }
                    else {
                        cout << "Node tidak ditemukan" << endl;
                    }
                    break;
                case 3:
                    cout << "Masukan Nomor Rekening yang akan dihapus : "; cin >> deleteBst;

                    removeBST(rootBst, deleteBst);

                    cout <<"Data berhasil dihapus!\n";
                    break;
                case 4:
                    printBST(rootBst);
                    break;
                case 5:
                    keluarSubBst = false;
                    break;
                
                default:
                    break;
                }
            } while (keluarSubBst);
            break;
        case 3:
            keluar = false;
            break;
        
        default:
            break;
        }
    } while (keluar);
    
}