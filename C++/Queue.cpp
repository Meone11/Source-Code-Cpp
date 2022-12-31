#include <iostream>
#include <string>

using namespace std;

const int MAX_QUEUE_SIZE = 100;

struct Data {
  int NIK;
  string Nama;
  string TanggalLahir;
  string StatusPerkawinan;
  string Pekerjaan;
};

struct Queue {
  int front;
  int rear;
  Data data[MAX_QUEUE_SIZE];
};

// Fungsi untuk mengecek apakah antrian sudah penuh atau belum
bool isFull(Queue queue) {
  return queue.rear == MAX_QUEUE_SIZE - 1;
}

// Fungsi untuk mengecek apakah antrian sudah kosong atau belum
bool isEmpty(Queue queue) {
  return queue.front > queue.rear;
}

// Fungsi untuk menambahkan elemen baru ke dalam antrian
void enqueue(Queue &queue, Data data) {
  if (isFull(queue)) {
    cout << "Antrian sudah penuh!" << endl;
    return;
  }

  queue.data[++queue.rear] = data;
}

// Fungsi untuk mengeluarkan elemen pertama dari antrian
void dequeue(Queue &queue) {
  if (isEmpty(queue)) {
    cout << "Antrian sudah kosong!" << endl;
    return;
  }

  queue.front++;
}

// Fungsi untuk menampilkan semua elemen dari antrian
void display(Queue queue) {
  if (isEmpty(queue)) {
    cout << "Antrian kosong!" << endl;
    return;
  }

  cout << "Isi antrian: " << endl;
  for (int i = queue.front; i <= queue.rear; i++) {
    cout << "NIK: " << queue.data[i].NIK << endl;
    cout << "Nama: " << queue.data[i].Nama << endl;
    cout << "Tanggal Lahir: " << queue.data[i].TanggalLahir << endl;
    cout << "Status Perkawinan: " << queue.data[i].StatusPerkawinan << endl;
    cout << "Pekerjaan: " << queue.data[i].Pekerjaan << endl;
    cout << endl;
  }
}

// Fungsi untuk menghapus semua elemen dari antrian
void clear(Queue &queue) {
  queue.front = 0;
  queue.rear = -1;
}

void Menu(){
    cout << "================================"<<endl;
    cout << "==== WELCOME TO SCHOOL HELP ===="<<endl;
    cout << "================================"<<endl;
    cout <<endl;
    cout << "\tMenu Queue" << endl;
    cout << "1. Enqueue Data KTP\n";
    cout << "2. Tampilkan Data KTP\n";
    cout << "3. Dequeue Data KTP\n";
    cout << "4. Hapus Semua Data KTP\n";
    cout << "5. Exit\n";
}

int main() {
    // Inisialisasi antrian
    Queue queue;
    queue.front = 0;
    queue.rear = -1;

    // Data yang akan dimasukkan ke dalam antrian
    Data data;
    
    int jumlah, menu;
    char pilih;
    do
    {
        system("clear");
        Menu();
        cout << "Pilihan : "; cin >> menu;
        switch (menu)
        {
        // Memanggil fungsi enqueue()
        case 1:
            cout << "Masukan Jumlah Data yang ingin diinput : "; cin >> jumlah;
            for (int i = 0; i < jumlah; i++){
                cout << "Masukan NIK : "; cin >> data.NIK;
                cin.ignore();
                cout << "Masukan Name : "; getline(cin, data.Nama);
                cout << "Masukan Date of Birth : "; getline(cin, data.TanggalLahir);
                cout << "Masukan Status Perkawinan : "; getline(cin, data.StatusPerkawinan);
                cout << "Masukan Pekerjaan : "; getline(cin, data.Pekerjaan);

                enqueue(queue, data);
                cout <<endl;
            }
            break;
        // Memanggil fungsi display() untuk menampilkan isi antrian
        case 2:
            display(queue);
            break;
        // Memanggil fungsi dequeue() untuk mengeluarkan elemen pertama dari antrian
        case 3:
            dequeue(queue);
            cout << "Element Awal Berhasil dihapus!!!" <<endl;
            break;
        // Memanggil fungsi clear() untuk menghapus semua elemen dari antrian
        case 4:
            clear(queue);
            cout <<"Data Berhasil Dihapus!" <<endl;
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }

        cout << "\nApakah Kamu Akan Mengulangi Program Ini Kembali? y/n : "; cin >> pilih;
    } while (pilih != 'n' || pilih != 'N');
    
    return 0;
}
