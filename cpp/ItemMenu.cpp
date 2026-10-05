#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// =============================================================================
// Kelas Dasar (Base Class 1): ItemMenu
// Berfungsi sebagai induk untuk semua jenis item yang dijual di kafe.
// Kelas ini menerapkan konsep Hierarchical Inheritance karena diturunkan
// menjadi dua kelas anak, yaitu Makanan dan Minuman.
// =============================================================================
class ItemMenu {
protected:
    // Menggunakan access modifier protected agar atribut umum ini
    // bisa diakses langsung oleh kelas turunannya (Makanan & Minuman)
    string idItem;
    string nama;
    double harga;
    string kategori;

public:
    // Konstruktor default
    ItemMenu() {
        this->idItem = "";
        this->nama = "";
        this->harga = 0.0;
        this->kategori = "";
    }

    // Konstruktor dengan parameter untuk inisialisasi data produk menu
    ItemMenu(string idItem, string nama, double harga, string kategori) {
        this->idItem = idItem;
        this->nama = nama;
        this->harga = harga;
        this->kategori = kategori;
    }

    // Virtual destructor: sangat penting pada konsep OOP Polimorfisme.
    // Memastikan destructor kelas turunan (anak) ikut dieksekusi saat
    // objek dihapus lewat pointer base class (mencegah memory leak).
    virtual ~ItemMenu() {}

    // Setter
    void setIdItem(string idItem) { 
        this->idItem = idItem; 
    }
    void setNama(string nama) { 
        this->nama = nama; 
    }
    void setHarga(double harga) { 
        this->harga = harga; 
    }
    void setKategori(string kategori) { 
        this->kategori = kategori; 
    }

    // Getter
    string getIdItem() const { 
        return this->idItem; 
    }
    string getNama() const { 
        return this->nama; 
    }
    double getHarga() const { 
        return this->harga; 
    }
    string getKategori() const { 
        return this->kategori; 
    }

    // Method virtual untuk Polimorfisme dinamis.
    // Method ini akan di-override oleh kelas Makanan dan Minuman agar
    // masing-masing dapat menampilkan detail atribut spesifiknya.
    virtual void tampilkanInfo() const {
        cout << "  [+] ID: " << this->idItem << " | " << this->nama << "\n";
        cout << "      ├─ Kategori      : " << this->kategori << "\n";
        cout << "      └─ Harga         : Rp " << fixed << setprecision(0) << this->harga << "\n";
    }
};
