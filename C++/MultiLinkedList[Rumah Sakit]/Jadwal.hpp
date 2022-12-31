#ifndef LIST_JADWAL_HPP_INCLUDED
#define LIST_JADWAL_HPP_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct Jadwal
{
    string tanggal, jam, nama_dokter, spesialisasi;
    int id_Dokter, kuota_pasien;
    Jadwal *next;
};

struct List_Jadwal
{
    Jadwal *first;
};

void newList(List_Jadwal &L);

Jadwal *alokasiParent(string tanggal, string jam, int id, string nama_dokter, string spesialisasi, int kuota_pasien);

void inputJadwal(List_Jadwal &L, Jadwal *P);

void printJadwal(List_Jadwal L);

Jadwal *findElement(List_Jadwal L, int id);

Jadwal *findTanggal(List_Jadwal L, string tanggal);

Jadwal *findDeleteTanggal(List_Jadwal L, string nama, string tanggal);

#endif