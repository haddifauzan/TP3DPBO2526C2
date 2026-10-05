# =============================================================================
# Kelas Dasar (Base Class 2): Pegawai
# Induk untuk semua pekerja di kafe. Menerapkan konsep Hierarchical
# Inheritance karena diturunkan ke peran spesifik: Barista dan Kasir.
# =============================================================================

class Pegawai:
    def __init__(self, id_pegawai="", nama="", nomor_hp="", gaji_pokok=0.0):
        # Konvensi enkapsulasi atribut protected di Python
        self._id_pegawai = id_pegawai
        self._nama = nama
        self._nomor_hp = nomor_hp
        self._gaji_pokok = float(gaji_pokok)

    # Setter
    def set_id_pegawai(self, id_pegawai):
        self._id_pegawai = id_pegawai

    def set_nama(self, nama):
        self._nama = nama

    def set_nomor_hp(self, nomor_hp):
        self._nomor_hp = nomor_hp

    def set_gaji_pokok(self, gaji_pokok):
        self._gaji_pokok = float(gaji_pokok)

    # Getter
    def get_id_pegawai(self):
        return self._id_pegawai

    def get_nama(self):
        return self._nama

    def get_nomor_hp(self):
        return self._nomor_hp

    def get_gaji_pokok(self):
        return self._gaji_pokok

    # Method dasar yang akan di-override secara polimorfik oleh kelas anak (Barista & Kasir)
    def tampilkan_info(self):
        print(f"  [+] ID: {self._id_pegawai} | {self._nama}")
        print(f"      ├─ Nomor HP      : {self._nomor_hp}")
        print(f"      └─ Gaji Pokok    : Rp {int(self._gaji_pokok)}")
