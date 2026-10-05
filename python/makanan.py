from item_menu import ItemMenu

# =============================================================================
# Kelas Turunan (Derived Class 1): Makanan
# Mewarisi ItemMenu (Hierarchical Inheritance) dengan atribut hidangan makanan:
# kategori sajian (Pastry/Snack/Main Course), status vegan, opsi pemanasan,
# dan daftar add-ons pelengkap makanan.
# =============================================================================

class Makanan(ItemMenu):
    def __init__(self, id_item="", nama="", harga=0.0, kategori="Makanan",
                 kategori_sajian="", is_vegan=False, is_bisa_dihangatkan=False, addons=None):
        # Memanggil konstruktor kelas induk ItemMenu via super()
        super().__init__(id_item, nama, harga, kategori)
        self._kategori_sajian = kategori_sajian
        self._is_vegan = is_vegan
        self._is_bisa_dihangatkan = is_bisa_dihangatkan
        self._addons = list(addons) if addons is not None else []

    # Setter
    def set_kategori_sajian(self, kategori_sajian):
        self._kategori_sajian = kategori_sajian

    def set_is_vegan(self, is_vegan):
        self._is_vegan = is_vegan

    def set_is_bisa_dihangatkan(self, is_bisa_dihangatkan):
        self._is_bisa_dihangatkan = is_bisa_dihangatkan

    def set_addons(self, addons):
        self._addons = list(addons) if addons is not None else []

    # Helper untuk menambah addon tunggal
    def tambah_addon(self, addon):
        self._addons.append(addon)

    # Getter
    def get_kategori_sajian(self):
        return self._kategori_sajian

    def get_is_vegan(self):
        return self._is_vegan

    def get_is_bisa_dihangatkan(self):
        return self._is_bisa_dihangatkan

    def get_addons(self):
        return self._addons

    # Method Overriding: Polimorfisme untuk mencetak kartu info makanan
    def tampilkan_info(self):
        print(f"  [+] ID: {self._id_item} | {self._nama}")
        print(f"      ├─ Kategori      : {self._kategori} ({self._kategori_sajian})")
        print(f"      ├─ Harga         : Rp {int(self._harga)}")
        print(f"      ├─ Karakteristik : {'Vegan' if self._is_vegan else 'Non-Vegan'}")
        print(f"      ├─ Dihangatkan   : {'Ya' if self._is_bisa_dihangatkan else 'Tidak'}")
        addons_str = ", ".join(self._addons) if self._addons else "-"
        print(f"      └─ Add-ons       : {addons_str}")
