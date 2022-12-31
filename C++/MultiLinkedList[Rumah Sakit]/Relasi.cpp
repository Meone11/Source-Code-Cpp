#include <iostream>
using namespace std;

#include "Relasi.hpp"

void Koneksi(Jadwal* &P, Pasien* &C){
    if (P != NULL && C != NULL){
        if (P->kuota_pasien > 0){
            C->parent = P;
            P->kuota_pasien -= 1;
        }else{
            cout << "Anda tidak Bisa membuat jadwal!\n";
        }
    }
}

void disconnect(Pasien* &C){
    if (C != NULL){
        C->parent = NULL;
    }
}

//9. [SHOW] Data Pasien Berdasarkan Tanggal
// void printRelasi(List_Pasien LP, List_Jadwal LC);

//10. [FIND CONNECTION] Data Pasien tertentu & Tanggal Tertentu
void printRelasiChild(List_Pasien LC, Pasien* C, string tanggal){
    C = LC.first;

    while (C != NULL)
    {
        if ((C->parent->tanggal == tanggal) && (C->parent != NULL)){
            cout << "Record ID : " << C->record_id << endl;
            cout << "Nama Pasien : " << C->nama << endl;
            cout << "Jenis Pasien : " << C->jenisPasien << endl;
            cout << "Hasil Pemeriksaan : " << C->hasilpemeriksaan << endl;
            cout << "Biaya Dokter : " << C->biaya_dokter << endl;
            cout << "Biaya Obat : " << C->biaya_obat << endl << endl;
            // break;
        }
        C = C->next;
    }
    
}

////9. [SHOW] Data Pasien Berdasarkan Tanggal
void printRelasiChildTanggal(List_Pasien LC, Pasien* C){
    C = LC.first;
    while(C != NULL)
    {
        if(C->parent != NULL){

            cout << "\nTanggal : " << C->parent->tanggal << endl;
            cout << "Record ID : " << C->record_id << endl;
            cout << "Nama Pasien : " << C->nama << endl;
            cout << "Jenis Pasien : " << C->jenisPasien << endl;
        }

        C = C->next;
    }
    cout <<endl <<endl;
}

//11. [EDIT CONNECTION] Memindahkan Pasien Ke Jadwal yang Baru
void editKoneksi(Jadwal* &P, Pasien* &C){
    
    C->parent = P;

}

void deleteParent(List_Jadwal &LP, Jadwal* P){

    if (P != NULL){
        LP.first = P->next;
        P->next = NULL;
    }

}

// 3. [DELETE] Berdasarkan Nama Dokter & Tanggal
void findDelete(List_Jadwal &LP, List_Pasien &LC, Jadwal* &P)
{
    Pasien* C = LC.first;
    while (C != NULL){
        if ( C->parent == P){
            C->parent = NULL;
        }
        C = C->next;
    }

    deleteParent(LP, P);
    cout <<"Data telah Dihapus!\n";
}