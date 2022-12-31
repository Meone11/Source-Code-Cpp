#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#include "Jadwal.hpp"
#include "Pasien.hpp"
#include "Relasi.hpp"

void Menu(){
    cout << "=========================================\n";
    cout << "       Welcome to Hospital Program       \n";
    cout << "=========================================\n";
    cout << "1. [INSERT] Jadwal Dokter\n";
    cout << "2. [SHOW] Jadwal Dokter\n";
    cout << "3. [DELETE] Berdasarkan Nama Dokter & Tanggal\n";
    cout << "4. [INSERT][CONNECT] Data pasien\n";
    cout << "5. [SHOW] Data Pasien\n";
    cout << "6. [DELETE] Data Pasien Berdasarkan ID & Nama Pasien\n";
    cout << "7. [SEARCH][EDIT] Mengeluarkan Hasil Pemeriksaan Pasien\n";
    cout << "8. [SHOW][EDIT] Biaya Pengobatan Pasien\n";
    cout << "9. [SHOW] Data Pasien Berdasarkan Tanggal\n";
    cout << "10. [FIND CONNECTION] Data Pasien tertentu & Tanggal Tertentu\n";
    cout << "11. [EDIT CONNECTION] Memindahkan Pasien Ke Jadwal yang Baru\n";
}

List_Jadwal LP;
List_Pasien LC;

int main(){
    Jadwal* J;
    Pasien* C;

    newList(LP);
    newList(LC);

    //variabel insert;
    string tanggal, jam, nama_dokter, spesialisasi;
    int id_Dokter, kuota_pasien;
    string deletenama, deleteTanggal;

    //Varibel Pasien
    int id, biayaDokter, biayaObat, idDokter, hapusID, ID;
    string nama, jenisPasien, hasil_Pemeriksaan, hapusNama, editNama;
    string hasil, tanggalRelasi, tanggalKoneksi;
    int biaya_dokter, biaya_Obat;
    
    //Varibel untuk ubah jadwal
    int idpasien;
    string tanggalLama, tanggalBaru;

    //variabel menu
    int menu, data, dataPasien;
    char keluar;

    do
    {
        system("clear");
        Menu();
        cout << "Pilihan : "; cin >> menu;

        switch (menu)
        {
        case 1:
            cout << "Masukan Banyak Jadwal Dokter : "; cin >> data;
            for (int i = 0; i < data ; i++){
                cin.ignore();
                cout << "Input Tanggal : "; getline(cin, tanggal);
                cout << "Input Jam (start - end) : ";getline(cin, jam);
                cout << "Input ID Dokter : "; cin >> id_Dokter;cin.ignore();
                cout << "Input Nama Dokter : "; getline(cin, nama_dokter);
                cout << "Input Spesialisasi Dokter : "; getline(cin, spesialisasi);
                cout << "Input Kuota Pasien Dokter : "; cin >> kuota_pasien;

                inputJadwal(LP, alokasiParent(tanggal, jam, id_Dokter, nama_dokter, spesialisasi, kuota_pasien));
                cout << endl;
            }
            break;
        case 2:
            cout <<"List Jadwal Dokter : \n";
            printJadwal(LP);
            break;
        case 3:
            cin.ignore();
            cout << "Masukan Nama yang ingin di hapus : "; getline(cin, deletenama);
            cout << "Masukan Tanggal yang ingin di Hapus : "; getline(cin, deleteTanggal);
            J = findDeleteTanggal(LP, deletenama, deleteTanggal);
            findDelete(LP, LC, J);
            break;
        case 4:
            cout << "masukan Banyak Data Pasien : "; cin >> dataPasien;
            cout << "\n Buat Jadwal Dengan Dokter : \n";
            printJadwal(LP);
            for (int i = 0; i < dataPasien; i++){
                // cin.ignore();
                cout << "\nInput Record ID : ";cin >> id;cin.ignore();
                cout << "Input Nama Pasien : ";getline(cin, nama);
                cout << "Input Jenis Pasien : "; getline(cin, jenisPasien);
                // cout << "Input Nama Dokter : "; getline(cin, nama_dokter);
                // cout << "Input Spesialisasi Dokter : "; getline(cin, spesialisasi);
                // cout << "Input Kuota Pasien Dokter : "; cin >> kuota_pasien;
                
                insertFirstParent(LC, alokasiPasien(id, nama, jenisPasien, " ", 0, 0));
                cout << "Masukan ID Dokter yang ingin anda Buat jadwal : "; cin >> idDokter;
                J = findElement(LP, idDokter);
                C = findElem(LC, id);
                Koneksi(J, C);

            }
            break;
        case 5:
            cout << "Data Pasien : \n";
            printPasien(LC);
            break;
        case 6:
            cout << "Masukan ID yang ingin di hapus : "; cin >> hapusID;
            cin.ignore();
            cout << "Masukan Nama yang ingin di Hapus : "; getline(cin, hapusNama);
            deletePasien(LC, hapusID, hapusNama);
            break;
        case 7:
            cout << "Masukan Id Pasien : "; cin >> ID;
            cin.ignore();
            cout << "Masukan Nama Pasien : "; getline(cin, editNama);
            cout << "Masukan Hasil Pemeriksaan : "; getline(cin, hasil);
            cout << "Masukan Biaya Pemeriksaan : Rp.";cin >> biaya_dokter;
            cout << "Masukan Biaya Obat : Rp.";cin >> biaya_Obat;

            searchEdit(LC, ID, editNama, hasil, biaya_dokter, biaya_Obat);
            break;
        case 8:
            cout << "Data Biaya Pasien : \n";
            showBiaya(LC);
            break;
        case 9:
            printRelasiChildTanggal(LC, C);
            break;
        case 10:
            cin.ignore();
            cout << "Masukan Tanggal Yang ingin Anda Cari : "; getline(cin, tanggalRelasi);
            printRelasiChild(LC, C, tanggalRelasi);
            break;
        case 11:
            cout << "Masukan Id Pasien yang Akan dipindahkan : ";cin >> idpasien;
            cin.ignore();
            cout << "Masukan Tanggal Jadwal yang Lama : ";getline(cin, tanggalLama);
            cout << "Masukan Tanggal yang jadwal Baru : ";getline(cin, tanggalBaru);
            C = findElem(LC, idpasien);
            J = findTanggal(LP, tanggalBaru);
            editKoneksi(J, C);
            break;
        
        default:
            break;
        }

        cout << "Ingin Menjalankan Program kembali? (y/n) : "; cin >> keluar;
    } while (keluar == 'y' || keluar == 'Y');
}