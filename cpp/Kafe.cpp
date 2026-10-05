#pragma once

#include "ItemMenu.cpp"
#include "Makanan.cpp"
#include "Minuman.cpp"
#include "Pegawai.cpp"
#include "Barista.cpp"
#include "Kasir.cpp"
#include <vector>

// =============================================================================
// Kelas Pengelola & Kontainer: Kafe
// Merupakan kelas sentral sistem yang menggabungkan dua konsep OOP penting:
// 1. Komposisi (Composition / strong has-a):
//    Kafe memiliki objek tunggal 'kasirUtama' yang merekatkan identitas
//    operasional transaksi kafe (hidup dan mati bersama objek Kafe).
// 2. Agregasi & Array of Objects (Koleksi Polimorfik):
//    Mengelola daftar menu (vector<ItemMenu*>) dan daftar pegawai (vector<Pegawai*>)
//    secara dinamis, di mana pointer base class dapat menampung objek turunan apa pun.
// =============================================================================
class Kafe {
private:
    string namaKafe;
    string alamat;
    Kasir kasirUtama;                  // Komposisi: Objek Kasir utama penanggung jawab
    vector<ItemMenu*> daftarMenu;      // Array of Objects: Koleksi menu polimorfik
    vector<Pegawai*> daftarPegawai;    // Array of Objects: Koleksi staf polimorfik

public:
    // Konstruktor default
    Kafe() {
        this->namaKafe = "";
        this->alamat = "";
    }

    // Konstruktor berparameter: menerima nama kafe, alamat, dan objek kasir utama (Komposisi)
    Kafe(string namaKafe, string alamat, Kasir kasirUtama) {
        this->namaKafe = namaKafe;
        this->alamat = alamat;
        this->kasirUtama = kasirUtama;
    }

    // Destructor: Sangat penting dalam manajemen memori C++.
    // Bertanggung jawab membebaskan (delete) seluruh objek heap polimorfik
    // yang disimpan di dalam vector pointer guna mencegah kebocoran memori (memory leak).
    ~Kafe() {
        for (auto* item : this->daftarMenu) {
            delete item;
        }
        this->daftarMenu.clear();

        for (auto* pegawai : this->daftarPegawai) {
            delete pegawai;
        }
        this->daftarPegawai.clear();
    }

    // Mencegah duplikasi objek (shallow copy) untuk menghindari bug double-free pointer
    Kafe(const Kafe&) = delete;
    Kafe& operator=(const Kafe&) = delete;

    // Setter
    void setNamaKafe(string namaKafe) { 
        this->namaKafe = namaKafe; 
    }
    void setAlamat(string alamat) { 
        this->alamat = alamat; 
    }
    void setKasirUtama(Kasir kasirUtama) { 
        this->kasirUtama = kasirUtama; 
    }

    // Getter
    string getNamaKafe() const { 
        return this->namaKafe; 
    }
    string getAlamat() const { 
        return this->alamat; 
    }
    Kasir getKasirUtama() const { 
        return this->kasirUtama; 
    }
    int getJumlahMenu() const { 
        return static_cast<int>(this->daftarMenu.size()); 
    }
    // Total pegawai dihitung dari 1 kasir utama (komposisi) + seluruh staf tambahan di array
    int getJumlahPegawai() const { 
        return 1 + static_cast<int>(this->daftarPegawai.size()); 
    }

    // -------------------------------------------------------------------------
    // Method untuk menambah item menu ke dalam kafe.
    // Berpengaruh pada Flow: Menerima pointer ItemMenu* (kelas induk) sehingga
    // bisa menerima objek Makanan maupun Minuman secara fleksibel (Polimorfisme).
    // -------------------------------------------------------------------------
    void tambahMenu(ItemMenu* item) {
        if (item != nullptr) {
            this->daftarMenu.push_back(item);
        }
    }

    // -------------------------------------------------------------------------
    // Method untuk menambah staf pegawai tambahan ke dalam kafe.
    // Berpengaruh pada Flow: Menerima pointer Pegawai* (kelas induk) sehingga
    // bisa menerima objek Barista maupun Kasir (Polimorfisme).
    // -------------------------------------------------------------------------
    void tambahPegawai(Pegawai* pegawai) {
        if (pegawai != nullptr) {
            this->daftarPegawai.push_back(pegawai);
        }
    }

    // =========================================================================
    // ALUR UTAMA MENAMPILKAN DATA: tampilkanKafeLengkap()
    // Menampilkan profil kafe, kasir utama, katalog menu, dan staf pegawai.
    // Di sini terjadi Polimorfisme: saat daftarMenu[i]->tampilkanInfo() dipanggil,
    // program otomatis memanggil method milik Makanan atau Minuman yang sesuai.
    // Hal serupa berlaku untuk daftarPegawai[i]->tampilkanInfo() (Barista/Kasir).
    // =========================================================================
    void tampilkanKafeLengkap() const {
        // Menghitung spasi agar nama kafe dan alamat tercetak rata tengah (center alignment)
        int padNama = max(0, (88 - (int)this->namaKafe.length()) / 2);
        string alamatStr = "Alamat: " + this->alamat;
        int padAlamat = max(0, (88 - (int)alamatStr.length()) / 2);

        cout << "========================================================================================\n";
        cout << string(padNama, ' ') << this->namaKafe << "\n";
        cout << string(padAlamat, ' ') << alamatStr << "\n";
        cout << "========================================================================================\n\n";
        
        // 1. Profil Penanggung Jawab Operasional (Komposisi Kafe)
        cout << "[PENANGGUNG JAWAB OPERASIONAL] (Komposisi Kafe)\n";
        cout << "  Kasir Utama : " << this->kasirUtama.getNama()
             << " (ID: " << this->kasirUtama.getIdPegawai()
             << " | Mesin: " << this->kasirUtama.getNomorMesinKasir()
             << " | Selesai: " << this->kasirUtama.getTotalTransaksiSelesai() << " transaksi)\n";
        cout << "----------------------------------------------------------------------------------------\n\n";

        // 2. Daftar Katalog Menu (Polimorfisme dinamis pada Array of Objects)
        cout << "[DAFTAR KATALOG MENU KAFE] (Total: " << this->getJumlahMenu() << " Menu)\n";
        cout << "----------------------------------------------------------------------------------------\n";
        if (this->daftarMenu.empty()) {
            cout << "  (Belum ada item menu yang terdaftar di sistem)\n";
        } else {
            for (size_t i = 0; i < this->daftarMenu.size(); ++i) {
                cout << "--- Menu #" << (i + 1) << " ---\n";
                // Pemanggilan virtual method tampilkanInfo() secara polimorfik
                this->daftarMenu[i]->tampilkanInfo();
                if (i + 1 < this->daftarMenu.size()) {
                    cout << "\n";
                }
            }
        }
        cout << "----------------------------------------------------------------------------------------\n\n";

        // 3. Daftar Staf Pegawai (Kasir Utama + Koleksi Polimorfik Barista & Kasir tambahan)
        cout << "[DAFTAR STAF PEGAWAI KAFE] (Total: " << this->getJumlahPegawai() << " Pegawai)\n";
        cout << "----------------------------------------------------------------------------------------\n";
        cout << "--- Pegawai #1 [Kasir Utama] ---\n";
        this->kasirUtama.tampilkanInfo();
        if (!this->daftarPegawai.empty()) {
            cout << "\n";
        }
        for (size_t i = 0; i < this->daftarPegawai.size(); ++i) {
            cout << "--- Pegawai #" << (i + 2) << " ---\n";
            // Pemanggilan virtual method tampilkanInfo() sesuai peran spesifik staf
            this->daftarPegawai[i]->tampilkanInfo();
            if (i + 1 < this->daftarPegawai.size()) {
                cout << "\n";
            }
        }
        cout << "========================================================================================\n";
    }
};
