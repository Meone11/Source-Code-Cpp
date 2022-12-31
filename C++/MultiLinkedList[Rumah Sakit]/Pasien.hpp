#ifndef LIST_PASIEN_HPP_INCLUDED
#define LIST_PASIEN_HPP_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#include "Jadwal.hpp"

struct Pasien
{
    int record_id, biaya_dokter, biaya_obat;
    string nama, jenisPasien, hasilpemeriksaan;
    Pasien* next;
    Pasien* prev;
    Jadwal* parent;
};

struct List_Pasien
{
    Pasien* first;
};

void newList(List_Pasien &L);

Pasien *alokasiPasien(int recordID, string nama, string jenisPasien, string hasilPemeriksaan, int biayaDokter, int biayaObat);

void insertFirstParent(List_Pasien &L, Pasien *P);

void insertLast(List_Pasien &L, Pasien* P);

Pasien *findElem(List_Pasien L, int id);

void printPasien(List_Pasien L);

void deletePasien(List_Pasien &L, int id, string nama);

void searchEdit(List_Pasien L, int ID, string nama, string hasil, int biaya_dokter, int biaya_Obat);

void showBiaya(List_Pasien L);

#endif