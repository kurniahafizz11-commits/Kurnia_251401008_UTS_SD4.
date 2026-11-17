// soal 2B
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

int hitungKemunculan(int nilaiCari) {
    int jumlah = 0;
    Node* bantu = head;
    while (bantu != NULL) {
        if (bantu->data == nilaiCari) {
            jumlah++;
        }
        bantu = bantu->next;
    }
    return jumlah;
}

void tambahDepan(int nilai) {
    Node* baru = new Node();
    baru->data = nilai;
    baru->next = head;
    head = baru;
}

void tambahBelakang(int nilai) {
    Node* baru = new Node();
    baru->data = nilai;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
        return;
    }

    Node* bantu = head;
    while (bantu->next != NULL) {
        bantu = bantu->next;
    }
    bantu->next = baru;
}

// 1. Hapus node berdasarkan nilai yang dipilih
void hapusNilai(int nilaiHapus) {
    if (head == NULL) {
        cout << "Linked list masih kosong!" << endl;
        return;
    }

    int total = hitungKemunculan(nilaiHapus);

    if (total == 0) {
        cout << "Nilai " << nilaiHapus << " tidak ditemukan!" << endl;
        return;
    }

    int urutan = 1; // Default urutan ke-1 jika tidak dobel
    if (total > 1) {
        cout << "Ditemukan " << total << " angka " << nilaiHapus << ". Hapus urutan ke berapa: ";
        cin >> urutan;

        if (urutan < 1 || urutan > total) {
            cout << "Urutan tidak valid!" << endl;
            return;
        }
    }

    int hitung = 0;

    // Jika yang dihapus adalah node pertama (head)
    if (head->data == nilaiHapus) {
        hitung++;
        if (hitung == urutan) {
            Node* hapus = head;
            head = head->next;
            delete hapus;
            return;
        }
    }

    // Mencari posisi node yang akan dihapus setelah head
    Node* bantu = head;
    while (bantu->next != NULL) {
        if (bantu->next->data == nilaiHapus) {
            hitung++;
            if (hitung == urutan) {
                Node* hapus = bantu->next;
                bantu->next = hapus->next;
                delete hapus;
                return;
            }
        }
        bantu = bantu->next;
    }
}

// 2. Menampilkan isi linked list
void tampilkanList() {
    Node* bantu = head;
    cout << "Isi Linked List: ";
    while (bantu != NULL) {
        cout << bantu->data << " -> ";
        bantu = bantu->next;
    }
    cout << "NULL" << endl << endl;
}

int main() {
    int jumlahAwal, nilai;
    

    cout << "Masukkan jumlah data awal (misal 10): ";
    cin >> jumlahAwal;

    for (int i = 0; i < jumlahAwal; i++) {
        cout << "Masukkan nilai mahasiswa ke-" << i + 1 << ": ";
        cin >> nilai;
        tambahBelakang(nilai);

    }

    tampilkanList();

    cout << "Masukkan nilai yang ingin DIHAPUS: ";
    cin >> nilai;
    hapusNilai(nilai);
    tampilkanList();    
       
    return 0;
}
