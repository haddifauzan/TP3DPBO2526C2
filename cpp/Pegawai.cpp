#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// =============================================================================
// Kelas Dasar (Base Class 2): Pegawai
// Berfungsi sebagai induk untuk semua pekerja di kafe.
// Menerapkan konsep Hierarchical Inheritance karena diturunkan menjadi dua
// peran spesifik, yaitu Barista dan Kasir.
// =============================================================================
class Pegawai {
protected:
    // Menggunakan protected agar dapat diakses langsung oleh kelas anak
    string idPegawai;
    string nama;
    string nomorHp;
    double gajiPokok;

public:
    // Konstruktor default
    Pegawai() {
        this->idPegawai = "";
        this->nama = "";
        this->nomorHp = "";
        this->gajiPokok = 0.0;
    }

    // Konstruktor berparameter untuk inisialisasi data pegawai
    Pegawai(string idPegawai, string nama, string nomorHp, double gajiPokok) {
        this->idPegawai = idPegawai;
        this->nama = nama;
        this->nomorHp = nomorHp;
        this->gajiPokok = gajiPokok;
    }

    // Virtual destructor wajib pada kelas dasar agar proses delete
    // pada pointer polimorfik memanggil destructor kelas anak secara tepat.
    virtual ~Pegawai() {}

    // Setter
    void setIdPegawai(string idPegawai) { 
        this->idPegawai = idPegawai; 
    }
    void setNama(string nama) { 
        this->nama = nama; 
    }
    void setNomorHp(string nomorHp) { 
        this->nomorHp = nomorHp; 
    }
    void setGajiPokok(double gajiPokok) { 
        this->gajiPokok = gajiPokok; 
    }

    // Getter
    string getIdPegawai() const { 
        return this->idPegawai; 
    }
    string getNama() const { 
        return this->nama; 
    }
    string getNomorHp() const { 
        return this->nomorHp; 
    }
    double getGajiPokok() const { 
        return this->gajiPokok; 
    }

    // Method virtual untuk menampilkan profil dasar pegawai secara polimorfik
    virtual void tampilkanInfo() const {
        cout << "  [+] ID: " << this->idPegawai << " | " << this->nama << "\n";
        cout << "      ├─ Nomor HP      : " << this->nomorHp << "\n";
        cout << "      └─ Gaji Pokok    : Rp " << fixed << setprecision(0) << this->gajiPokok << "\n";
    }
};
