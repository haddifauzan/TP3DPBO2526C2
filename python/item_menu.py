# =============================================================================
# Kelas Dasar (Base Class 1): ItemMenu
# Induk untuk semua menu konsumsi di kafe. Menerapkan konsep Hierarchical
# Inheritance karena diturunkan ke kelas Makanan dan Minuman.
# =============================================================================

class ItemMenu:
    def __init__(self, id_item="", nama="", harga=0.0, kategori=""):
        # Menggunakan prefix underscore (_) sebagai konvensi protected/private di Python
        self._id_item = id_item
        self._nama = nama
        self._harga = float(harga)
        self._kategori = kategori

    # Setter
    def set_id_item(self, id_item):
        self._id_item = id_item

    def set_nama(self, nama):
        self._nama = nama

    def set_harga(self, harga):
        self._harga = float(harga)

    def set_kategori(self, kategori):
        self._kategori = kategori

    # Getter
    def get_id_item(self):
        return self._id_item

    def get_nama(self):
        return self._nama

    def get_harga(self):
        return self._harga

    def get_kategori(self):
        return self._kategori

    # Method dasar yang akan di-override secara polimorfik oleh kelas anak (Makanan & Minuman)
    def tampilkan_info(self):
        print(f"  [+] ID: {self._id_item} | {self._nama}")
        print(f"      ├─ Kategori      : {self._kategori}")
        print(f"      └─ Harga         : Rp {int(self._harga)}")
