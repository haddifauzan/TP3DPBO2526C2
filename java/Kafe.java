import java.util.ArrayList;

// =============================================================================
// Kelas Pengelola & Kontainer: Kafe
// Merupakan kelas sentral sistem yang menggabungkan dua konsep OOP utama:
// 1. Komposisi (Composition / strong has-a):
//    Kafe memiliki objek tunggal 'kasirUtama' yang merekatkan identitas
//    operasional transaksi kafe (siklus hidup terkait langsung dengan Kafe).
// 2. Agregasi & Array of Objects (Koleksi Polimorfik):
//    Mengelola daftar menu (ArrayList<ItemMenu>) dan daftar pegawai (ArrayList<Pegawai>)
//    secara dinamis, di mana referensi kelas induk menampung ragam objek turunan.
// =============================================================================

public class Kafe {
    private String namaKafe;
    private String alamat;
    private Kasir kasirUtama;                     // Komposisi: Objek Kasir penanggung jawab utama
    private ArrayList<ItemMenu> daftarMenu;       // Array of Objects: Koleksi menu polimorfik
    private ArrayList<Pegawai> daftarPegawai;     // Array of Objects: Koleksi staf polimorfik

    // Konstruktor default
    public Kafe() {
        this.namaKafe = "";
        this.alamat = "";
        this.kasirUtama = new Kasir();
        this.daftarMenu = new ArrayList<>();
        this.daftarPegawai = new ArrayList<>();
    }

    // Konstruktor berparameter: menerima nama kafe, alamat, dan objek kasirUtama (Komposisi)
    public Kafe(String namaKafe, String alamat, Kasir kasirUtama) {
        this.namaKafe = namaKafe;
        this.alamat = alamat;
        this.kasirUtama = (kasirUtama != null) ? kasirUtama : new Kasir();
        this.daftarMenu = new ArrayList<>();
        this.daftarPegawai = new ArrayList<>();
    }

    // Setter
    public void setNamaKafe(String namaKafe) {
        this.namaKafe = namaKafe;
    }

    public void setAlamat(String alamat) {
        this.alamat = alamat;
    }

    public void setKasirUtama(Kasir kasirUtama) {
        this.kasirUtama = (kasirUtama != null) ? kasirUtama : new Kasir();
    }

    // Getter
    public String getNamaKafe() {
        return this.namaKafe;
    }

    public String getAlamat() {
        return this.alamat;
    }

    public Kasir getKasirUtama() {
        return this.kasirUtama;
    }

    public int getJumlahMenu() {
        return this.daftarMenu.size();
    }

    // Total pegawai dihitung dari 1 kasir utama (komposisi) + seluruh staf tambahan di ArrayList
    public int getJumlahPegawai() {
        return 1 + this.daftarPegawai.size();
    }

    // -------------------------------------------------------------------------
    // Method untuk menambah item menu ke dalam kafe.
    // Berpengaruh pada Flow: Menerima tipe kelas induk (ItemMenu) sehingga
    // bisa menerima objek Makanan maupun Minuman secara fleksibel (Polimorfisme).
    // -------------------------------------------------------------------------
    public void tambahMenu(ItemMenu item) {
        if (item != null) {
            this.daftarMenu.add(item);
        }
    }

    // -------------------------------------------------------------------------
    // Method untuk menambah staf pegawai tambahan ke dalam kafe.
    // Berpengaruh pada Flow: Menerima tipe kelas induk (Pegawai) sehingga
    // bisa menerima objek Barista maupun Kasir secara fleksibel (Polimorfisme).
    // -------------------------------------------------------------------------
    public void tambahPegawai(Pegawai pegawai) {
        if (pegawai != null) {
            this.daftarPegawai.add(pegawai);
        }
    }

    // =========================================================================
    // ALUR UTAMA MENAMPILKAN DATA: tampilkanKafeLengkap()
    // Menampilkan profil kafe, kasir utama, katalog menu, dan staf pegawai.
    // Di sini terjadi Polimorfisme: saat daftarMenu.get(i).tampilkanInfo() dipanggil,
    // JVM otomatis memanggil method milik Makanan atau Minuman yang sesuai.
    // Hal serupa berlaku untuk daftarPegawai.get(i).tampilkanInfo() (Barista/Kasir).
    // =========================================================================
    public void tampilkanKafeLengkap() {
        // Perhitungan spasi rata tengah (center alignment) pada lebar 88 karakter
        int padNama = Math.max(0, (88 - this.namaKafe.length()) / 2);
        String alamatStr = "Alamat: " + this.alamat;
        int padAlamat = Math.max(0, (88 - alamatStr.length()) / 2);

        System.out.println("=".repeat(88));
        System.out.println(" ".repeat(padNama) + this.namaKafe);
        System.out.println(" ".repeat(padAlamat) + alamatStr);
        System.out.println("=".repeat(88) + "\n");

        // 1. Profil Penanggung Jawab Operasional (Komposisi Kafe)
        System.out.println("[PENANGGUNG JAWAB OPERASIONAL] (Komposisi Kafe)");
        System.out.println("  Kasir Utama : " + this.kasirUtama.getNama() +
                           " (ID: " + this.kasirUtama.getIdPegawai() +
                           " | Mesin: " + this.kasirUtama.getNomorMesinKasir() +
                           " | Selesai: " + this.kasirUtama.getTotalTransaksiSelesai() + " transaksi)");
        System.out.println("-".repeat(88) + "\n");

        // 2. Daftar Katalog Menu (Polimorfisme dinamis pada Array of Objects)
        System.out.println("[DAFTAR KATALOG MENU KAFE] (Total: " + this.getJumlahMenu() + " Menu)");
        System.out.println("-".repeat(88));
        if (this.daftarMenu.isEmpty()) {
            System.out.println("  (Belum ada item menu yang terdaftar di sistem)");
        } else {
            for (int i = 0; i < this.daftarMenu.size(); i++) {
                System.out.println("--- Menu #" + (i + 1) + " ---");
                // Dynamic dispatch memanggil tampilkanInfo() objek Makanan / Minuman
                this.daftarMenu.get(i).tampilkanInfo();
                if (i + 1 < this.daftarMenu.size()) {
                    System.out.println();
                }
            }
        }
        System.out.println("-".repeat(88) + "\n");

        // 3. Daftar Staf Pegawai (Kasir Utama + Koleksi Polimorfik Barista & Kasir tambahan)
        System.out.println("[DAFTAR STAF PEGAWAI KAFE] (Total: " + this.getJumlahPegawai() + " Pegawai)");
        System.out.println("-".repeat(88));
        System.out.println("--- Pegawai #1 [Kasir Utama] ---");
        this.kasirUtama.tampilkanInfo();
        if (!this.daftarPegawai.isEmpty()) {
            System.out.println();
        }
        for (int i = 0; i < this.daftarPegawai.size(); i++) {
            System.out.println("--- Pegawai #" + (i + 2) + " ---");
            // Dynamic dispatch memanggil tampilkanInfo() sesuai peran staf (Barista / Kasir)
            this.daftarPegawai.get(i).tampilkanInfo();
            if (i + 1 < this.daftarPegawai.size()) {
                System.out.println();
            }
        }
        System.out.println("=".repeat(88));
    }
}
