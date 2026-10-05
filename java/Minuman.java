import java.util.ArrayList;

// =============================================================================
// Kelas Turunan (Derived Class 2): Minuman
// Mewarisi ItemMenu (Hierarchical Inheritance) menggunakan kata kunci 'extends'.
// Menambahkan kustomisasi sajian minuman seperti suhu, ukuran cup, level gula,
// jenis susu, shot espresso, jenis beans, serta aneka pilihan topping.
// =============================================================================

public class Minuman extends ItemMenu {
    private String varianSuhu;          // Panas (Hot) atau Dingin (Ice)
    private String ukuranGelas;         // Regular atau Large
    private String levelGula;           // Normal Sweet, Less Sugar, No Sugar
    private String jenisSusu;           // Fresh Milk, Oat Milk, Almond Milk, dsb.
    private int extraShotEspresso;      // Jumlah tambahan shot espresso
    private String jenisBeans;          // Asal profil biji kopi (misal Aceh Gayo)
    private ArrayList<String> topping;  // Daftar topping minuman

    // Konstruktor default
    public Minuman() {
        super();
        this.varianSuhu = "";
        this.ukuranGelas = "";
        this.levelGula = "";
        this.jenisSusu = "";
        this.extraShotEspresso = 0;
        this.jenisBeans = "";
        this.topping = new ArrayList<>();
    }

    // Konstruktor berparameter:
    // Memanggil super(idItem, nama, harga, kategori) untuk mengisi atribut kelas induk
    public Minuman(String idItem, String nama, double harga, String kategori,
                   String varianSuhu, String ukuranGelas, String levelGula,
                   String jenisSusu, int extraShotEspresso, String jenisBeans,
                   ArrayList<String> topping) {
        super(idItem, nama, harga, kategori);
        this.varianSuhu = varianSuhu;
        this.ukuranGelas = ukuranGelas;
        this.levelGula = levelGula;
        this.jenisSusu = jenisSusu;
        this.extraShotEspresso = extraShotEspresso;
        this.jenisBeans = jenisBeans;
        this.topping = (topping != null) ? new ArrayList<>(topping) : new ArrayList<>();
    }

    // Setter
    public void setVarianSuhu(String varianSuhu) {
        this.varianSuhu = varianSuhu;
    }

    public void setUkuranGelas(String ukuranGelas) {
        this.ukuranGelas = ukuranGelas;
    }

    public void setLevelGula(String levelGula) {
        this.levelGula = levelGula;
    }

    public void setJenisSusu(String jenisSusu) {
        this.jenisSusu = jenisSusu;
    }

    public void setExtraShotEspresso(int extraShotEspresso) {
        this.extraShotEspresso = extraShotEspresso;
    }

    public void setJenisBeans(String jenisBeans) {
        this.jenisBeans = jenisBeans;
    }

    public void setTopping(ArrayList<String> topping) {
        this.topping = (topping != null) ? new ArrayList<>(topping) : new ArrayList<>();
    }

    // Helper untuk menambah topping tunggal ke dalam ArrayList
    public void tambahTopping(String itemTopping) {
        this.topping.add(itemTopping);
    }

    // Getter
    public String getVarianSuhu() {
        return this.varianSuhu;
    }

    public String getUkuranGelas() {
        return this.ukuranGelas;
    }

    public String getLevelGula() {
        return this.levelGula;
    }

    public String getJenisSusu() {
        return this.jenisSusu;
    }

    public int getExtraShotEspresso() {
        return this.extraShotEspresso;
    }

    public String getJenisBeans() {
        return this.jenisBeans;
    }

    public ArrayList<String> getTopping() {
        return this.topping;
    }

    // Method Overriding: Polimorfisme untuk mencetak card info racikan minuman
    @Override
    public void tampilkanInfo() {
        System.out.println("  [+] ID: " + this.idItem + " | " + this.nama);
        System.out.println("      ├─ Kategori      : " + this.kategori);
        System.out.println("      ├─ Harga         : Rp " + (long) this.harga);
        System.out.println("      ├─ Varian Suhu   : " + this.varianSuhu + " | Ukuran: " + this.ukuranGelas + " | Gula: " + this.levelGula);
        System.out.println("      ├─ Racikan Kopi  : Susu: " + this.jenisSusu + " | Extra Shot: " + this.extraShotEspresso + " | Beans: " + this.jenisBeans);
        String toppingStr = (this.topping == null || this.topping.isEmpty()) ? "-" : String.join(", ", this.topping);
        System.out.println("      └─ Topping       : " + toppingStr);
    }
}
