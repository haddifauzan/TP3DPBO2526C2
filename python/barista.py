from pegawai import Pegawai

# =============================================================================
# Kelas Turunan (Derived Class 3): Barista
# Mewarisi Pegawai (Hierarchical Inheritance) dengan atribut keahlian khusus
# racik seduh kopi (manual brew, latte art, cupping) dan jadwal shift kerja.
# =============================================================================

class Barista(Pegawai):
    def __init__(self, id_pegawai="", nama="", nomor_hp="", gaji_pokok=0.0,
                 keahlian_utama="", shift_kerja=""):
        # Memanggil konstruktor kelas induk Pegawai via super()
        super().__init__(id_pegawai, nama, nomor_hp, gaji_pokok)
        self._keahlian_utama = keahlian_utama
        self._shift_kerja = shift_kerja

    # Setter
    def set_keahlian_utama(self, keahlian_utama):
        self._keahlian_utama = keahlian_utama

    def set_shift_kerja(self, shift_kerja):
        self._shift_kerja = shift_kerja

    # Getter
    def get_keahlian_utama(self):
        return self._keahlian_utama

    def get_shift_kerja(self):
        return self._shift_kerja

    # Method Overriding: Polimorfisme untuk menampilkan kartu informasi staf Barista
    def tampilkan_info(self):
        print(f"  [+] [BARISTA] ID: {self._id_pegawai} | {self._nama}")
        print(f"      ├─ Nomor HP      : {self._nomor_hp}")
        print(f"      ├─ Gaji Pokok    : Rp {int(self._gaji_pokok)}")
        print(f"      ├─ Keahlian      : {self._keahlian_utama}")
        print(f"      └─ Shift Kerja   : {self._shift_kerja}")
