from pegawai import Pegawai

# =============================================================================
# Kelas Turunan (Derived Class 4): Kasir
# Mewarisi Pegawai (Hierarchical Inheritance) dengan atribut pengelolaan kasir:
# nomor terminal mesin POS dan jumlah total transaksi selesai.
# Objek kelas ini juga dipakai sebagai komponen Komposisi pada kelas Kafe.
# =============================================================================

class Kasir(Pegawai):
    def __init__(self, id_pegawai="", nama="", nomor_hp="", gaji_pokok=0.0,
                 nomor_mesin_kasir="", total_transaksi_selesai=0):
        # Memanggil konstruktor kelas induk Pegawai via super()
        super().__init__(id_pegawai, nama, nomor_hp, gaji_pokok)
        self._nomor_mesin_kasir = nomor_mesin_kasir
        self._total_transaksi_selesai = int(total_transaksi_selesai)

    # Setter
    def set_nomor_mesin_kasir(self, nomor_mesin_kasir):
        self._nomor_mesin_kasir = nomor_mesin_kasir

    def set_total_transaksi_selesai(self, total):
        self._total_transaksi_selesai = int(total)

    # Getter
    def get_nomor_mesin_kasir(self):
        return self._nomor_mesin_kasir

    def get_total_transaksi_selesai(self):
        return self._total_transaksi_selesai

    # Method Overriding: Polimorfisme untuk menampilkan kartu informasi staf Kasir
    def tampilkan_info(self):
        print(f"  [+] [KASIR] ID: {self._id_pegawai} | {self._nama}")
        print(f"      ├─ Nomor HP      : {self._nomor_hp}")
        print(f"      ├─ Gaji Pokok    : Rp {int(self._gaji_pokok)}")
        print(f"      ├─ Mesin POS     : {self._nomor_mesin_kasir}")
        print(f"      └─ Transaksi Sls : {self._total_transaksi_selesai} transaksi")
