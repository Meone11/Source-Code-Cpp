#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Data
{
    string nama;
    string jeniskelamin;
    int index;
};

void printData(Data data[], int n){
    cout << "Nama dan jenis kelamin siswa:" << endl;
    for (int i = 0; i < n; i++) {
        cout << data[i].nama << " (" << data[i].jeniskelamin << ")" << endl;
    }
}


int main() {

    Data data[20];
  // Jumlah siswa dalam kelas 
  int n = 20;

  // Jumlah anggota kelompok
  int r = 5;

  // Memasukkan nama dan jenis kelamin siswa ke dalam array
    cout << "Masukan Data Siswa : \n";
    for (int i = 0; i < n; i++){
        cin.ignore();
        cout << "Nama : "; getline(cin, data[i].nama);
        cout << "Jenis Kelamin : "; getline(cin, data[i].jeniskelamin);
    }
    cout <<endl;

  // Menampilkan nama dan jenis kelamin siswa
  printData(data, n);

  cout << endl;

  // Membuat array indeks siswa yang belum terpilih
  for (int i = 0; i < n; i++) {
    data[i].index = i;
  }

  // Mengacak indeks siswa
  Data temp;
  srand(time(NULL));
  for (int i = n - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    temp = data[i];
    data[i] = data[j];
    data[j] = temp;
  }

  // Membentuk kelompok secara acak
  cout << "Kelompok : \n" << endl ;
  int kelompok = 1;
  for (int i = 0; i < n; i += r) {
    cout << "Kelompok " << kelompok << " :";
    for (int j = i; j < i + r; j++) {
      cout << " " << data[data[j].index].nama;
    }
    cout << endl << endl;
    kelompok++;
  }
  
  return 0;
}
