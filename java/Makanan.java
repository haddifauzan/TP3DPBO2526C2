import java.util.ArrayList;

// =============================================================================
// Kelas Turunan (Derived Class 1): Makanan
// Mewarisi ItemMenu (Hierarchical Inheritance) menggunakan kata kunci 'extends'.
// Menambahkan atribut spesifik untuk hidangan makanan seperti kategori sajian,
// status vegan, opsi pemanasan, dan daftar add-ons pelengkap.
// =============================================================================

public class Makanan extends ItemMenu {
    private String kategoriSajian;      // Contoh: Pastry, Snack, Main Course
    private boolean isVegan;           // Status ramah vegan (true / false)
    private boolean isBisaDihangatkan; // Opsi bisa dihangatkan sebelum disajikan
    private ArrayList<String> addons;  // Daftar topping/pelengkap ekstra

    // Konstruktor default
    public Makanan() {
        super();
        this.kategoriSajian = "";
        this.isVegan = false;
        this.isBisaDihangatkan = false;
        this.addons = new ArrayList<>();
    }

    // Konstruktor berparameter:
    // Memanggil super(idItem, nama, harga, kategori) untuk mengisi atribut kelas induk
    public Makanan(String idItem, String nama, double harga, String kategori,
                   String kategoriSajian, boolean isVegan, boolean isBisaDihangatkan,
                   ArrayList<String> addons) {
        super(idItem, nama, harga, kategori);
        this.kategoriSajian = kategoriSajian;
        this.isVegan = isVegan;
        this.isBisaDihangatkan = isBisaDihangatkan;
        this.addons = (addons != null) ? new ArrayList<>(addons) : new ArrayList<>();
    }

    // Setter
    public void setKategoriSajian(String kategoriSajian) {
        this.kategoriSajian = kategoriSajian;
    }

    public void setIsVegan(boolean isVegan) {
        this.isVegan = isVegan;
    }

    public void setIsBisaDihangatkan(boolean isBisaDihangatkan) {
        this.isBisaDihangatkan = isBisaDihangatkan;
    }

    public void setAddons(ArrayList<String> addons) {
        this.addons = (addons != null) ? new ArrayList<>(addons) : new ArrayList<>();
    }

    // Helper untuk menambah addon tunggal ke dalam ArrayList
    public void tambahAddon(String addon) {
        this.addons.add(addon);
    }

    // Getter
    public String getKategoriSajian() {
        return this.kategoriSajian;
    }

    public boolean getIsVegan() {
        return this.isVegan;
    }

    public boolean getIsBisaDihangatkan() {
        return this.isBisaDihangatkan;
    }

    public ArrayList<String> getAddons() {
        return this.addons;
    }

    // Method Overriding: Polimorfisme untuk mencetak card info hidangan makanan
    @Override
    public void tampilkanInfo() {
        System.out.println("  [+] ID: " + this.idItem + " | " + this.nama);
        System.out.println("      ├─ Kategori      : " + this.kategori + " (" + this.kategoriSajian + ")");
        System.out.println("      ├─ Harga         : Rp " + (long) this.harga);
        System.out.println("      ├─ Karakteristik : " + (this.isVegan ? "Vegan" : "Non-Vegan"));
        System.out.println("      ├─ Dihangatkan   : " + (this.isBisaDihangatkan ? "Ya" : "Tidak"));
        String addonsStr = (this.addons == null || this.addons.isEmpty()) ? "-" : String.join(", ", this.addons);
        System.out.println("      └─ Add-ons       : " + addonsStr);
    }
}
