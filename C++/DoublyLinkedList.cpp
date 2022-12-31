#include <bits/stdc++.h>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *next;
    Node *prev;
};

typedef Node *NodePtr;

NodePtr Head = NULL;
NodePtr Tail = NULL;

int isEmpty(){
    return Head == NULL;
}

void InsertAtHead(int value){
    NodePtr node = new Node;
    node->data = value;
    node->next = NULL;
    node->prev = NULL;

    if (isEmpty()){
        Head = node;
        Tail = node;
    } else {
        node->next = Head;
        Head->prev = node;
        Head = node;
    }
}

void InsertAtTail(int value){
    NodePtr node = new Node;
    node->data = value;
    node->next = NULL;
    node->prev = NULL;

    if (isEmpty()){
        Head = node;
        Tail = node;
    } else {
        Tail->next = node;
        node->prev = Tail;
        Tail = node;
    }
}

int HapusDepan(){
    int item;

    if (isEmpty()){
        cout << "Linked List Is Empty!!" <<endl;
    }else{
        item = Head->data;
        if ( Head->next != NULL ){
            Head->next->prev =  NULL;
        }

        NodePtr next = Head->next;
        free(Head);
        Head = next;
    }

    return item;
}

int HapusBelakang(){
    int item;

    if ( isEmpty() ){
        cout << "Linked List Is Empty!!" <<endl;
    }else {
        item = Tail->data;
        if ( Tail->prev != NULL ){
            Tail->prev->next = NULL;
        }

        NodePtr prev = Tail->prev;
        Tail->prev = NULL;
        free(Tail);
        Tail = prev;
    }
    return item;
}

void Hapus(int key){
    if (isEmpty()){
        cout << "Linked List Is Empty!!" << endl;
    }
    
    NodePtr curr = Head;
    while (curr != NULL && curr->data != key)
    {
        /* code */
        curr = curr->next;
    }

    if ( curr == NULL ){
        cout << "Data's Not Found" << endl;
    }

    if ( curr->prev == NULL ){
        HapusDepan();
    } else if ( curr->next ==  NULL ){
       HapusBelakang(); 
    } else {
        NodePtr nextPtr = curr->next;
        NodePtr prevPtr = curr->prev;
        nextPtr->prev = prevPtr;
        prevPtr->next = nextPtr;
        curr->next = NULL;
        curr->prev = NULL;
        free(curr);
        curr = NULL;
    }
    
}

void BacaList(){
    NodePtr curr = Head;
    while (curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout <<endl;
}

void BacaList1(vector<int>& Nomor, vector<string>& Nama, vector<string>& Kaset, vector<int>& LamaPinjam){
    for (int i = 0; i < Nama.size(); i++){
        cout << "Nomor Urut Pelanggan : " << Nomor.at(i);
        cout <<endl;
        cout << "Nama Pelanggan : " << Nama.at(i);
        cout <<endl;        
        cout << "Kaset yang Dipinjam : " << Kaset.at(i);
        cout <<endl;        
        cout << "Lama Pinjam : " << LamaPinjam.at(i); 
        cout <<endl<<endl;
    }
}

int main(){
    int BanyakData, pilihan, BanyakDataHapus;
    char menu;

    int Nomor, Nomor_hapus, Lama_Pinjam;
    vector<int> nomor, nomor_hapus, lama_pinjam;
    
    string name, Kaset;
    vector<string> nama, kaset;
    string nama_hapus;
    int index;

    do
    {
        /* code */
        system("clear");
        cout<<"----------MENU----------";
        cout<<"\n1. Input Peminjam";
        cout<<"\n2. Hapus Peminjam";
        cout<<"\n3. Baca List Peminjam\n";
        cout << "Masukan Pilihan : ";cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            /* code */
            system("clear");
            cout << "----------INPUT PEMINJAM----------" <<endl;
            cout <<"Banyak Data : ";cin >> BanyakData;
            for ( int i = 0; i < BanyakData; i++){
                cout << "\nData Ke - " << i+1 <<endl;
                cout << "Nomor Urut Pelanggan : "; cin >> Nomor;
                nomor.push_back(Nomor);
                cin.ignore();
                cout << "Nama Pelanggan : "; getline(cin, name);
                nama.push_back(name);
                cout << "Kaset yang Dipinjam : "; getline(cin, Kaset);
                kaset.push_back(Kaset);
                cout << "Lama Pinjam : "; cin >> Lama_Pinjam;
                lama_pinjam.push_back(Lama_Pinjam);
                InsertAtTail(Nomor);
            }
            break;

        case 2:
            /* code */
            system("clear");
            cout << "----------HAPUS PEMINJAM----------" <<endl;
            cin.ignore();
            cout <<"Masukan Nama Data yang ingin di hapus : ";getline(cin, nama_hapus);
            for (int i = 0; i < BanyakData; i++){
                if (nama[i] == nama_hapus){
                    Hapus(nomor.at(i));
                    nomor.erase(nomor.begin() + i);
                    nama.erase(nama.begin() + i);
                    kaset.erase(kaset.begin() + i);
                    lama_pinjam.erase(lama_pinjam.begin() + i);
                }
            }
            cout << "Data Berhasil Di Hapus Atas Nama " << nama_hapus <<endl;
            break;

        case 3:
            /* code */
            system("clear");
            cout << "---------BACA LIST PEMINJAM---------" <<endl<<endl;
            BacaList1(nomor, nama, kaset, lama_pinjam);
            break;
        
        default:
            break;
        }

        cout <<"Apakah Anda Ingin Mengulangi Program Ini ? (y/n) : "; cin >> menu;
    } while (menu == 'y' || menu == 'Y');
    
}