import sys
import io

# Memastikan output terminal menggunakan encoding UTF-8 agar karakter box-drawing (├─, └─) tampil rapi
if sys.stdout.encoding != 'utf-8':
    try:
        sys.stdout.reconfigure(encoding='utf-8')
    except (AttributeError, io.UnsupportedOperation):
        pass

from kafe import Kafe
from kasir import Kasir
from barista import Barista
from makanan import Makanan
from minuman import Minuman


def main():
    # =========================================================================
    # ALUR 1: Inisialisasi Objek Utama & Menerapkan Konsep KOMPOSISI
    # - Kasir utama dibuat terlebih dahulu sebagai penanggung jawab kafe.
    # - Objek 'kasir_utama' diserahkan ke dalam constructor objek 'kafe'.
    # - Ini menerapkan KOMPOSISI: Kafe memiliki relasi kepemilikan kuat
    #   terhadap kasir utama (kasir utama hidup sebagai bagian dari kafe).
    # =========================================================================
    kasir_utama = Kasir("KSR-01", "Ujang Kedu", "0812-3456-7890", 4200000.0, "POS-01", 125)
    kafe = Kafe("Pitong Coffee & Eatery", "Jl. Sanca No. 76, Cimahi", kasir_utama)

    # =========================================================================
    # ALUR 2: Mengisi Data Awal Kafe (ARRAY OF OBJECTS & POLIMORFISME)
    # - Objek Makanan dan Minuman dimasukkan ke dalam wadah list daftar_menu.
    # - Objek Barista dan Kasir dimasukkan ke dalam wadah list daftar_pegawai.
    # - Ini membuktikan konsep Polimorfisme: satu koleksi dapat menampung
    #   berbagai objek kelas turunan secara fleksibel.
    # =========================================================================
    
    # Menambahkan 2 makanan awal
    kafe.tambah_menu(Makanan(
        "MK-01", "Croissant Butter", 28000.0, "Makanan",
        "Pastry", False, True,
        ["Extra Salted Butter", "Selai Cokelat"]
    ))
    kafe.tambah_menu(Makanan(
        "MK-02", "Truffle French Fries", 32000.0, "Makanan",
        "Snack", True, False,
        ["Saus Tartar", "Bubuk Nori"]
    ))

    # Menambahkan 2 minuman awal
    kafe.tambah_menu(Minuman(
        "MN-01", "Caramel Macchiato", 38000.0, "Minuman",
        "Dingin (Ice)", "Regular", "Less Sugar",
        "Oat Milk", 1, "Arabica Single Origin Aceh Gayo",
        ["Whipped Cream", "Caramel Drizzle"]
    ))
    kafe.tambah_menu(Minuman(
        "MN-02", "Matcha Green Tea Latte", 35000.0, "Minuman",
        "Panas (Hot)", "Large", "Normal Sweet",
        "Fresh Milk", 0, "-",
        ["Matcha Powder Dusting"]
    ))

    # Menambahkan 3 staf tambahan (2 Barista + 1 Kasir)
    # Catatan: Kasir utama sudah otomatis tercatat sebagai Pegawai #1 via Komposisi
    kafe.tambah_pegawai(Barista(
        "BAR-01", "Fajar Nugraha", "0813-9876-5432", 4500000.0,
        "Latte Art & Manual Brew", "Pagi (Morning Shift)"
    ))
    kafe.tambah_pegawai(Barista(
        "BAR-02", "Dimas Prasetyo", "0821-5566-7788", 4300000.0,
        "Cold Brew & Roasting", "Malam (Night Shift)"
    ))
    kafe.tambah_pegawai(Kasir(
        "KSR-02", "Siti Aminah", "0819-1122-3344", 4000000.0,
        "POS-02", 38
    ))

    # =========================================================================
    # ALUR 3: Menampilkan Seluruh Data Kafe Sebelum Ada Penambahan
    # Memanggil method tampilkan_kafe_lengkap() yang mencetak info kafe,
    # kasir utama, katalog 4 menu, dan 4 staf pegawai (1 kasir utama + 3 staf).
    # Di dalamnya, method tampilkan_info() dipanggil secara polimorfik.
    # =========================================================================
    print("\n============================ >> SEBELUM DATA DITAMBAHKAN << ============================\n")
    kafe.tampilkan_kafe_lengkap()

    # =========================================================================
    # ALUR 4: Proses Penambahan Data Baru Secara Dinamis
    # Membuktikan bahwa sistem dapat menambahkan objek baru ke objek 'kafe'
    # yang sedang berjalan:
    # - 1 Menu Makanan baru (Spaghetti Aglio Olio - MK-03)
    # - 1 Menu Minuman baru (Signature Cold Brew Float - MN-03)
    # - 1 Staf Barista baru (Alya Safira - BAR-03)
    # =========================================================================
    print("\n\n" + ">" * 24 + " PROSES PENAMBAHAN DATA BARU KE KAFE " + "<" * 25)
    
    # 1. Tambah makanan baru
    print("[+] Menambahkan 1 Makanan Baru : Spaghetti Aglio Olio (MK-03)")
    kafe.tambah_menu(Makanan(
        "MK-03", "Spaghetti Aglio Olio", 45000.0, "Makanan",
        "Main Course", False, True,
        ["Extra Keju Parmesan", "Telor Ceplok"]
    ))

    # 2. Tambah minuman baru
    print("[+] Menambahkan 1 Minuman Baru : Signature Cold Brew Float (MN-03)")
    kafe.tambah_menu(Minuman(
        "MN-03", "Signature Cold Brew Float", 40000.0, "Minuman",
        "Dingin (Ice)", "Large", "Less Sugar",
        "-", 0, "House Blend Flores Bajawa",
        ["Vanilla Ice Cream Scoop"]
    ))

    # 3. Tambah barista baru
    print("[+] Menambahkan 1 Barista Baru : Alya Safira (BAR-03)")
    kafe.tambah_pegawai(Barista(
        "BAR-03", "Alya Safira", "0857-1234-5678", 4400000.0,
        "Espresso Extraction & Cupping", "Pagi (Morning Shift)"
    ))
    print("-" * 88)
    print("Penambahan data sukses diproses!\n")

    # =========================================================================
    # ALUR 5: Menampilkan Seluruh Data Kafe Sesudah Penambahan
    # Memanggil kembali method tampilkan_kafe_lengkap().
    # Hasil cetakan membuktikan bahwa data bertambah secara dinamis:
    # - Total menu bertambah dari 4 menjadi 6 menu.
    # - Total staf bertambah dari 4 menjadi 5 staf pegawai.
    # =========================================================================
    print("============================ >> SESUDAH DATA DITAMBAHKAN << ============================\n")
    kafe.tampilkan_kafe_lengkap()


if __name__ == "__main__":
    main()
