// =============================================================================
// Kelas Dasar (Base Class 1): ItemMenu
// Berfungsi sebagai induk untuk semua menu konsumsi di kafe.
// Menerapkan konsep Hierarchical Inheritance karena diturunkan menjadi dua
// kelas anak, yaitu Makanan dan Minuman.
// =============================================================================

public class ItemMenu {
    // Modifier protected memungkinkan atribut ini diakses langsung oleh kelas turunan
    protected String idItem;
    protected String nama;
    protected double harga;
    protected String kategori;

    // Konstruktor default
    public ItemMenu() {
        this.idItem = "";
        this.nama = "";
        this.harga = 0.0;
        this.kategori = "";
    }

    // Konstruktor berparameter untuk inisialisasi data produk menu
    public ItemMenu(String idItem, String nama, double harga, String kategori) {
        this.idItem = idItem;
        this.nama = nama;
        this.harga = harga;
        this.kategori = kategori;
    }

    // Setter
    public void setIdItem(String idItem) {
        this.idItem = idItem;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public void setHarga(double harga) {
        this.harga = harga;
    }

    public void setKategori(String kategori) {
        this.kategori = kategori;
    }

    // Getter
    public String getIdItem() {
        return this.idItem;
    }

    public String getNama() {
        return this.nama;
    }

    public double getHarga() {
        return this.harga;
    }

    public String getKategori() {
        return this.kategori;
    }

    // Method dasar untuk polimorfisme, akan di-override oleh kelas anak (Makanan & Minuman)
    public void tampilkanInfo() {
        System.out.println("  [+] ID: " + this.idItem + " | " + this.nama);
        System.out.println("      ├─ Kategori      : " + this.kategori);
        System.out.println("      └─ Harga         : Rp " + (long) this.harga);
    }
}
