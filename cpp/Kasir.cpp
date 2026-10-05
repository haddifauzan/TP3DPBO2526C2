#pragma once

#include "Pegawai.cpp"

// =============================================================================
// Kelas Turunan (Derived Class 4): Kasir
// Mewarisi sifat dan atribut dari kelas Pegawai (Hierarchical Inheritance).
// Menambahkan data spesifik pengelolaan transaksi seperti nomor mesin kasir POS
// dan riwayat jumlah transaksi yang sukses diselesaikan.
// Kelas ini juga digunakan sebagai objek Komposisi di dalam kelas Kafe.
// =============================================================================
class Kasir : public Pegawai {
private:
    string nomorMesinKasir;       // Contoh: POS-01, POS-02
    int totalTransaksiSelesai;    // Jumlah struk transaksi yang berhasil ditangani

public:
    // Konstruktor default
    Kasir() : Pegawai() {
        this->nomorMesinKasir = "";
        this->totalTransaksiSelesai = 0;
    }

    // Konstruktor berparameter:
    // Meneruskan atribut pegawai ke kelas induk Pegawai, lalu mengisi atribut mesin & transaksi.
    Kasir(string idPegawai, string nama, string nomorHp, double gajiPokok,
          string nomorMesinKasir, int totalTransaksiSelesai)
        : Pegawai(idPegawai, nama, nomorHp, gajiPokok) {
        this->nomorMesinKasir = nomorMesinKasir;
        this->totalTransaksiSelesai = totalTransaksiSelesai;
    }

    ~Kasir() override {}

    // Setter
    void setNomorMesinKasir(string nomorMesinKasir) { 
        this->nomorMesinKasir = nomorMesinKasir; 
    }
    void setTotalTransaksiSelesai(int total) { 
        this->totalTransaksiSelesai = total; 
    }

    // Getter
    string getNomorMesinKasir() const { 
        return this->nomorMesinKasir; 
    }
    int getTotalTransaksiSelesai() const { 
        return this->totalTransaksiSelesai; 
    }

    // Override method: Menerapkan polimorfisme untuk menampilkan card
    // informasi kasir dengan badge [KASIR], nomor mesin POS, dan total transaksi.
    void tampilkanInfo() const override {
        cout << "  [+] [KASIR] ID: " << this->idPegawai << " | " << this->nama << "\n";
        cout << "      ├─ Nomor HP      : " << this->nomorHp << "\n";
        cout << "      ├─ Gaji Pokok    : Rp " << fixed << setprecision(0) << this->gajiPokok << "\n";
        cout << "      ├─ Mesin POS     : " << this->nomorMesinKasir << "\n";
        cout << "      └─ Transaksi Sls : " << this->totalTransaksiSelesai << " transaksi\n";
    }
};
