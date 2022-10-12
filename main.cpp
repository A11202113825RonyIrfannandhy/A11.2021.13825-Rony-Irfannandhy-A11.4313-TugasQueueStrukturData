/*
    Nama  : Rony Irfannandhy
    NIM   : A11.2021.13825
    Kelas : A114313
    Note  : Queue (STRUKDATA)
*/

#include <iostream>
#define n 10
using namespace std;

struct antrian{
    string nama;
    int nim;
}antre[n];

struct queue{
    int awal, akhir;
}Queue;

void deQueue();
void menu();
void inQueue();
void tampil();

void init(){
    Queue.awal = -1;
    Queue.akhir = -1;
    cout << " ==================================\n";
    cout << " Data anda berhasil di reset system \n" << endl << endl;
    cout << " ==================================\n";
    menu();
}

bool isFull(){
    if(Queue.akhir == n - 1){
        return true;
    } else {
        return false;
    }
}

bool isEmpty(){
    if(Queue.akhir == -1){
        return true;
    }else {
        return false;
    }
}

void inQueue(){
    if(!isFull()){
        string nama;
        int nim;
        cout << " Masukkan nama Anda : ";
        cin >> nama;
        cout << " Masukkan nomor antrian Anda : ";
        cin >> nim;
        antre[Queue.akhir].nama = nama;
        antre[Queue.akhir].nim = nim;
        ++Queue.akhir;
        cout << endl;
        menu();
    }else {
        cout << " ==================================\n";
        cout << " Data sudah penuh \n";
        cout << " ==================================\n";
        cout << endl;
        menu();
    }
}

void menu(){
    int pilih;
    cout << " ===Pilih menu berikut==\n";
    cout << " 1. masukkan data anda\n";
    cout << " 2. Hapus satu data anda\n";
    cout << " 3. Reset data anda\n";
    cout << " 4. tampilkan data anda keseluruhan\n";
    cout << " =======================\n";
    cout << " Masukkan pilihan anda : ";
    cin >> pilih;
    cout << endl;
    if(pilih == 1){
        inQueue();
    }else if(pilih == 2){
        deQueue();
    } else if(pilih == 3){
        init();
    }else if(pilih == 4){
        tampil();
    }else {
        menu();
    }
}

void deQueue(){
    if(!isEmpty()){
        for(int i = Queue.awal; i < Queue.akhir; i++){
            antre[i].nama = antre[i+1].nama;
            antre[i].nim = antre[i+1].nim;
        }Queue.akhir--;
        cout << " ==================================\n";
        cout << " Data anda berhasil dihapus \n";
        cout << " ==================================\n";
        cout << endl;
        menu();
    }else{
        cout << " Antrian kosong" << endl;
    }
}

void tampil(){
    if(!isEmpty()){
        cout << " ==========Daftar Antrian==========\n";
        for(int i = 0; i < Queue.akhir; i++){
            cout << " Atas nama : " << antre[i].nama << endl;
            cout << " No. antrian : " << antre[i].nim << endl;
        }
        cout << " ==================================\n";
        cout << endl;
    }else {
        cout << " ==================================\n";
        cout << " Data kosong \n";
        cout << " ==================================\n";
        cout << endl;
    }
    menu();
}

int main(){
    menu();

    return 0;
}
