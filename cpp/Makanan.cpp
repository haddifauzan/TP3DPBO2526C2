#pragma once

#include "ItemMenu.cpp"
#include <vector>

// =============================================================================
// Kelas Turunan (Derived Class 1): Makanan
// Mewarisi sifat dan atribut dari kelas ItemMenu (Hierarchical Inheritance).
// Menambahkan atribut spesifik untuk hidangan makanan seperti sajian, vegan,
// opsi dihangatkan, serta pilihan add-ons pelengkap.
// =============================================================================
class Makanan : public ItemMenu {
private:
    string kategoriSajian;      // Contoh: Pastry, Snack, Main Course
    bool isVegan;               // Status ramah vegan (true / false)
    bool isBisaDihangatkan;     // Status apakah hidangan bisa dihangatkan
    vector<string> addons;      // Daftar topping/pelengkap tambahan

public:
    // Konstruktor default
    Makanan() : ItemMenu() {
        this->kategoriSajian = "";
        this->isVegan = false;
        this->isBisaDihangatkan = false;
    }

    // Konstruktor berparameter:
    // Memanggil konstruktor kelas induk ItemMenu untuk inisialisasi atribut umum,
    // kemudian menginisialisasi atribut spesifik milik kelas Makanan.
    Makanan(string idItem, string nama, double harga, string kategori,
            string kategoriSajian, bool isVegan, bool isBisaDihangatkan,
            vector<string> addons)
        : ItemMenu(idItem, nama, harga, kategori) {
        this->kategoriSajian = kategoriSajian;
        this->isVegan = isVegan;
        this->isBisaDihangatkan = isBisaDihangatkan;
        this->addons = addons;
    }

    ~Makanan() override {}

    // Setter
    void setKategoriSajian(string kategoriSajian) { 
        this->kategoriSajian = kategoriSajian; 
    }
    void setIsVegan(bool isVegan) { 
        this->isVegan = isVegan; 
    }
    void setIsBisaDihangatkan(bool isBisaDihangatkan) { 
        this->isBisaDihangatkan = isBisaDihangatkan; 
    }
    void setAddons(vector<string> addons) { 
        this->addons = addons; 
    }

    // Helper untuk menambah addon tunggal ke dalam vector
    void tambahAddon(string addon) {
        this->addons.push_back(addon);
    }

    // Getter
    string getKategoriSajian() const { 
        return this->kategoriSajian; 
    }
    bool getIsVegan() const { 
        return this->isVegan; 
    }
    bool getIsBisaDihangatkan() const { 
        return this->isBisaDihangatkan; 
    }
    vector<string> getAddons() const { 
        return this->addons; 
    }

    // Override method: Menerapkan polimorfisme untuk menampilkan rincian
    // kartu informasi makanan menggantikan method dasar pada ItemMenu.
    void tampilkanInfo() const override {
        cout << "  [+] ID: " << this->idItem << " | " << this->nama << "\n";
        cout << "      ├─ Kategori      : " << this->kategori << " (" << this->kategoriSajian << ")\n";
        cout << "      ├─ Harga         : Rp " << fixed << setprecision(0) << this->harga << "\n";
        cout << "      ├─ Karakteristik : " << (this->isVegan ? "Vegan" : "Non-Vegan") << "\n";
        cout << "      ├─ Dihangatkan   : " << (this->isBisaDihangatkan ? "Ya" : "Tidak") << "\n";
        cout << "      └─ Add-ons       : ";
        if (this->addons.empty()) {
            cout << "-\n";
        } else {
            for (size_t i = 0; i < this->addons.size(); ++i) {
                cout << this->addons[i] << (i + 1 < this->addons.size() ? ", " : "\n");
            }
        }
    }
};
