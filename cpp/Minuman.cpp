#pragma once

#include "ItemMenu.cpp"
#include <vector>

// =============================================================================
// Kelas Turunan (Derived Class 2): Minuman
// Mewarisi sifat dan atribut dari kelas ItemMenu (Hierarchical Inheritance).
// Menambahkan kustomisasi khas minuman kafe modern seperti suhu, ukuran cup,
// level gula, jenis susu, shot espresso, jenis beans, serta aneka topping.
// =============================================================================
class Minuman : public ItemMenu {
private:
    string varianSuhu;          // Panas (Hot) atau Dingin (Ice)
    string ukuranGelas;         // Regular atau Large
    string levelGula;           // Normal Sweet, Less Sugar, No Sugar
    string jenisSusu;           // Fresh Milk, Oat Milk, Almond Milk, dsb.
    int extraShotEspresso;      // Jumlah tambahan shot espresso
    string jenisBeans;          // Asal profil biji kopi (misal Aceh Gayo)
    vector<string> topping;     // Daftar topping minuman

public:
    // Konstruktor default
    Minuman() : ItemMenu() {
        this->varianSuhu = "";
        this->ukuranGelas = "";
        this->levelGula = "";
        this->jenisSusu = "";
        this->extraShotEspresso = 0;
        this->jenisBeans = "";
    }

    // Konstruktor berparameter:
    // Meneruskan atribut umum ke konstruktor kelas induk ItemMenu,
    // lalu mengisi seluruh atribut kustomisasi racikan minuman.
    Minuman(string idItem, string nama, double harga, string kategori,
            string varianSuhu, string ukuranGelas, string levelGula,
            string jenisSusu, int extraShotEspresso, string jenisBeans,
            vector<string> topping)
        : ItemMenu(idItem, nama, harga, kategori) {
        this->varianSuhu = varianSuhu;
        this->ukuranGelas = ukuranGelas;
        this->levelGula = levelGula;
        this->jenisSusu = jenisSusu;
        this->extraShotEspresso = extraShotEspresso;
        this->jenisBeans = jenisBeans;
        this->topping = topping;
    }

    ~Minuman() override {}

    // Setter
    void setVarianSuhu(string varianSuhu) { 
        this->varianSuhu = varianSuhu; 
    }
    void setUkuranGelas(string ukuranGelas) { 
        this->ukuranGelas = ukuranGelas; 
    }
    void setLevelGula(string levelGula) { 
        this->levelGula = levelGula; 
    }
    void setJenisSusu(string jenisSusu) { 
        this->jenisSusu = jenisSusu; 
    }
    void setExtraShotEspresso(int extraShotEspresso) { 
        this->extraShotEspresso = extraShotEspresso; 
    }
    void setJenisBeans(string jenisBeans) { 
        this->jenisBeans = jenisBeans; 
    }
    void setTopping(vector<string> topping) { 
        this->topping = topping; 
    }

    // Helper untuk menambah topping tunggal ke dalam vector
    void tambahTopping(string toppingItem) {
        this->topping.push_back(toppingItem);
    }

    // Getter
    string getVarianSuhu() const { 
        return this->varianSuhu; 
    }
    string getUkuranGelas() const { 
        return this->ukuranGelas; 
    }
    string getLevelGula() const { 
        return this->levelGula; 
    }
    string getJenisSusu() const { 
        return this->jenisSusu; 
    }
    int getExtraShotEspresso() const { 
        return this->extraShotEspresso; 
    }
    string getJenisBeans() const { 
        return this->jenisBeans; 
    }
    vector<string> getTopping() const { 
        return this->topping; 
    }

    // Override method: Menerapkan polimorfisme untuk mencetak card
    // rincian racikan minuman kafe secara lengkap dan rapi.
    void tampilkanInfo() const override {
        cout << "  [+] ID: " << this->idItem << " | " << this->nama << "\n";
        cout << "      ├─ Kategori      : " << this->kategori << "\n";
        cout << "      ├─ Harga         : Rp " << fixed << setprecision(0) << this->harga << "\n";
        cout << "      ├─ Varian Suhu   : " << this->varianSuhu << " | Ukuran: " << this->ukuranGelas << " | Gula: " << this->levelGula << "\n";
        cout << "      ├─ Racikan Kopi  : Susu: " << this->jenisSusu << " | Extra Shot: " << this->extraShotEspresso << " | Beans: " << this->jenisBeans << "\n";
        cout << "      └─ Topping       : ";
        if (this->topping.empty()) {
            cout << "-\n";
        } else {
            for (size_t i = 0; i < this->topping.size(); ++i) {
                cout << this->topping[i] << (i + 1 < this->topping.size() ? ", " : "\n");
            }
        }
    }
};
