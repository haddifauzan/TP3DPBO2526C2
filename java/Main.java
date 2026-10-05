import java.io.PrintStream;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        // Mengaktifkan encoding UTF-8 agar karakter box-drawing (├─, └─) tampil rapi di terminal
        try {
            System.setOut(new PrintStream(System.out, true, StandardCharsets.UTF_8));
        } catch (Exception ignored) {}

        // =========================================================================
        // ALUR 1: Inisialisasi Objek Utama & Menerapkan Konsep KOMPOSISI
        // - Kasir utama dibuat terlebih dahulu sebagai penanggung jawab kafe.
        // - Objek 'kasirUtama' diserahkan ke dalam constructor objek 'kafe'.
        // - Ini menerapkan KOMPOSISI: Kafe memiliki hubungan kepemilikan kuat
        //   terhadap kasir utama (kasir utama hidup sebagai bagian dari kafe).
        // =========================================================================
        Kasir kasirUtama = new Kasir("KSR-01", "Ujang Kedu", "0812-3456-7890", 4200000.0, "POS-01", 125);
        Kafe kafe = new Kafe("Java Coffee & Eatery", "Jl. Kalijaga No. 89, Cimahi", kasirUtama);

        // =========================================================================
        // ALUR 2: Mengisi Data Awal Kafe (ARRAY OF OBJECTS & POLIMORFISME)
        // - Objek turunan Makanan dan Minuman dimasukkan ke wadah yang sama (daftarMenu)
        //   menggunakan tipe kelas induk (ItemMenu).
        // - Objek turunan Barista dan Kasir dimasukkan ke wadah daftarPegawai
        //   menggunakan tipe kelas induk (Pegawai).
        // - Ini membuktikan konsep Polimorfisme: satu ArrayList bertipe induk dapat
        //   menampung berbagai objek kelas turunannya secara dinamis.
        // =========================================================================
        
        // Menambahkan 2 makanan awal
        kafe.tambahMenu(new Makanan(
            "MK-01", "Croissant Butter", 28000.0, "Makanan",
            "Pastry", false, true,
            new ArrayList<>(Arrays.asList("Extra Salted Butter", "Selai Cokelat"))
        ));
        kafe.tambahMenu(new Makanan(
            "MK-02", "Truffle French Fries", 32000.0, "Makanan",
            "Snack", true, false,
            new ArrayList<>(Arrays.asList("Saus Tartar", "Bubuk Nori"))
        ));

        // Menambahkan 2 minuman awal
        kafe.tambahMenu(new Minuman(
            "MN-01", "Caramel Macchiato", 38000.0, "Minuman",
            "Dingin (Ice)", "Regular", "Less Sugar",
            "Oat Milk", 1, "Arabica Single Origin Aceh Gayo",
            new ArrayList<>(Arrays.asList("Whipped Cream", "Caramel Drizzle"))
        ));
        kafe.tambahMenu(new Minuman(
            "MN-02", "Matcha Green Tea Latte", 35000.0, "Minuman",
            "Panas (Hot)", "Large", "Normal Sweet",
            "Fresh Milk", 0, "-",
            new ArrayList<>(Arrays.asList("Matcha Powder Dusting"))
        ));

        // Menambahkan 3 staf tambahan (2 Barista + 1 Kasir)
        // Catatan: Kasir utama sudah otomatis tercatat sebagai Pegawai #1 via Komposisi
        kafe.tambahPegawai(new Barista(
            "BAR-01", "Fajar Nugraha", "0813-9876-5432", 4500000.0,
            "Latte Art & Manual Brew", "Pagi (Morning Shift)"
        ));
        kafe.tambahPegawai(new Barista(
            "BAR-02", "Dimas Prasetyo", "0821-5566-7788", 4300000.0,
            "Cold Brew & Roasting", "Malam (Night Shift)"
        ));
        kafe.tambahPegawai(new Kasir(
            "KSR-02", "Siti Aminah", "0819-1122-3344", 4000000.0,
            "POS-02", 38
        ));

        // =========================================================================
        // ALUR 3: Menampilkan Seluruh Data Kafe Sebelum Ada Penambahan
        // Memanggil method tampilkanKafeLengkap() yang mencetak info kafe,
        // kasir utama, katalog 4 menu, dan 4 staf pegawai (1 kasir utama + 3 staf).
        // Di dalamnya, method tampilkanInfo() dipanggil secara polimorfik.
        // =========================================================================
        System.out.println("\n============================ >> SEBELUM DATA DITAMBAHKAN << ============================\n");
        kafe.tampilkanKafeLengkap();

        // =========================================================================
        // ALUR 4: Proses Penambahan Data Baru Secara Dinamis
        // Membuktikan bahwa sistem dapat menambahkan objek baru ke objek 'kafe'
        // yang sedang berjalan:
        // - 1 Menu Makanan baru (Spaghetti Aglio Olio - MK-03)
        // - 1 Menu Minuman baru (Signature Cold Brew Float - MN-03)
        // - 1 Staf Barista baru (Alya Safira - BAR-03)
        // =========================================================================
        System.out.println("\n\n>>>>>>>>>>>>>>>>>>>>>>>> PROSES PENAMBAHAN DATA BARU KE KAFE <<<<<<<<<<<<<<<<<<<<<<<<<");
        
        // 1. Tambah makanan baru
        System.out.println("[+] Menambahkan 1 Makanan Baru : Spaghetti Aglio Olio (MK-03)");
        kafe.tambahMenu(new Makanan(
            "MK-03", "Spaghetti Aglio Olio", 45000.0, "Makanan",
            "Main Course", false, true,
            new ArrayList<>(Arrays.asList("Extra Keju Parmesan", "Telor Ceplok"))
        ));

        // 2. Tambah minuman baru
        System.out.println("[+] Menambahkan 1 Minuman Baru : Signature Cold Brew Float (MN-03)");
        kafe.tambahMenu(new Minuman(
            "MN-03", "Signature Cold Brew Float", 40000.0, "Minuman",
            "Dingin (Ice)", "Large", "Less Sugar",
            "-", 0, "House Blend Flores Bajawa",
            new ArrayList<>(Arrays.asList("Vanilla Ice Cream Scoop"))
        ));

        // 3. Tambah barista baru
        System.out.println("[+] Menambahkan 1 Barista Baru : Alya Safira (BAR-03)");
        kafe.tambahPegawai(new Barista(
            "BAR-03", "Alya Safira", "0857-1234-5678", 4400000.0,
            "Espresso Extraction & Cupping", "Pagi (Morning Shift)"
        ));
        System.out.println("-".repeat(88));
        System.out.println("Penambahan data sukses diproses!\n");

        // =========================================================================
        // ALUR 5: Menampilkan Seluruh Data Kafe Sesudah Penambahan
        // Memanggil kembali method tampilkanKafeLengkap().
        // Hasil cetakan membuktikan bahwa data bertambah secara dinamis:
        // - Total menu bertambah dari 4 menjadi 6 menu.
        // - Total staf bertambah dari 4 menjadi 5 staf pegawai.
        // =========================================================================
        System.out.println("============================ >> SESUDAH DATA DITAMBAHKAN << ============================\n");
        kafe.tampilkanKafeLengkap();
    }
}
