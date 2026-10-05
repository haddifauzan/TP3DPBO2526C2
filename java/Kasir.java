// =============================================================================
// Kelas Turunan (Derived Class 4): Kasir
// Mewarisi Pegawai (Hierarchical Inheritance) menggunakan kata kunci 'extends'.
// Menambahkan atribut pengelolaan kasir: nomor mesin POS dan riwayat total transaksi.
// Kelas ini juga digunakan sebagai komponen Komposisi pada kelas Kafe.
// =============================================================================

public class Kasir extends Pegawai {
    private String nomorMesinKasir;    // Contoh: POS-01, POS-02
    private int totalTransaksiSelesai; // Jumlah transaksi yang berhasil diselesaikan

    // Konstruktor default
    public Kasir() {
        super();
        this.nomorMesinKasir = "";
        this.totalTransaksiSelesai = 0;
    }

    // Konstruktor berparameter:
    // Memanggil super(idPegawai, nama, nomorHp, gajiPokok) untuk mengisi atribut kelas induk
    public Kasir(String idPegawai, String nama, String nomorHp, double gajiPokok,
                 String nomorMesinKasir, int totalTransaksiSelesai) {
        super(idPegawai, nama, nomorHp, gajiPokok);
        this.nomorMesinKasir = nomorMesinKasir;
        this.totalTransaksiSelesai = totalTransaksiSelesai;
    }

    // Setter
    public void setNomorMesinKasir(String nomorMesinKasir) {
        this.nomorMesinKasir = nomorMesinKasir;
    }

    public void setTotalTransaksiSelesai(int totalTransaksiSelesai) {
        this.totalTransaksiSelesai = totalTransaksiSelesai;
    }

    // Getter
    public String getNomorMesinKasir() {
        return this.nomorMesinKasir;
    }

    public int getTotalTransaksiSelesai() {
        return this.totalTransaksiSelesai;
    }

    // Method Overriding: Polimorfisme untuk mencetak card info staf Kasir
    @Override
    public void tampilkanInfo() {
        System.out.println("  [+] [KASIR] ID: " + this.idPegawai + " | " + this.nama);
        System.out.println("      ├─ Nomor HP      : " + this.nomorHp);
        System.out.println("      ├─ Gaji Pokok    : Rp " + (long) this.gajiPokok);
        System.out.println("      ├─ Mesin POS     : " + this.nomorMesinKasir);
        System.out.println("      └─ Transaksi Sls : " + this.totalTransaksiSelesai + " transaksi");
    }
}
