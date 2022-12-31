#include <iostream>

using namespace std;

int main()
{
    // menu
    cout << "| ============================================ |" << endl;
    cout << "|             Kalkulator Sederhana             |" << endl;
    cout << "| ============================================ |" << endl;
    cout << "---------------||||||||||||||||---------------" << endl;
    cout << "INI ADALAH PROGRAM ARRAY untuk KALKULATOR SEDERHANA" << endl;
    cout << "PILIHAN KALKULATOR :" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "3. Perkalian" << endl;
    cout << "4. Pembagian" << endl;
    cout << "5. Faktorial" << endl;
    cout << "0. EXIT PROGRAM" << endl;
    cout << "---------------||||||||||||||||---------------" << endl;

    int a, b, pilihan, hasil, angka, i;
    double hasilPembagian;

    // meminta user untuk memasukan pilihan operasi
    cout << "Masukkan pilihan operasi : ";
    cin >> pilihan;
    if (pilihan == 1)
    {
        cout << "Ini Program Penjumlahan" << endl;
        cout << "Masukkan angka pertama: ";
        cin >> a;
        cout << "Masukkan angka kedua: ";
        cin >> b;
        hasil = a + b;
        cout << "Hasil dari " << a << " + " << b << " = " << hasil << endl;
    }
    else if (pilihan == 2)
    {
        cout << "Ini Program Pengurangan" << endl;
        cout << "Masukkan angka pertama: ";
        cin >> a;
        cout << "Masukkan angka kedua: ";
        cin >> b;
        hasil = a - b;
        cout << "Hasil dari " << a << " - " << b << " = " << hasil << endl;
    }
    else if (pilihan == 3)
    {
        cout << "Ini Program Perkalian " << endl;
        cout << "Masukkan angka pertama: ";
        cin >> a;
        cout << "Masukkan angka kedua: ";
        cin >> b;
        hasil = a * b;
        cout << "Hasil dari " << a << " * " << b << " = " << hasil << endl;
    }
    else if (pilihan == 4)
    {
        cout << "Ini Program Pembagian " << endl;
        cout << "Masukkan nilai pertama: ";
        cin >> a;
        cout << "Masukkan nilai kedua: ";
        cin >> b;
        hasilPembagian = (double)a / b;
        cout << "Hasil dari " << a << " / " << b << " = " << hasilPembagian << endl;
    }
    else if (pilihan == 5)
    {
        cout << "Ini Program Faktorial" << endl;
        cout << "Masukkan nilai: ";
        cin >> angka;
        hasil = 1;
        for (i = 1; i <= angka; i++)
        {
            hasil = hasil * i;
        }
        cout << "Hasil dari " << angka << " ! = " << hasil << endl;
    }
    else if (pilihan == 6)
    {
        cout << "Terima Kasih Telah Menggunakan Program Kalkulator Sederhana" << endl;
    }
    else
    {
        cout << "Maaf, pilihan yang anda masukkan salah" << endl;
    }
    return 0;
}
