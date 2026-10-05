from item_menu import ItemMenu

# =============================================================================
# Kelas Turunan (Derived Class 2): Minuman
# Mewarisi ItemMenu (Hierarchical Inheritance) dengan kustomisasi minuman:
# varian suhu, ukuran gelas, tingkat kemanisan, jenis susu, shot espresso,
# profil biji kopi (beans), serta aneka topping.
# =============================================================================

class Minuman(ItemMenu):
    def __init__(self, id_item="", nama="", harga=0.0, kategori="Minuman",
                 varian_suhu="", ukuran_gelas="", level_gula="",
                 jenis_susu="", extra_shot_espresso=0, jenis_beans="", topping=None):
        # Memanggil konstruktor kelas induk ItemMenu via super()
        super().__init__(id_item, nama, harga, kategori)
        self._varian_suhu = varian_suhu
        self._ukuran_gelas = ukuran_gelas
        self._level_gula = level_gula
        self._jenis_susu = jenis_susu
        self._extra_shot_espresso = int(extra_shot_espresso)
        self._jenis_beans = jenis_beans
        self._topping = list(topping) if topping is not None else []

    # Setter
    def set_varian_suhu(self, varian_suhu):
        self._varian_suhu = varian_suhu

    def set_ukuran_gelas(self, ukuran_gelas):
        self._ukuran_gelas = ukuran_gelas

    def set_level_gula(self, level_gula):
        self._level_gula = level_gula

    def set_jenis_susu(self, jenis_susu):
        self._jenis_susu = jenis_susu

    def set_extra_shot_espresso(self, extra_shot):
        self._extra_shot_espresso = int(extra_shot)

    def set_jenis_beans(self, jenis_beans):
        self._jenis_beans = jenis_beans

    def set_topping(self, topping):
        self._topping = list(topping) if topping is not None else []

    # Helper untuk menambah topping tunggal
    def tambah_topping(self, item_topping):
        self._topping.append(item_topping)

    # Getter
    def get_varian_suhu(self):
        return self._varian_suhu

    def get_ukuran_gelas(self):
        return self._ukuran_gelas

    def get_level_gula(self):
        return self._level_gula

    def get_jenis_susu(self):
        return self._jenis_susu

    def get_extra_shot_espresso(self):
        return self._extra_shot_espresso

    def get_jenis_beans(self):
        return self._jenis_beans

    def get_topping(self):
        return self._topping

    # Method Overriding: Polimorfisme untuk mencetak kartu info racikan minuman
    def tampilkan_info(self):
        print(f"  [+] ID: {self._id_item} | {self._nama}")
        print(f"      ├─ Kategori      : {self._kategori}")
        print(f"      ├─ Harga         : Rp {int(self._harga)}")
        print(f"      ├─ Varian Suhu   : {self._varian_suhu} | Ukuran: {self._ukuran_gelas} | Gula: {self._level_gula}")
        print(f"      ├─ Racikan Kopi  : Susu: {self._jenis_susu} | Extra Shot: {self._extra_shot_espresso} | Beans: {self._jenis_beans}")
        topping_str = ", ".join(self._topping) if self._topping else "-"
        print(f"      └─ Topping       : {topping_str}")
