#include <iostream>
#include <string>

using namespace std;

struct Node {
  int no_rek;
  string nama;
  Node *left;
  Node *right;
  int height;
};

int getHeight(Node *node) {
  if (node == NULL) return 0;
  return node->height;
}

int getBalance(Node *node) {
  if (node == NULL) return 0;
  return getHeight(node->left) - getHeight(node->right);
}

Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

  return x;
}

Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

  return y;
}

Node *newNode(int no_rek, string nama) {
  Node *node = new Node();
  node->no_rek = no_rek;
  node->nama = nama;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return node;
}

void insertBST(Node *&node, int no_rek, string nama) {
  if (node == NULL) {
    node = new Node();
    node->no_rek = no_rek;
    node->nama = nama;
    node->left = NULL;
    node->right = NULL;
  } else if (no_rek < node->no_rek) {
    insertBST(node->left, no_rek, nama);
  } else if (no_rek > node->no_rek) {
    insertBST(node->right, no_rek, nama);
  }
}

Node *insert(Node *node, int no_rek, string nama) {
  if (node == NULL) return newNode(no_rek, nama);

  if (no_rek < node->no_rek) node->left = insert(node->left, no_rek, nama);
  else if (no_rek > node->no_rek) node->right = insert(node->right, no_rek, nama);
  else return node;

  node->height = 1 + max(getHeight(node->left), getHeight(node->right));

  int balance = getBalance(node);

  // Left Left Case
  if (balance > 1 && no_rek < node->left->no_rek) return rightRotate(node);

  // Right Right Case
  if (balance < -1 && no_rek > node->right->no_rek) return leftRotate(node);

  // Left Right Case
  if (balance > 1 && no_rek > node->left->no_rek) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  // Right Left Case
  if (balance < -1 && no_rek < node->right->no_rek) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

void insertAVL(Node *&node, int no_rek, string nama) {
  node = insert(node, no_rek, nama);
}

Node *minValueNode(Node *node) {
  Node *current = node;
  while (current->left != NULL) current = current->left;
  return current;
}

void deleteNodeBST(Node *&node, int no_rek) {
  if (node == NULL) return;

  if (no_rek < node->no_rek) {
    deleteNodeBST(node->left, no_rek);
  } else if (no_rek > node->no_rek) {
    deleteNodeBST(node->right, no_rek);
  } else {
    if (node->left == NULL && node->right == NULL) {
      delete node;
      node = NULL;
    } else if (node->left == NULL) {
      Node *temp = node;
      node = node->right;
      delete temp;
    } else if (node->right == NULL) {
      Node *temp = node;
      node = node->left;
      delete temp;
    } else {
      Node *temp = node->right;
      while (temp->left != NULL) temp = temp->left;
      node->no_rek = temp->no_rek;
      deleteNodeBST(node->right, temp->no_rek);
    }
  }
}


Node *deleteNode(Node *root, int no_rek) {
  if (root == NULL) return root;

  if (no_rek < root->no_rek) root->left = deleteNode(root->left, no_rek);
  else if (no_rek > root->no_rek) root->right = deleteNode(root->right, no_rek);
  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      Node *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else *root = *temp;
      delete temp;
    } else {
      Node *temp = minValueNode(root->right);
      root->no_rek = temp->no_rek;
      root->right = deleteNode(root->right, temp->no_rek);
    }
  }

  if (root == NULL) return root;

  root->height = 1 + max(getHeight(root->left), getHeight(root->right));

  int balance = getBalance(root);

  // Left Left Case
  if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);

  // Left Right Case
 
if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  // Right Right Case
  if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);

  // Right Left Case
  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

void deleteNodeAVL(Node *&node, int no_rek) {
  node = deleteNode(node, no_rek);
}

bool searchNodeBST(Node *node, int no_rek) {
  if (node == NULL) return false;

  if (no_rek < node->no_rek) {
    return searchNodeBST(node->left, no_rek);
  } else if (no_rek > node->no_rek) {
    return searchNodeBST(node->right, no_rek);
  } else {
    return true;
  }
}

bool searchNodeAVL(Node *node, int no_rek) {
  if (node == NULL) return false;

  if (node->no_rek == no_rek) return true;

  if (node->no_rek > no_rek) {
    return searchNodeAVL(node->left, no_rek);
  } else {
    return searchNodeAVL(node->right, no_rek);
  }
}


void preOrder(Node *node) {
  if (node != NULL) {
    cout << node->no_rek << " " << node->nama << endl;
    preOrder(node->left);
    preOrder(node->right);
  }
}

void Menu(){
    cout << "==================================\n";
    cout << "====== Welcome To MyProgram ======\n";
    cout << "==================================\n";
    cout << "1. Insert dengan AVL\n";
    cout << "2. Insert dengan BST\n";
    cout << "3. Delete dengan AVL\n";
    cout << "4. Delete dengan BST\n";
    cout << "5. Search dengan AVL\n";
    cout << "6. Search dengan BST\n";
    cout << "7. View Data\n";
    cout << "8. Exit\n";
}

int main() {
    Node *root = NULL;

    int menu, menuAvl, menuBst;
    bool keluar = true;


    int dataAvl, dataBst;
    int rek;
    int cariBst, cariAvl;
    int deleteBst, deleteAvl;
    bool nodeAvl = false;
    bool nodeBst = false;
    string Name;

    do
    {
        Menu();
        cout << "Pilihan : "; cin >> menu;

        switch (menu)
        {
        case 1:
            cout << "Masukan Banyak Data : "; cin >>dataAvl;
            for (int i = 0; i < dataAvl; i++)
            {
                cin.ignore();
                cout << "Nama : "; getline(cin, Name);
                cout << "Nomor Rekening : "; cin >> rek;

                insertAVL(root, rek, Name);
            }

            cout << "\nData Berhasil Di input!\n";
            break;
        case 2:
            cout << "Masukan Banyak Data : "; cin >>dataBst;
            for (int i = 0; i < dataBst; i++)
            {
                cin.ignore();
                cout << "Nama : "; getline(cin, Name);
                cout << "Nomor Rekening : "; cin >> rek;

                insertBST(root, rek, Name);
            }

            cout << "\nData Berhasil Di input!\n";
            break;
        case 3:
            cout << "Masukan Nomor Rekening yang akan dihapus : "; cin >> deleteAvl;

            deleteNodeAVL(root, deleteAvl);

            cout <<"Data berhasil dihapus!\n";
            break;
        case 4:
            cout << "Masukan Nomor Rekening yang akan dihapus : "; cin >> deleteBst;

            deleteNodeAVL(root, deleteBst);

            cout <<"Data berhasil dihapus!\n";
            break;
        case 5:
            cout << "Masukan Rekening ayng akan dicari : "; cin >> cariAvl;
            nodeAvl = searchNodeAVL(root, cariAvl);

            if (nodeAvl) {
                cout << "Nomor rekening: " << root->no_rek << endl;
                cout << "Nama: " << root->nama << endl;
                }
            else {
                cout << "Node tidak ditemukan." << endl;
            }

            break;
        case 6:
            cout << "Masukan Rekening ayng akan dicari : "; cin >> cariBst;
            nodeBst = searchNodeAVL(root, cariBst);

            if (nodeBst) {
                cout << "Nomor rekening: " << root->no_rek << endl;
                cout << "Nama: " << root->nama << endl;
                }
            else {
                cout << "Node tidak ditemukan." << endl;
            }
            break;
        case 7:
            cout << "Ini Adalah Node dari Tree Avl dan BSt : \n";
            preOrder(root);
            break;
        case 8:
            keluar = false;
            break;
        
        default:
            break;
        }
    } while (keluar);

    return 0;
}
