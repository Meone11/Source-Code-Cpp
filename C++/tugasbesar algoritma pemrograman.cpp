#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int data[16] = {85000,100000,150000,170000,120000,55000,45000,135000,145000,99000,40000,78000,60000,99000,160000,85000};
string barang[16] = {"Kaos","Kemeja","Polo","Jeans","Dres","Blous","Outer","Mukena","Tunik","Hoodie","Daster","Sweater","Boomer","Rok","Jaket","Cardigan"};

    int kode,harga,jumlah,total,bayar,kembalian;
	char mad;
	string user,pass;

	void sorting();

void login(){

     system ("cls");
     
     cout<<"           ====================================================\n";
	 cout<<"           |                   TUGAS BESAR                    |\n";
	 cout<<"           |                    ALGORITMA                     |\n";
	 cout<<"           |                MARKETPLACE PAKAIAN               |\n";
	 cout<<"           ===================================================="<<endl;
	 cout<<endl;
     
	cout<<"=========================================================================="<<endl;
   cout<<"|                        DATA MAHASISWA                                   |"<<endl;
   cout<<"==========================================================================="<<endl;
   cout<<"|       NAMA MAHASISWA          |     Nim       | KELAS |     JURUSAN     |"<<endl;
   cout<<"---------------------------------------------------------------------------"<<endl;
   cout<<"| ADELIA SHINTIA DEWI           | 60900122001   |   A   | SISTEM INFORMASI|"<<endl;
   cout<<"| ANDI MARITZA SYAHRANI IBRAHIM | 60900122022   |   A   | SISTEM INFORMASI|"<<endl;
   cout<<"==========================================================================="<<endl;
   cout<<endl<<endl;

	cout<<"Masukkan Username :";
	cin>>user;
	cout<<"Masukkan Password :";
	cin>>pass;

	if(user == "happy" && pass== "222"){
		cout<<"\n\nPassword dan Username anda cocok\n anda berhasil masuk"<<endl<<endl;
	}

	else{
		cout<<"Gagal masuk,Password atau Username anda salah";
		return login();
	}

	system ("cls");

	cout<<endl;
}

void menu(){
    system("cls");
    
        char pilih2;
        int pilih,penampung;
        string nm;
        bool cek = false;
        
        cout << "|---------------------------|\n";
        cout << "|       MENU TAMBAHAN       |\n";
        cout << "|---------------------------|\n";
        cout << "| 1. Cari Barang            |\n";
        cout << "| 2. Urutkan Barang         |\n";
        cout << "| 3. Keluar                 |\n";
        cout << "|---------------------------|\n";
        cout << " Pilih ==>";
        cin >> pilih;

        switch(pilih){
        	
        case 1:
            do{
            cout << "Masukkan nama barang : ";
            cin >> nm;
            for(int i =0; i <16;i++){
                if(nm == barang[i]){
                    cek = true;
                    penampung = i;
                }
            }
            if(cek == false){
            
                cout << "Barang tidak ada\n";
                menu();
            
            }else{
            	
                cout << "Nama Barang : " << barang[penampung]<<endl;
                cout << "Harga : " << data[penampung]<<endl;
                x:
                cout << "Apakah anda ingin mencari barng lagi ? [Y/N]";
                cin >> pilih2;
                if(pilih2 == 'Y' || pilih2 == 'N'){
                    menu();
                    
                }else{
                    cout << "Masukkan pilihan yang benar!!!\n";
                    goto x;
                    
                }
                }
            
            }while(pilih2 == 'y' || pilih2 == 'Y');
            break;

        case 2:
            sorting();
            break;
            
        case 3:
            cout << "Thank You\n";
            system("pause");
            login();
            break;
            
        default:
            cout << "Masukkan Pilihan yang benar !!!\n";
            system("pause");
            menu();
        }

}

void sorting(){
	
    int pilih;
    system("cls");
    
        cout << "Mengurutkan Barang :\n"
             << "--------------------\n"
             << "1. Urutkan barang dari harga termurah ke harga termahal\n"
             << "2. Urutkan Barang dari harga termahal ke harga termurah\n"
             << "3. Keluar\n"
             << "Pilih ==> ";
        cin >> pilih;
        
        switch(pilih){
        	
        case 1:
        for(int a=0;a<16;a++){
            for(int b=a+1;b<16;b++){
                if(data[a]>data[b]){

                    int x = data[a];
                    data[a] = data[b];
                    data[b] = x;
                }
            }
        }

        cout <<"Barang di urut dari termurah ke termahal : ";
        for(int i = 0;i < 16;i++){
        cout<<i+1<<". "<<barang[i]<<" = "<<data[i]<<" \n";
                }
                break;
                
        case 2:
            for(int a=0;a<16;a++){
            for(int b=a+1;b<16;b++){
                if(data[a]<data[b]){

                    int x = data[a];
                    data[a] = data[b];
                    data[b] = x;
                }
            }
        }

        cout <<"harga di urut dari termahal ke termurah : ";
        for(int i = 0;i < 16;i++){
        cout<<i+1<<". "<<barang[i]<<" = "<<data[i]<<" \n";
        }
        break;
        
        case 3:
            menu();
            break;
            
        default:
            cout << "Masukkan pilihan yang benar !!!\n";
            system("pasue");
            sorting();

}

system("pause");
sorting();

}

void belanja(){
	
	char x[]="----------------SELAMAT DATANG DI MARKETPLACE PAKAIAN------------------";
      	int a,b,i,n;
      	n=strlen(x);

      	for(i=0; i<n; i++){

      	for(a=0; a<99999;a++){
    		for(b=0; b<100; b++){
      		}
      	}
      	printf("%c",x[i]);
      	}

      cout<<endl<<endl;

	do{
    cout<<"=========================================="<<endl;
	cout<<"	MARKETPLACE PAKAIAN	"<<endl;
	cout<<"=========================================="<<endl;
	cout<<"______________"<<endl;
	cout<<"| Kode | Daftar Baju    |  Harga         |"<<endl;
	cout<<"|========================================|"<<endl;
	cout<<"|  1   | Kaos           | Rp. 85.000,-   |"<<endl;
	cout<<"|  2   | Kemeja         | Rp. 100.000,-  |"<<endl;
	cout<<"|  3   | Polo           | Rp. 150.000,-  |"<<endl;
	cout<<"|  4   | Jeans          | Rp. 170.000,-  |"<<endl;
	cout<<"|  5   | Dres           | Rp. 120.000,-  |"<<endl;
	cout<<"|  6   | Blous          | Rp. 55.000,-   |"<<endl;
	cout<<"|  7   | Outer          | Rp. 45.000,-   |"<<endl;
	cout<<"|  8   | Mukena         | Rp. 135.000,-  |"<<endl;
	cout<<"|  9   | Tunik          | Rp. 145.000,-  |"<<endl;
	cout<<"|  10  | Hoodie         | Rp. 99.000,-   |"<<endl;
	cout<<"|  11  | Daster         | Rp. 40.000,-   |"<<endl;
	cout<<"|  12  | Sweater        | Rp. 78.000,-   |"<<endl;
	cout<<"|  13  | Boomer         | Rp. 60.000,-   |"<<endl;
	cout<<"|  14  | Rok            | Rp. 99.000,-   |"<<endl;
	cout<<"|  15  | Jaket          | Rp. 160.000,-  |"<<endl;
	cout<<"|  16  | Cardigan       | Rp. 85.000,-   |"<<endl;
	cout<<"|========================================|"<<endl;
	cout<<"\nMasukkan Kode Pilihan Anda :";
	cin>>kode;

	system ("cls");

	switch(kode){
		case 1:
			cout<<'\n'<<"KAOS"<<endl;
				harga = 85000;
			cout<<"Masukkan Jumlah :";
			cin>>jumlah;
				total = harga*jumlah;
			cout<<"Total Bayar   : Rp. "<<total<<endl;
			cout<<"Dibayar       : Rp. ";
			cin>>bayar;
				kembalian = bayar-total;
			cout<<"Kembalian       : Rp. "<<kembalian<<endl;
			cout<<"Masih ada Y/T :";
			cin>>mad;
			break;

		case 2:
			cout<<'\n'<<"KEMEJA"<<endl;
				harga = 100000;
			cout<<"Masukkan Jumlah :";
			cin>>jumlah;
				total = harga*jumlah;
			cout<<"Total Bayar   : Rp. "<<total<<endl;
			cout<<"Dibayar       : Rp. ";
			cin>>bayar;
				kembalian = bayar-total;
			cout<<"Kembalian     : Rp. "<<kembalian<<endl;
			cout<<"Masih ada Y/T :";
			cin>>mad;
			break;

		case 3:
			cout<<'\n'<<"POLO"<<endl;
				harga = 150000;
			cout<<"Masukkan Jumlah :";
			cin>>jumlah;
				total = harga*jumlah;
			cout<<"Total Bayar   : Rp. "<<total<<endl;
			cout<<"Dibayar       : Rp. ";
			cin>>bayar;
				kembalian = bayar-total;
			cout<<"Kembalian       : Rp. "<<kembalian<<endl;
			cout<<"Masih ada Y/T :";
			cin>>mad;
			break;

		case 4:
			cout<<'\n'<<"JEANS"<<endl;
				harga = 170000;
			cout<<"Masukkan Jumlah :";
			cin>>jumlah;
				total = harga*jumlah;
			cout<<"Total Bayar   : Rp. "<<total<<endl;
			cout<<"Dibayar       : Rp. ";
			cin>>bayar;
				kembalian = bayar-total;
			cout<<"Kembalian       : Rp. "<<kembalian<<endl;
			cout<<"Masih ada Y/T :";
			cin>>mad;
			break;

		case 5:
			cout<<'\n'<<"DRES"<<endl;
				harga = 120000;
			cout<<"Masukkan Jumlah :";
			cin>>jumlah;
				total = harga*jumlah;
			cout<<"Total Bayar   : Rp. "<<total<<endl;
			cout<<"Dibayar       : Rp. ";
			cin>>bayar;
				kembalian = bayar-total;
			cout<<"Kembalian       : Rp. "<<kembalian<<endl;
			cout<<"Masih ada Y/T :";
			cin>>mad;
			break;

		case 6:
			cout<<'\n'<<"BLOUS"<<endl;
				harga = 55000;
			cout<<"Masukkan Jumlah :";
			cin>>jumlah;
				total = harga*jumlah;
			cout<<"Total Bayar   : Rp. "<<total<<endl;
			cout<<"Dibayar       : Rp. ";
			cin>>bayar;
				kembalian = bayar-total;
			cout<<"Kembalian       : Rp. "<<kembalian<<endl;
			cout<<"Masih ada Y/T :";
			cin>>mad;
			break;

		case 7:
			cout<<'\n'<<"OUTER"<<endl;
				harga = 45000;
			cout<<"Masukkan Jumlah :";
			cin>>jumlah;
				total = harga*jumlah;
			cout<<"Total Bayar   : Rp. "<<total<<endl;
			cout<<"Dibayar       : Rp. ";
			cin>>bayar;
				kembalian = bayar-total;
			cout<<"Kembalian       : Rp. "<<kembalian<<endl;
			cout<<"Masih ada Y/T :";
			cin>>mad;
			break;

		case 8:
			cout<<'\n'<<"MUKENA"<<endl;
				harga = 135000;
			cout<<"Masukkan Jumlah :";
			cin>>jumlah;
				total = harga*jumlah;
			cout<<"Total Bayar   : Rp. "<<total<<endl;
			cout<<"Dibayar       : Rp. ";
			cin>>bayar;
				kembalian = bayar-total;
			cout<<"Kembalian       : Rp. "<<kembalian<<endl;
			cout<<"Masih ada Y/T :";
			cin>>mad;
			break;

		case 9:
			cout<<'\n'<<"TUNIK"<<endl;
				harga = 145000;
			cout<<"Masukkan Jumlah :";
			cin>>jumlah;
				total = harga*jumlah;
			cout<<"Total Bayar   : Rp. "<<total<<endl;
			cout<<"Dibayar       : Rp. ";
			cin>>bayar;
				kembalian = bayar-total;
			cout<<"Kembalian       : Rp. "<<kembalian<<endl;
			cout<<"Masih ada Y/T :";
			cin>>mad;
			break;

		case 10:
			cout<<'\n'<<"HOODIE"<<endl;
				harga = 99000;
			cout<<"Masukkan Jumlah :";
			cin>>jumlah;
				total = harga*jumlah;
			cout<<"Total Bayar   : Rp. "<<total<<endl;
			cout<<"Dibayar       : Rp. ";
			cin>>bayar;
				kembalian = bayar-total;
			cout<<"Kembalian       : Rp. "<<kembalian<<endl;
			cout<<"Masih ada Y/T :";
			cin>>mad;
			break;

		case 11:
			cout<<'\n'<<"DASTER"<<endl;
				harga = 40000;
			cout<<"Masukkan Jumlah :";
			cin>>jumlah;
				total = harga*jumlah;
			cout<<"Total Bayar   : Rp. "<<total<<endl;
			cout<<"Dibayar       : Rp. ";
			cin>>bayar;
				kembalian = bayar-total;
			cout<<"Kembalian       : Rp. "<<kembalian<<endl;
			cout<<"Masih ada Y/T :";
			cin>>mad;
			break;

		case 12:
			cout<<'\n'<<"SWEATER"<<endl;
				harga = 78000;
			cout<<"Masukkan Jumlah :";
			cin>>jumlah;
				total = harga*jumlah;
			cout<<"Total Bayar   : Rp. "<<total<<endl;
			cout<<"Dibayar       : Rp. ";
			cin>>bayar;
				kembalian = bayar-total;
			cout<<"Kembalian       : Rp. "<<kembalian<<endl;
			cout<<"Masih ada Y/T :";
			cin>>mad;
			break;

		case 13:
			cout<<'\n'<<"BOOMER"<<endl;
				harga = 60000;
			cout<<"Masukkan Jumlah :";
			cin>>jumlah;
				total = harga*jumlah;
			cout<<"Total Bayar   : Rp. "<<total<<endl;
			cout<<"Dibayar       : Rp. ";
			cin>>bayar;
				kembalian = bayar-total;
			cout<<"Kembalian       : Rp. "<<kembalian<<endl;
			cout<<"Masih ada Y/T :";
			cin>>mad;
			break;

		case 14:
			cout<<'\n'<<"ROK"<<endl;
				harga = 99000;
			cout<<"Masukkan Jumlah :";
			cin>>jumlah;
				total = harga*jumlah;
			cout<<"Total Bayar   : Rp. "<<total<<endl;
			cout<<"Dibayar       : Rp. ";
			cin>>bayar;
				kembalian = bayar-total;
			cout<<"Kembalian       : Rp. "<<kembalian<<endl;
			cout<<"Masih ada Y/T :";
			cin>>mad;
			break;

		case 15:
			cout<<'\n'<<"JAKET"<<endl;
				harga = 160000;
			cout<<"Masukkan Jumlah :";
			cin>>jumlah;
				total = harga*jumlah;
			cout<<"Total Bayar   : Rp. "<<total<<endl;
			cout<<"Dibayar       : Rp. ";
			cin>>bayar;
				kembalian = bayar-total;
			cout<<"Kembalian       : Rp. "<<kembalian<<endl;
			cout<<"Masih ada Y/T :";
			cin>>mad;
			break;

		case 16:
			cout<<'\n'<<"CARDIGAN"<<endl;
				harga = 85000;
			cout<<"Masukkan Jumlah :";
			cin>>jumlah;
				total = harga*jumlah;
			cout<<"Total Bayar   : Rp. "<<total<<endl;
			cout<<"Dibayar       : Rp. ";
			cin>>bayar;
				kembalian = bayar-total;
			cout<<"Kembalian       : Rp. "<<kembalian<<endl;
			cout<<"Masih ada Y/T :";
			cin>>mad;
			break;

		default:
		cout<<"Kode yang anda masukkan tidak ada";
	}
	}while (mad == 'y' );

    system("cls");

	cout<<endl;
	cout<<"-----TERIMAKASIH ATAS KUNJUNGAN ANDA DI MARKETPLACE PAKAIAN KAMI-----\n\n";
	system("pause");

 }

int main (){
    login();
    belanja();
    menu();
    sorting();

}
