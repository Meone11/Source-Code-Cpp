#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
};

struct BST {
    Node *root;

    BST() {
        root = NULL;
    }

    void insert(int value) {
        if (root == NULL) {
            root = new Node;
            root->value = value;
            root->left = NULL;
            root->right = NULL;
        } else {
            insert(root, value);
        }
    }

    void insert(Node *node, int value) {
        if (value < node->value) {
            if (node->left == NULL) {
                node->left = new Node;
                node->left->value = value;
                node->left->left = NULL;
                node->left->right = NULL;
            } else {
                insert(node->left, value);
            }
        } else {
            if (node->right == NULL) {
                node->right = new Node;
                node->right->value = value;
                node->right->left = NULL;
                node->right->right = NULL;
            } else {
                insert(node->right, value);
            }
        }
    }

    Node *search(int value) {
        return search(root, value);
    }

    Node *search(Node *node, int value) {
        if (node == NULL) {
            return NULL;
        }
        if (node->value == value) {
            return node;
        }
        if (value < node->value) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    int countOnlyLeftChild() {
        return countOnlyLeftChild(root);
    }

    int countOnlyLeftChild(Node *node) {
        if (node == NULL) {
            return 0;
        }
        int count = 0;
        if (node->left != NULL && node->right == NULL) {
            count++;
        }
        count += countOnlyLeftChild(node->left);
        count += countOnlyLeftChild(node->right);
        return count;
    }

    int countOnlyRightChild() {
        return countOnlyRightChild(root);
    }

    int countOnlyRightChild(Node *node) {
        if (node == NULL) {
            return 0;
        }
        int count = 0;
        if (node->right != NULL && node->left == NULL) {
            count++;
        }
        count += countOnlyRightChild(node->left);
        count += countOnlyRightChild(node->right);
        return count;
    }

    int countTwoChildren() {
        return countTwoChildren(root);
    }

    int countTwoChildren(Node *node) {
    if (node == NULL) {
        return 0;
    }
    int count = 0;
    if (node->left != NULL && node->right != NULL) {
        count++;
    }
    count += countTwoChildren(node->left);
    count += countTwoChildren(node->right);
    return count;
    }

    void printOnlyLeftChild() {
        cout << "Node yang hanya memiliki anak kiri: \n";
        printOnlyLeftChild(root);
        cout << endl;
    }

    void printOnlyLeftChild(Node *node) {
        if (node == NULL) {
            // cout << "Tree ini tidak memiliki Node yang hanya mempunyai Left Chiild saja\n";
            return;
        }
        if (node->left != NULL && node->right == NULL) {
            cout << node->value << " ";
        }
        printOnlyLeftChild(node->left);
        printOnlyLeftChild(node->right);
    }

    void printOnlyRightChild() {
        cout << "Node yang hanya memiliki anak kanan: \n";
        printOnlyRightChild(root);
        cout << endl;
    }

    void printOnlyRightChild(Node *node) {
        if (node == NULL) {
            // cout << "Tree ini tidak memiliki Node yang hanya mempunyai Right Chiild saja\n";
            return;
        }
        if (node->right != NULL && node->left == NULL) {
            cout << node->value << " ";
        }
        printOnlyRightChild(node->left);
        printOnlyRightChild(node->right);
    }

    void printTwoChildren() {
        cout << "Node yang memiliki 2 anak: \n";
        printTwoChildren(root);
        cout << endl;
    }

    void printTwoChildren(Node *node) {
        if (node == NULL) {
            // cout << "Tree ini tidak memiliki Node yang  mempunyai 2 Chiild Node\n";
            return;
        }
        if (node->left != NULL && node->right != NULL) {
            cout << node->value << " ";
        }
        printTwoChildren(node->left);
        printTwoChildren(node->right);
    }
};


void Menu(){
    cout << "==================================\n";
    cout << "====== Welcome To MyProgram ======\n";
    cout << "==================================\n";
    cout << "1. Insert Data\n";
    cout << "2. Search Data\n";
    cout << "3. Hitung Node yang memiliki Left Node\n";
    cout << "4. Hitung Node yang memiliki Right Node\n";
    cout << "5. Hitung Node yang memiliki 2 Node\n";
    cout << "6. Exit\n";
}

int main() {
    BST tree;
    Node *root;

    int menu, data, inputData, cariData;
    bool keluar = true;

    do
    {
        Menu();
        cout << "Pilihan : "; cin >> menu;

        switch (menu)
        {
        case 1:
            cout << "Masukan Jumlah Data : "; cin >> data;

            for (int i = 0; i < data; i++){
                cout << "Masukan Data indeks ke - "<< i << " : "; cin >> inputData;

                tree.insert(inputData);
            }

            cout << "Data Berhasil Di input!\n";
            break;
        case 2:
            cout << "Masukan Nilai yang ingin dicari : "; cin >> cariData;

            root = tree.search(cariData);
            if (root != NULL){
                cout << "Data yang anda cari : " << root->value <<endl;
            }else{
                cout << "Data yang anda cari tidak ditemukan!\n";
            }
            break;
        case 3:
            cout << "Jumlah Node yang memiliki anak kiri saja \n";
            cout << "Jumlah node : " << tree.countOnlyLeftChild() << endl;

            cout <<endl;
            tree.printOnlyLeftChild();
            break;
        case 4:
            cout << "Jumlah Node yang memiliki anak kanan saja \n";
            cout << "Jumlah node : " << tree.countOnlyRightChild() << endl;

            cout <<endl;
            tree.printOnlyRightChild();
            break;
        case 5:
            cout << "Jumlah Node yang memiliki 2 Anak \n";
            cout << "Jumlah node : " << tree.countTwoChildren() << endl;

            cout <<endl;
            tree.printTwoChildren();
            break;
        case 6:
            keluar = false;
            break;
        
        default:
            break;
        }
    } while (keluar);
    
















    // tree.insert(5);
    // tree.insert(3);
    // tree.insert(7);
    // tree.insert(2);
    // tree.insert(4);
    // tree.insert(6);
    // tree.insert(8);


    // cout << "mencari Nilai : " <<endl;
    // root = tree.search(2);
    // if (root != NULL){
    //     cout << root->value << "<- ini nilai yang di hasilkan \n";
    // }

    // cout << "Jumlah node yang hanya memiliki anak kanan: " << tree.countOnlyRightChild() << endl;
    // cout << "Jumlah node yang memiliki 2 anak: " << tree.countTwoChildren() << endl;



    return 0;
}

