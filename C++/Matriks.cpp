#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sumMatrix(int (*arr1)[10], int (*arr2)[10], int n){
    int hasil[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            hasil[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    
    cout << "Hasil Penjumlahan Matriks : " << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << hasil[i][j] << " ";
        }
        cout <<endl;
    }
    cout <<endl;

}

void lessMatrix(int (*arr1)[10], int (*arr2)[10], int n){
    int hasil[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            hasil[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
    
    cout << "Hasil Pengurangan Matriks : " <<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << hasil[i][j] << " ";
        }
        cout <<endl;
    }
    cout <<endl;
}

void multiplyMatrix(int (*arr1)[10], int (*arr2)[10], int n){
    int hasil[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                hasil[i][j] = arr1[i][k] * arr2[k][j];
            }
        }
    }

    cout << "Hasil Perkalian Matriks : " << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << hasil[i][j] << " ";
        }
        cout <<endl;
    }
    cout <<endl;
}

void dividedMatrix(int (*arr1)[10], int (*arr2)[10], int n){
    int hasil[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            hasil[i][j] = 0;
        }
    }

    cout << "Hasil Pembagian Matriks : "<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << hasil[i][j] << " ";
        }
        cout <<endl;
    }
    cout <<endl;
}

int main(){
    cout << "=== Program Operasi Matriks ===" <<endl;
    int ukuran;

    cout << "Masukan Ordo Matriks : "; cin >> ukuran;
    int matriks1[10][10];
    int matriks2[10][10];

    cout << "Matriks 1" <<endl;
    for (int i = 0; i < ukuran; i++)
    {
        for (int j = 0; j < ukuran; j++)
        {
            cout << "Angka [" << i << "]" << "[" << j <<"] : "; cin >> matriks1[i][j];
        }
        cout << endl;
    }
    cout <<endl;

    cout << "Matriks 2" <<endl;
    for (int i = 0; i < ukuran; i++)
    {
        for (int j = 0; j < ukuran; j++)
        {
            cout << "Angka [" << i << "]" << "[" << j <<"] : "; cin >> matriks2[i][j];
        }
        cout << endl;
    }
    cout <<endl;
    
    cout << "Matriks 1 " <<endl;
    for (int i = 0; i < ukuran; i++){
        for (int j = 0; j < ukuran; j++){
            cout << matriks1[i][j] << " ";
        }
        cout <<endl;
    }

    cout << "\nMatriks 2 " <<endl;
    for (int i = 0; i < ukuran; i++){
        for (int j = 0; j < ukuran; j++){
            cout << matriks2[i][j] << " ";
        }
        cout <<endl;
    }
    cout <<endl;

    sumMatrix(matriks1, matriks2, ukuran);
    lessMatrix(matriks1, matriks2, ukuran);
    multiplyMatrix(matriks1, matriks2, ukuran);
    dividedMatrix(matriks1, matriks2, ukuran);

}