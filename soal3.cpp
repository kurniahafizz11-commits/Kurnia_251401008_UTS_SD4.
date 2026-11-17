#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

void enqueue(int data) {
    Node* newNode = new Node();
    if (!newNode) { 
        cout << "Queue penuh! (Dynamic Memory Exhausted)" << endl;
        return;
    }
    
    newNode->data = data;
    newNode->next = nullptr;
    
    if (front == nullptr) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode; 
        rear = newNode;       
    }
    cout << "Data " << data << " berhasil masuk ke queue." << endl;
}

void dequeue() {
    if (front == nullptr) {
        cout << "Queue kosong!" << endl;
        return;
    }
    
    Node* temp = front;
    cout << "Data yang di-dequeue: " << front->data << endl;
    
    front = front->next; 
    
    if (front == nullptr) {
        rear = nullptr;
    }
    
    delete temp; 
}

void lihatFront() {
    if (front == nullptr) 
        cout << "Queue kosong!" << endl;
    else 
        cout << "Nilai depan: " << front->data << endl;
}

void lihatrear() {
    if (rear == nullptr)
        cout<<"Queue kosong!"<<endl;
    else
        cout<<"Nilai belakang: "<< rear -> data<<endl;    
}

void cekEmpty() {
    if (front == nullptr) 
        cout << "Queue Empty" << endl;
    else 
        cout << "Queue tidak Empty" << endl;
}

void cekFull() {
    Node* temp = new Node();
    if (temp == nullptr) {
        cout << "Queue Full" << endl;
    } else {
        cout << "Queue belum Full" << endl;
        delete temp;
    }
}

void tampil() {
    if (front == nullptr) {
        cout << "Queue kosong!" << endl;
        return;
    }
    cout << "Isi Queue: ";
    Node* current = front;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int pilihan, nilai;

    do {
        cout << "\n=== MENU QUEUE (LINKED LIST) ===" << endl;
        cout << "1. Menambahkan pelanggan" << endl;
        cout << "2. Menghapus pelanggan" << endl;
        cout << "3. pelanggan depan" << endl;
        cout << "4. Tampilkan Queue" << endl;
        cout << "5. Cek slot kosong" << endl;
        cout << "6. pelanggan belakang" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan angka: ";
                cin >> nilai;
                enqueue(nilai);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                lihatFront();
                break;
            case 4:
                tampil();
                break;
            case 5:
                cekEmpty();
                cekFull();
                cout << "pelanggan yang menunggu: " << front->data << endl;
                break;
            case 6:
                lihatrear();
                break;    
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
