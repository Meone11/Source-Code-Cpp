#ifndef RELASI_HPP_INCLUDED
#define RELASI_HPP_INCLUDED

#include "Jadwal.hpp"
#include "Pasien.hpp"

void Koneksi(Jadwal* &P, Pasien* &C);

void disconnect(Pasien* &C);

void printRelasiChild(List_Pasien LC, Pasien* C, string tanggal);

void printRelasiChildTanggal(List_Pasien LC, Pasien* C);

void editKoneksi(Jadwal* &P, Pasien* &C);

void deleteParent(List_Jadwal &LP, Jadwal* P);

void findDelete(List_Jadwal &LP, List_Pasien &LC, Jadwal* &P);

#endif