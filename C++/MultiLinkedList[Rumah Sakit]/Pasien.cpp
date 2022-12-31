#include "Pasien.hpp"

void newList(List_Pasien &L){
    L.first = NULL;
}

Pasien *alokasiPasien(int recordID, string nama, string jenisPasien, string hasilPemeriksaan, int biayaDokter, int biayaObat)
{
    Pasien* P = new Pasien;

    P->record_id = recordID;
    P->nama = nama;
    P->jenisPasien = jenisPasien;
    P->hasilpemeriksaan = hasilPemeriksaan;
    P->biaya_dokter = biayaDokter;
    P->biaya_obat = biayaObat;
    P->next = NULL;
    P->parent = NULL;

    return P;
}

//4. [INSERT][CONNECT n/y] Data pasien
void insertFirstParent(List_Pasien &L, Pasien *P)
{
    P->next = L.first;
    L.first = P;
}

void insertLast(List_Pasien &L, Pasien* P){
    if (L.first == NULL){
        L.first = P;
        P->prev = NULL;
        P->next = NULL;
    }else{
        Pasien* Last = L.first;
        while (Last->next != NULL){
            Last = Last->next;
        }

        Last->next = P;
        P->prev = Last;
        P->next = NULL;
    }
}

Pasien *findElem(List_Pasien L, int id)
{
    Pasien *C = L.first;

    while (C != NULL)
    {
        if (C->record_id == id)
        {
            return C;
            // break
        }
        C = C->next;
    }
    return NULL;
}

//5. [SHOW] Data Pasien
void printPasien(List_Pasien L)
{
    Pasien *P = L.first;
    while (P != NULL)
    {
        if (P->parent != NULL){
            cout << "Record ID : " << P->record_id << endl;
            cout << "Nama Pasien : " << P->nama << endl;
            cout << "Jenis Pasien : " << P->jenisPasien << endl;
            cout << "Hasil Pemeriksaan : " << P->hasilpemeriksaan << endl;
            cout << "Biaya Dokter : " << P->biaya_dokter<< endl;
            cout << "Biaya Obat : " << P->biaya_obat<< endl<<endl; 
        }
        P = P->next;
    }
}

//6. [DELETE] Data Pasien Berdasarkan ID & Nama Pasien
void deletePasien(List_Pasien &L, int id, string nama){
    Pasien *P = L.first;
    Pasien* temp = NULL;
    while (P != NULL)
    {
        if ((P->record_id == id) && (P->nama == nama))
        {
            break;
        }
        temp = P;
        P = P->next;
    }

    if (P == NULL) {
        return;
    }

    if (P == L.first){
        L.first = P->next;
    }else{
        temp->next = P->next;
    }

    delete P;
    cout << "Data berhasil Dihapus!\n";
}

//7. [SEARCH][EDIT] Mengeluarkan Hasil Pemeriksaan Pasien
void searchEdit(List_Pasien L, int ID, string nama, string hasil, int biaya_dokter, int biaya_Obat){
    Pasien* P = L.first;

    while (P != NULL)
    {
        if ((P->record_id == ID) && (P->nama == nama))
        {
            P->hasilpemeriksaan= hasil;
            P->biaya_dokter = biaya_dokter;
            P->biaya_obat = biaya_Obat;  
            break;
        }
        P = P->next;
    }

    if (P == L.first){
        return;
    }

    
}

//8. [SHOW][EDIT] Biaya Pengobatan Pasien
void showBiaya(List_Pasien L){
    Pasien* P = L.first;

    while (P != NULL)
    {

        if ((P->jenisPasien == "BPJS") && (P->parent != NULL))
        {
            if (P->biaya_dokter > 500000)
            {
                P->biaya_dokter -= 500000;
            }
            cout << "Record ID : " << P->record_id << endl;
            cout << "Nama Pasien : " << P->nama << endl;
            cout << "Jenis Pasien : " << P->jenisPasien << endl;
            cout << "Hasil Pemeriksaan : " << P->hasilpemeriksaan << endl;
            cout << "Biaya Dokter : " << P->biaya_dokter << endl;
            cout << "Biaya Obat : " << P->biaya_obat << endl << endl;
        }else if (P->parent != NULL){
            cout << "Record ID : " << P->record_id << endl;
            cout << "Nama Pasien : " << P->nama << endl;
            cout << "Jenis Pasien : " << P->jenisPasien << endl;
            cout << "Hasil Pemeriksaan : " << P->hasilpemeriksaan << endl;
            cout << "Biaya Dokter : " << P->biaya_dokter << endl;
            cout << "Biaya Obat : " << P->biaya_obat << endl << endl;
        }
        P = P->next;
    }

    if (P == L.first){
        return;
    }
}