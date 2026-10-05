#pragma once

#include "Pegawai.cpp"

// =============================================================================
// Kelas Turunan (Derived Class 3): Barista
// Mewarisi sifat dan atribut dari kelas Pegawai (Hierarchical Inheritance).
// Menambahkan keahlian teknis racik kopi (manual brew, latte art, dsb.)
// dan jadwal pembagian shift kerja di kafe.
// =============================================================================
class Barista : public Pegawai {
private:
    string keahlianUtama;      // Contoh: Latte Art & Manual Brew
    string shiftKerja;         // Pagi (Morning Shift) atau Malam (Night Shift)

public:
    // Konstruktor default
    Barista() : Pegawai() {
        this->keahlianUtama = "";
        this->shiftKerja = "";
    }

    // Konstruktor berparameter:
    // Memanggil konstruktor Pegawai untuk mengisi atribut umum pegawai,
    // lalu mengisi atribut spesifik keahlian dan shift kerja barista.
    Barista(string idPegawai, string nama, string nomorHp, double gajiPokok, string keahlianUtama, string shiftKerja)
        : Pegawai(idPegawai, nama, nomorHp, gajiPokok) {
        this->keahlianUtama = keahlianUtama;
        this->shiftKerja = shiftKerja;
    }

    ~Barista() override {}

    // Setter
    void setKeahlianUtama(string keahlianUtama) { 
        this->keahlianUtama = keahlianUtama; 
    }
    void setShiftKerja(string shiftKerja) { 
        this->shiftKerja = shiftKerja; 
    }

    // Getter
    string getKeahlianUtama() const { 
        return this->keahlianUtama; 
    }
    string getShiftKerja() const { 
        return this->shiftKerja; 
    }

    // Override method: Menerapkan polimorfisme untuk menampilkan card
    // informasi staf barista dengan badge [BARISTA] dan atribut khususnya.
    void tampilkanInfo() const override {
        cout << "  [+] [BARISTA] ID: " << this->idPegawai << " | " << this->nama << "\n";
        cout << "      ├─ Nomor HP      : " << this->nomorHp << "\n";
        cout << "      ├─ Gaji Pokok    : Rp " << fixed << setprecision(0) << this->gajiPokok << "\n";
        cout << "      ├─ Keahlian      : " << this->keahlianUtama << "\n";
        cout << "      └─ Shift Kerja   : " << this->shiftKerja << "\n";
    }
};
