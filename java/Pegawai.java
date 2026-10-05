// =============================================================================
// Kelas Dasar (Base Class 2): Pegawai
// Berfungsi sebagai induk untuk semua pekerja di kafe.
// Menerapkan konsep Hierarchical Inheritance karena diturunkan menjadi dua
// peran spesifik, yaitu Barista dan Kasir.
// =============================================================================

public class Pegawai {
    // Modifier protected memungkinkan atribut ini diakses langsung oleh kelas turunan
    protected String idPegawai;
    protected String nama;
    protected String nomorHp;
    protected double gajiPokok;

    // Konstruktor default
    public Pegawai() {
        this.idPegawai = "";
        this.nama = "";
        this.nomorHp = "";
        this.gajiPokok = 0.0;
    }

    // Konstruktor berparameter untuk inisialisasi data pegawai
    public Pegawai(String idPegawai, String nama, String nomorHp, double gajiPokok) {
        this.idPegawai = idPegawai;
        this.nama = nama;
        this.nomorHp = nomorHp;
        this.gajiPokok = gajiPokok;
    }

    // Setter
    public void setIdPegawai(String idPegawai) {
        this.idPegawai = idPegawai;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public void setNomorHp(String nomorHp) {
        this.nomorHp = nomorHp;
    }

    public void setGajiPokok(double gajiPokok) {
        this.gajiPokok = gajiPokok;
    }

    // Getter
    public String getIdPegawai() {
        return this.idPegawai;
    }

    public String getNama() {
        return this.nama;
    }

    public String getNomorHp() {
        return this.nomorHp;
    }

    public double getGajiPokok() {
        return this.gajiPokok;
    }

    // Method dasar untuk polimorfisme, akan di-override oleh Barista dan Kasir
    public void tampilkanInfo() {
        System.out.println("  [+] ID: " + this.idPegawai + " | " + this.nama);
        System.out.println("      ├─ Nomor HP      : " + this.nomorHp);
        System.out.println("      └─ Gaji Pokok    : Rp " + (long) this.gajiPokok);
    }
}
