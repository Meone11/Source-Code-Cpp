#include "Jadwal.hpp"

void newList(List_Jadwal &L)
{
    L.first = NULL;
}

Jadwal *alokasiParent(string tanggal, string jam, int id, string nama_dokter, string spesialisasi, int kuota_pasien)
{

    Jadwal *J = new Jadwal;

    J->tanggal = tanggal;
    J->jam = jam;
    J->id_Dokter = id;
    J->nama_dokter = nama_dokter;
    J->spesialisasi = spesialisasi;
    J->kuota_pasien = kuota_pasien;
    J->next = NULL;

    return J;
}

// 1. [INSERT] Jadwal Doker
void inputJadwal(List_Jadwal &L, Jadwal *P)
{
    P->next = L.first;
    L.first = P;
}

// 2. [SHOW] Jadwal Dokter
void printJadwal(List_Jadwal L)
{
    Jadwal *P = L.first;

    while (P != NULL)
    {
        cout << "\nTanggal : " << P->tanggal << endl;
        cout << "Jam Kerja : " << P->jam << endl;
        cout << "Id Dokter : " << P->id_Dokter << endl;
        cout << "Nama Dokter : " << P->nama_dokter << endl;
        cout << "Spesialisasi : " << P->spesialisasi << endl;
        cout << "Kuota Pasien : " << P->kuota_pasien << endl;

        P = P->next;
    }
}

//[CONNECT]
Jadwal *findElement(List_Jadwal L, int id)
{
    Jadwal *P = L.first;

    while (P != NULL)
    {
        if (P->id_Dokter == id)
        {
            return P;
            // break;
        }
        P = P->next;
    }
    return NULL;
}

Jadwal *findTanggal(List_Jadwal L, string tanggal)
{
    Jadwal *P = L.first;

    while (P != NULL)
    {
        if (P->tanggal == tanggal)
        {
            return P;
            // break;
        }
        P = P->next;
    }
    return NULL;
}

Jadwal *findDeleteTanggal(List_Jadwal L, string nama, string tanggal)
{
    Jadwal *P = L.first;

    while (P != NULL)
    {
        if ((P->nama_dokter == nama) && (P->tanggal == tanggal))
        {
            return P;
            // break;
        }
        P = P->next;
    }
    return NULL;
}