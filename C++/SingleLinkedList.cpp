#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    /* data */
    char kode[10];
    int nilai1;
    //nilai2,nilai3,nilai4; 
    int IPK;
    struct Node *next;
};

struct Node *head;

void craete(struct Node *root){
    int nilai1;
    //nilai2, nilai3, nilai4;
    int ipk;
    char kode[10];
    cout << "Kode Mahasiswa : ";cin >> kode;
    cout << "Bobot Nilai 1 : "; cin >> nilai1;
    // cout << "Bobot Nilai 2 : "; cin >> nilai2;
    // cout << "Bobot Nilai 3 : "; cin >> nilai3;
    // cout << "Bobot Nilai 4 : "; cin >> nilai4;
    cout << "Ipk Mahasiswa : "; cin >> ipk;

    if (root == NULL){
        head = (Node*) malloc(sizeof(Node));
        head->nilai1 = nilai1;
        // head->nilai2 = nilai2;
        // head->nilai3 = nilai3;
        // head->nilai4 = nilai4;
        head->IPK = ipk;
        strcpy(head->kode, kode);
        head->next = NULL;
    }else {
        while (root->next != NULL){
            root = root->next;
        }
        root->next = (Node*) malloc(sizeof(Node));
        root->next->nilai1 = nilai1;
        // root->next->nilai2 = nilai2;
        // root->next->nilai3 = nilai3;
        // root->next->nilai4 = nilai4;
        root->next->IPK = ipk;
        strcpy(root->next->kode, kode);
    }
}

void Display(struct Node *root){
    while (root != NULL){
        cout << root->kode << " " << root->nilai1<< " " << root->IPK ;
        cout <<endl;
        root  = root->next;
    }
}

void writeData(struct Node *root){
    FILE *fp = fopen("file.txt", "w");

    while (root != NULL){
        fwrite(root, sizeof(Node), 1, fp);
        root = root->next;
    }
    fclose(fp);
    cout << "data telah di tulis!!!" << endl;
}

void readData(struct Node *root){
    struct Node node;
    FILE *fp = fopen("file.txt", "r");
    while ( fread(&node, sizeof(Node), 1, fp)){
        if (root == NULL){
            head = (Node*) malloc(sizeof(Node));
            head->nilai1 = node.nilai1;
            // head->nilai2 = node.nilai2;
            // head->nilai3 = node.nilai3;
            // head->nilai4 = node.nilai4;
            head->IPK = node.IPK;
            strcpy(head->kode, node.kode);
            head->next = NULL;
        }else {
            while (root->next != NULL){
                root = root->next;
            }
            root->next = (Node*) malloc(sizeof(Node));
            root->next->nilai1 = node.nilai1;
            // root->next->nilai2 = node.nilai2;
            // root->next->nilai3 = node.nilai3;
            // root->next->nilai4 = node.nilai4;
            root->next->IPK = node.IPK;
            strcpy(root->next->kode, node.kode);
        }
    }
    fclose(fp);
}

int main(){
    int banyak, pilihan;
    do
    {
        /* code */
        system("clear");
        cout<<"----------MENU----------";
        cout<<"\n1. create";
        cout<<"\n2. Write";
        cout<<"\n3. Read";
        cout<<"\n4. Display";
        cout<<"\n0. exit";
        cout <<"\nMasukan Pilihan : ";cin >>banyak;
        switch (banyak)
        {
        case 1:
            /* code */
            craete(head);
            break;
        case 2:
            /* code */
            writeData(head);
            break;
        case 3:
            /* code */
            readData(head);
            break;
        case 4:
            /* code */
            Display(head);
            break;
        }
        cout << "Ulang ? 1 if yes"; cin >> pilihan;
    } while (pilihan == 1);
    
}