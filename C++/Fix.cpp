#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

#define N 5
using namespace std;

void ShowMenu(char candidates[][50]);
void ShowResult(char candidates[][50], int *results);
int Max (int *arr);

int main()
{
	struct PEKETANG
	{
		char choise;
		int n;
		
	}data[4];
	
	cout << "\t " << endl;
	cout << "\t======================================================================" << endl;
	cout << "\t                     UAS PRAKTIKUM PEMROGRAMAN DASAR" << endl;
	cout << "\t                     VOTING PEMILIHAN KETUA ANGKATAN " << endl;
	cout << "\t              TEKNOLOGI REKAYASA INSTRUMENTASI DAN KONTROL " << endl;
	cout << "\t                             PERIODE 2022 " << endl;
	cout << "\t======================================================================" << endl << endl;
	
	cout << "\tNama Anggota Kelompok : " <<endl;
	cout << "\t1. Salsabilla Humaira 22/506198/SV/22111" <<endl;
	cout << "\t2. Indira Arifa Putri 22/496416/SV/20953" <<endl;
	cout << "\t3. Erika Dyah Tri S.  22/496596/SV/20989" <<endl;
	cout << "\t" << endl;
	cout << "\t======================================================================" << endl;
	
char candidates [N][50]={"", "Tegar Ellhanan R.", "Cakrawala Razzaq", "Dzulkifli Daeng S.", "Wikan Jalu K."};
	cout << "\n \n";
	int results[N]={0};
	while (true)
	{
		
	ShowMenu(candidates);
	cout << "\tPilihan Anda : ";
	cin>>data[N].choise;
	
switch(tolower(data[N].choise))
	{
	case'c':
	cout << "\n\n\t=======================================" << endl;
	cout << "          Ketua Angkatan TRIK 2022 terpilih :  \n" 
	<< "\t\t---"<<candidates[Max(results)]<<"---\t\t\n";
	cout << "\t=======================================" <<endl<<endl;
	cout << "\n";
	break;
	
	case'b':
	cout << "\n\n\t=======================================" << endl;
	cout << "         Hasil Voting Ketua Angkatan TRIK 2022";
	cout << "\n\t=======================================" <<endl<<endl;
	ShowResult(candidates, results);
	break;
	
	case'a':
	cout << "\tMasukkan Nomor Kandidat Ketua : ";
	cin>>data[N].n;
	results [data[N].n]++;
	break;
	
	case'd':
	return 0;
	
	default:
	cout << "\tPilihan Anda Salah ! Harap Diulangi\n\n";
	}
	cout <<endl;
	}
	
	system("cls");
	return 0;
}

void ShowMenu (char candidates[][50])
{
	cout << "\tList Kandidat Ketua Angkatan : \n";
	for (int i=1; i<N; i++)
	{
	cout << "\t"<<i<<". "<<candidates[i]<<endl;
	}
	cout << "\n\n";
	cout << "\tMenu Aplikasi : " << endl;
	cout << "\tA. Menentukan Pilihan" << endl;
	cout << "\tB. Preview Hasil" << endl;
	cout << "\tC. Hasil Perolehan Suara Terbanyak" << endl;
	cout << "\tD. Selesai\n\n" << endl;
}

void ShowResult(char candidates[][50], int *results)
{
	for (int i=1;i<N;i++)
	{
	cout << "\t"<<i<<". "<<candidates[i]<<"\t"<<results[i]<<endl;
	ofstream outfile;
	outfile.open("Voting Kandidat Ketua Angkatan.txt", ios::app);
	outfile<<"\t"<<i<<". "<<candidates[i]<<"\t"<<results[i]<<endl;
	}
	
}

int Max (int *arr)
{
	int max=0;
	for (int i=1; i<N; i++)
	{
	if (arr[i]>arr[max]){
	max=i;}
	
	}
	
return max;

system("cls");
	return(0);
}
