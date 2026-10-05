#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include "Kafe.cpp"

int main() {
    // Mengaktifkan encoding UTF-8 pada terminal Windows agar karakter box-drawing (├─, └─) tampil rapi
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    // =========================================================================
    // ALUR 1: Inisialisasi Objek Utama & Menerapkan Konsep KOMPOSISI
    // - Kasir utama dibuat terlebih dahulu sebagai penanggung jawab kafe.
    // - Objek 'kasirUtama' kemudian diserahkan ke dalam objek 'kafe'.
    // - Ini adalah konsep KOMPOSISI: Kafe memiliki hubungan kepemilikan kuat
    //   terhadap kasir utama (kasir utama menjadi bagian integral dari kafe).
    // =========================================================================
    Kasir kasirUtama("KSR-01", "Ujang Kedu", "0812-3456-7890", 4200000.0, "POS-01", 125);
    Kafe kafe("Ciplusplus Coffee & Eatery", "Jl. Cimimin No. 67, Cimahi", kasirUtama);

    // =========================================================================
    // ALUR 2: Mengisi Data Awal Kafe (ARRAY OF OBJECTS & POLIMORFISME)
    // - Objek turunan Makanan dan Minuman dimasukkan ke wadah yang sama (daftarMenu)
    //   menggunakan tipe pointer kelas induk (ItemMenu*).
    // - Objek turunan Barista dan Kasir dimasukkan ke wadah daftarPegawai
    //   menggunakan tipe pointer kelas induk (Pegawai*).
    // - Ini membuktikan konsep Polimorfisme: satu tipe induk dapat menampung
    //   berbagai bentuk kelas turunannya secara dinamis.
    // =========================================================================
    
    // Menambahkan 2 makanan awal
    kafe.tambahMenu(new Makanan(
        "MK-01", "Croissant Butter", 28000.0, "Makanan",
        "Pastry", false, true,
        {"Extra Salted Butter", "Selai Cokelat"}
    ));
    kafe.tambahMenu(new Makanan(
        "MK-02", "Truffle French Fries", 32000.0, "Makanan",
        "Snack", true, false,
        {"Saus Tartar", "Bubuk Nori"}
    ));

    // Menambahkan 2 minuman awal
    kafe.tambahMenu(new Minuman(
        "MN-01", "Caramel Macchiato", 38000.0, "Minuman",
        "Dingin (Ice)", "Regular", "Less Sugar",
        "Oat Milk", 1, "Arabica Single Origin Aceh Gayo",
        {"Whipped Cream", "Caramel Drizzle"}
    ));
    kafe.tambahMenu(new Minuman(
        "MN-02", "Matcha Green Tea Latte", 35000.0, "Minuman",
        "Panas (Hot)", "Large", "Normal Sweet",
        "Fresh Milk", 0, "-",
        {"Matcha Powder Dusting"}
    ));

    // Menambahkan 3 staf tambahan (2 Barista + 1 Kasir)
    // Catatan: Kasir utama sudah tersimpan sebagai pegawai #1 via Komposisi
    kafe.tambahPegawai(new Barista(
        "BAR-01", "Fajar Nugraha", "0813-9876-5432", 4500000.0,
        "Latte Art & Manual Brew", "Pagi (Morning Shift)"
    ));
    kafe.tambahPegawai(new Barista(
        "BAR-02", "Dimas Prasetyo", "0821-5566-7788", 4300000.0,
        "Cold Brew & Roasting", "Malam (Night Shift)"
    ));
    kafe.tambahPegawai(new Kasir(
        "KSR-02", "Siti Aminah", "0819-1122-3344", 4000000.0,
        "POS-02", 38
    ));

    // =========================================================================
    // ALUR 3: Menampilkan Seluruh Data Kafe Sebelum Ada Penambahan
    // Memanggil method tampilkanKafeLengkap() yang akan mencetak data kafe,
    // kasir utama, daftar 4 menu, dan daftar 4 staf (1 kasir utama + 3 staf).
    // Di dalamnya, method tampilkanInfo() dipanggil secara polimorfik.
    // =========================================================================
    cout << "\n";
    cout << "============================ >> SEBELUM DATA DITAMBAHKAN << ============================\n\n";
    kafe.tampilkanKafeLengkap();

    // =========================================================================
    // ALUR 4: Proses Penambahan Data Baru Secara Dinamis
    // Membuktikan bahwa sistem dapat menambahkan objek baru ke objek 'kafe'
    // yang sedang berjalan:
    // - 1 Menu Makanan baru (Spaghetti Aglio Olio - MK-03)
    // - 1 Menu Minuman baru (Signature Cold Brew Float - MN-03)
    // - 1 Staf Barista baru (Alya Safira - BAR-03)
    // =========================================================================
    cout << "\n\n";
    cout << ">>>>>>>>>>>>>>>>>>>>>>>> PROSES PENAMBAHAN DATA BARU KE KAFE <<<<<<<<<<<<<<<<<<<<<<<<<\n";
    
    // 1. Tambah makanan baru
    cout << "[+] Menambahkan 1 Makanan Baru : Spaghetti Aglio Olio (MK-03)\n";
    kafe.tambahMenu(new Makanan(
        "MK-03", "Spaghetti Aglio Olio", 45000.0, "Makanan",
        "Main Course", false, true,
        {"Extra Keju Parmesan", "Telor Ceplok"}
    ));

    // 2. Tambah minuman baru
    cout << "[+] Menambahkan 1 Minuman Baru : Signature Cold Brew Float (MN-03)\n";
    kafe.tambahMenu(new Minuman(
        "MN-03", "Signature Cold Brew Float", 40000.0, "Minuman",
        "Dingin (Ice)", "Large", "Less Sugar",
        "-", 0, "House Blend Flores Bajawa",
        {"Vanilla Ice Cream Scoop"}
    ));

    // 3. Tambah barista baru
    cout << "[+] Menambahkan 1 Barista Baru : Alya Safira (BAR-03)\n";
    kafe.tambahPegawai(new Barista(
        "BAR-03", "Alya Safira", "0857-1234-5678", 4400000.0,
        "Espresso Extraction & Cupping", "Pagi (Morning Shift)"
    ));
    cout << "----------------------------------------------------------------------------------------\n";
    cout << "Penambahan data sukses diproses!\n\n";

    // =========================================================================
    // ALUR 5: Menampilkan Seluruh Data Kafe Sesudah Penambahan
    // Memanggil kembali method tampilkanKafeLengkap().
    // Hasil cetakan membuktikan data bertambah secara dinamis:
    // - Total menu bertambah dari 4 menjadi 6 menu.
    // - Total staf bertambah dari 4 menjadi 5 staf pegawai.
    // =========================================================================
    cout << "============================ >> SESUDAH DATA DITAMBAHKAN << ============================\n\n";
    kafe.tampilkanKafeLengkap();

    // Saat fungsi main selesai, destructor Kafe otomatis dipanggil
    // untuk menghapus seluruh objek heap guna mencegah kebocoran memori (memory leak).
    return 0;
}
