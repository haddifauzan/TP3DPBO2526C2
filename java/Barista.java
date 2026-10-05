// =============================================================================
// Kelas Turunan (Derived Class 3): Barista
// Mewarisi Pegawai (Hierarchical Inheritance) menggunakan kata kunci 'extends'.
// Menambahkan atribut keahlian khusus peracik kopi dan pembagian jadwal shift kerja.
// =============================================================================

public class Barista extends Pegawai {
    private String keahlianUtama; // Contoh: Latte Art & Manual Brew
    private String shiftKerja;    // Pagi (Morning Shift) atau Malam (Night Shift)

    // Konstruktor default
    public Barista() {
        super();
        this.keahlianUtama = "";
        this.shiftKerja = "";
    }

    // Konstruktor berparameter:
    // Memanggil super(idPegawai, nama, nomorHp, gajiPokok) untuk mengisi atribut kelas induk
    public Barista(String idPegawai, String nama, String nomorHp, double gajiPokok,
                   String keahlianUtama, String shiftKerja) {
        super(idPegawai, nama, nomorHp, gajiPokok);
        this.keahlianUtama = keahlianUtama;
        this.shiftKerja = shiftKerja;
    }

    // Setter
    public void setKeahlianUtama(String keahlianUtama) {
        this.keahlianUtama = keahlianUtama;
    }

    public void setShiftKerja(String shiftKerja) {
        this.shiftKerja = shiftKerja;
    }

    // Getter
    public String getKeahlianUtama() {
        return this.keahlianUtama;
    }

    public String getShiftKerja() {
        return this.shiftKerja;
    }

    // Method Overriding: Polimorfisme untuk mencetak card info staf Barista
    @Override
    public void tampilkanInfo() {
        System.out.println("  [+] [BARISTA] ID: " + this.idPegawai + " | " + this.nama);
        System.out.println("      ├─ Nomor HP      : " + this.nomorHp);
        System.out.println("      ├─ Gaji Pokok    : Rp " + (long) this.gajiPokok);
        System.out.println("      ├─ Keahlian      : " + this.keahlianUtama);
        System.out.println("      └─ Shift Kerja   : " + this.shiftKerja);
    }
}
