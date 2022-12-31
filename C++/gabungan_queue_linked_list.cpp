#include<iostream> //input output 
#include<stdio.h> //input output
#include<conio.h> //antarmuka consol
#include<cstdlib>
// #include<windows.h> //fungsi di Windows API
#include<iomanip> //untuk tampilan tabel
using namespace std;

int pil;
//list fungsi
void pilih(int pil);
void addQueue(); //enqueue
void deleteQueue(); //dequeue
void clear(); //clear all
void printQueue(); //tampilan

// Tipe data struct
struct antrean_cafe
{
    string nama;
    string npm; 
	string no_hp;
	string prodi;
	string fak;  
	int no_antri;
    antrean_cafe *next;
};

int max_queue=5;
antrean_cafe *head, *tail, *current, *hapus, *newNode;

//clearscreen
// void clrscr(){
// 	system("cls");
// }

// main fungsi
int main()
{
    do{
	system("clear");
	cout<<"\n====================================================================";
	cout<<"\n  UAS - Program Kombinasi Queue dan Linked List  ";
	cout<<"\n====================================================================";
	cout<<endl<<endl;
	
	cout<<"===== MENU ANTRIAN PENGAMBILAN KTM ====="<<endl; //QUEUE LINKEDLIST 
	cout<<"---------------------------------"<<endl;
    cout<<"|1. Tambah Antrian              |"<<endl;
	cout<<"|2. Hapus Antrian               |"<<endl;
	cout<<"|3. Lihat Antrian               |"<<endl;
    cout<<"|4. Hapus Semua Antrian         |"<<endl;
	cout<<"|5. Selesai                     |"<<endl;
	cout<<"================================="<<endl;
	cout<<"\nPilihan Anda        : ";
	cin>>pil;
	
	pilih(pil);
	}while (pil!=5);
	return 0;
}

void pilih(int pil)
{
	if(pil==1){
	addQueue();
	}
    else if(pil==2){
	deleteQueue();
	}
    else if(pil==3){
	printQueue();
	}
	else if(pil==4){
	clear();
	}
}

// Menghitung jumlah antrian
int count()
{
	if(head==NULL){
    return 0;
	}else{
    int jumlah = 0;
    current = head;
   		while(current!=NULL){
		current = current->next;
		jumlah++;
    }
    return jumlah;
	}
}

// Mengecek apakah antrian penuh?
bool isFull(){
	if(count()==max_queue){
    return true;
	}else{
    return false;
	}
}

// Mengecek apakah antrian kosong?
bool isEmpty(){
	if(count() == 0){
    return true;
	}else{
    return false;
	}
}

// Fungsi Enqueue
void addQueue(){
	if(isFull()){
    cout<<"Mohon maaf antrian sudah penuh"<<endl;
	}
		else{
		if(isEmpty()){
		head=new antrean_cafe();
		cin.ignore();
		cout<<"Masukkan Nama       : ";
		getline(cin,head->nama);
		cout<<"Masukkan NPM        : ";
		getline(cin,head->npm);
		cout<<"Masukkan Nomor HP   : ";
		getline(cin,head->no_hp);
		cout<<"Masukkan Prodi      : ";
		getline(cin,head->prodi);
		cout<<"Masukkan Fakultas   : ";
		getline(cin,head->fak);
		cout<<"Masukkan No Antrian : ";
		cin>>head->no_antri;
		
		head->next=NULL;
		tail=head;
		printQueue();
		}else{
		newNode=new antrean_cafe();
		cin.ignore();
		cout<<"Masukkan Nama       : ";
		getline(cin,head->nama);
		cout<<"Masukkan NPM        : ";
		getline(cin,head->npm);
		cout<<"Masukkan Nomor HP   : ";
		getline(cin,head->no_hp);
		cout<<"Masukkan Prodi       : ";
		getline(cin,head->prodi);
		cout<<"Masukkan Fakultas       : ";
		getline(cin,head->fak);
		cout<<"Masukkan No Antrian : ";
		cin>>head->no_antri;
		newNode->next=NULL;
		tail->next=newNode;
		tail=newNode;
		printQueue();
    }
  }
}

// Fungsi Dequeue
void deleteQueue(){
	if(isEmpty()){
    cout<<"\nAntrian masih kosong"<<endl;
	}else{
		hapus=head;
    	head=head->next;
		hapus->next=NULL;
    	delete hapus;
  }
  printQueue();
}

// Fungsi Menghapus semua antrian
void clear(){
	if(isEmpty()){
    cout<<"Antrian masih kosong"<<endl;
	}else{
    current=head;
    	while(current!=NULL){
		hapus=current;
		current=current->next;
		hapus->next=NULL;
		delete hapus;
    }
    head = NULL;
    tail = NULL;
  }
}

// Fungsi tampilkan antrian
void printQueue()
{
	system("clear");
	cout<<"\n List Antrian Pengambilan KTM: "<<endl;
	if(isEmpty()){
    cout<<"Antrian masih kosong"<<endl;
	}else{
		current=head;
		int nomor=1;
		cout<<"-----------------------------------------------------------------\n";
 		cout<<"|  No  |           NPM           |           No Antrian           |\n";
 		cout<<"-----------------------------------------------------------------";
	
		while(nomor<=max_queue){
			if(current!=NULL){			
				cout<<"\n| "<<setiosflags(ios::left)<<setw(5)<<nomor<<"|";
  				cout<<" "<<setiosflags(ios::left)<<setw(25)<<current->npm<<"|";
  				cout<<" "<<setiosflags(ios::left)<<setw(28)<<current->no_antri<<"|";
			current=current->next;
				}else{
				cout<<"\n| "<<setiosflags(ios::left)<<setw(5)<<nomor<<"|";
  				cout<<" "<<setiosflags(ios::left)<<setw(25)<<"Data masih kosong"<<"|";
  				cout<<" "<<setiosflags(ios::left)<<setw(28)<<"Data masih kosong"<<"|";
      			}
				

	nomor++;
    	}
		cout<<"\n=================================================================\n";
	}
	getche();
}
