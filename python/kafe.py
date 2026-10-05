from kasir import Kasir
from item_menu import ItemMenu
from pegawai import Pegawai

# =============================================================================
# Kelas Pengelola & Kontainer: Kafe
# Menggabungkan dua konsep OOP utama:
# 1. Komposisi (Composition / strong has-a):
#    Kafe memiliki objek tunggal 'kasir_utama' sebagai penanggung jawab transaksi.
# 2. Agregasi & Array of Objects (Koleksi Polimorfik):
#    Mengelola daftar menu (list of ItemMenu) dan daftar pegawai (list of Pegawai)
#    secara dinamis menggunakan list objek Python.
# =============================================================================

class Kafe:
    def __init__(self, nama_kafe="", alamat="", kasir_utama=None):
        self._nama_kafe = nama_kafe
        self._alamat = alamat
        # Menerapkan konsep Komposisi: menyimpan objek Kasir penanggung jawab
        self._kasir_utama = kasir_utama if kasir_utama is not None else Kasir()
        # Menerapkan konsep Array of Objects: wadah list polimorfik
        self._daftar_menu = []      # Menyimpan objek Makanan & Minuman
        self._daftar_pegawai = []   # Menyimpan objek Barista & Kasir tambahan

    # Setter
    def set_nama_kafe(self, nama_kafe):
        self._nama_kafe = nama_kafe

    def set_alamat(self, alamat):
        self._alamat = alamat

    def set_kasir_utama(self, kasir_utama):
        self._kasir_utama = kasir_utama

    # Getter
    def get_nama_kafe(self):
        return self._nama_kafe

    def get_alamat(self):
        return self._alamat

    def get_kasir_utama(self):
        return self._kasir_utama

    def get_jumlah_menu(self):
        return len(self._daftar_menu)

    def get_jumlah_pegawai(self):
        # Total pegawai = 1 Kasir Utama (komposisi) + staf tambahan di daftar_pegawai
        return 1 + len(self._daftar_pegawai)

    # -------------------------------------------------------------------------
    # Method untuk menambah item menu ke dalam kafe.
    # Berpengaruh pada Flow: Menerima objek Makanan maupun Minuman secara fleksibel
    # lalu menyimpannya ke dalam list daftar_menu (Polimorfisme).
    # -------------------------------------------------------------------------
    def tambah_menu(self, item):
        if item is not None:
            self._daftar_menu.append(item)

    # -------------------------------------------------------------------------
    # Method untuk menambah staf pegawai tambahan ke dalam kafe.
    # Berpengaruh pada Flow: Menerima objek Barista maupun Kasir secara fleksibel
    # lalu menyimpannya ke dalam list daftar_pegawai (Polimorfisme).
    # -------------------------------------------------------------------------
    def tambah_pegawai(self, pegawai):
        if pegawai is not None:
            self._daftar_pegawai.append(pegawai)

    # =========================================================================
    # ALUR UTAMA MENAMPILKAN DATA: tampilkan_kafe_lengkap()
    # Menampilkan profil kafe, kasir utama, katalog menu, dan staf pegawai.
    # Di sini terjadi Polimorfisme: saat item.tampilkan_info() dipanggil,
    # Python otomatis memanggil method milik Makanan atau Minuman yang sesuai.
    # Hal serupa berlaku untuk pegawai.tampilkan_info() (Barista/Kasir).
    # =========================================================================
    def tampilkan_kafe_lengkap(self):
        # Perhitungan spasi rata tengah (center alignment) pada lebar 88 karakter
        pad_nama = max(0, (88 - len(self._nama_kafe)) // 2)
        alamat_str = f"Alamat: {self._alamat}"
        pad_alamat = max(0, (88 - len(alamat_str)) // 2)

        print("=" * 88)
        print(" " * pad_nama + self._nama_kafe)
        print(" " * pad_alamat + alamat_str)
        print("=" * 88 + "\n")

        # 1. Profil Penanggung Jawab Operasional (Komposisi Kafe)
        print("[PENANGGUNG JAWAB OPERASIONAL] (Komposisi Kafe)")
        print(f"  Kasir Utama : {self._kasir_utama.get_nama()} "
              f"(ID: {self._kasir_utama.get_id_pegawai()} | "
              f"Mesin: {self._kasir_utama.get_nomor_mesin_kasir()} | "
              f"Selesai: {self._kasir_utama.get_total_transaksi_selesai()} transaksi)")
        print("-" * 88 + "\n")

        # 2. Daftar Katalog Menu (Polimorfisme dinamis pada Array of Objects)
        print(f"[DAFTAR KATALOG MENU KAFE] (Total: {self.get_jumlah_menu()} Menu)")
        print("-" * 88)
        if not self._daftar_menu:
            print("  (Belum ada item menu yang terdaftar di sistem)")
        else:
            for i, item in enumerate(self._daftar_menu):
                print(f"--- Menu #{i + 1} ---")
                # Pemanggilan method tampilkan_info() secara polimorfik
                item.tampilkan_info()
                if i + 1 < len(self._daftar_menu):
                    print()
        print("-" * 88 + "\n")

        # 3. Daftar Staf Pegawai (Kasir Utama + Koleksi Polimorfik Barista & Kasir)
        print(f"[DAFTAR STAF PEGAWAI KAFE] (Total: {self.get_jumlah_pegawai()} Pegawai)")
        print("-" * 88)
        print("--- Pegawai #1 [Kasir Utama] ---")
        self._kasir_utama.tampilkan_info()
        if self._daftar_pegawai:
            print()
        for i, pegawai in enumerate(self._daftar_pegawai):
            print(f"--- Pegawai #{i + 2} ---")
            # Pemanggilan method tampilkan_info() sesuai tipe staf spesifik
            pegawai.tampilkan_info()
            if i + 1 < len(self._daftar_pegawai):
                print()
        print("=" * 88)
