#include <stdio.h>  // Diperlukan untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Diperlukan untuk INT_MAX dan INT_MIN untuk inisialisasi min/max
#include <float.h>  // Diperlukan untuk FLT_MAX untuk inisialisasi min_avg

int main() {
    // Deklarasi variabel
    int n;           // Jumlah baris masukan berikutnya.
    int num;         // Menyimpan setiap bilangan yang dibaca dari input.
    int min_val;     // Menyimpan nilai terkecil yang ditemukan.
    int max_val;     // Menyimpan nilai terbesar yang ditemukan.
    int prev_num;    // Menyimpan bilangan sebelumnya untuk perhitungan rata-rata pasangan.
    float min_avg;   // Menyimpan nilai rata-rata terendah dari pasangan bilangan berturut-turut.

    // 1. Membaca baris pertama masukan: jumlah bilangan 'n'
    printf("Masukkan jumlah bilangan (n): "); // Pesan panduan untuk pengguna
    scanf("%d", &n);

    // Pastikan n adalah bilangan bulat positif sesuai spesifikasi
    if (n <= 0) {
        printf("Jumlah bilangan (n) harus positif.\n");
        return 1; // Mengembalikan kode error
    }

    // Membaca bilangan pertama untuk inisialisasi
    printf("Masukkan bilangan ke-1: "); // Pesan panduan untuk pengguna
    scanf("%d", &num);
    min_val = num; // Inisialisasi min_val dengan bilangan pertama
    max_val = num; // Inisialisasi max_val dengan bilangan pertama
    prev_num = num; // Simpan bilangan pertama sebagai bilangan sebelumnya untuk pasangan pertama

    // Inisialisasi min_avg dengan nilai floating-point maksimum
    // Ini memastikan bahwa rata-rata pasangan pertama yang valid akan selalu lebih kecil dan menjadi min_avg awal.
    min_avg = FLT_MAX;

    // 2. Membaca n-1 baris masukan berikutnya dan mencari nilai terkecil, terbesar, dan rata-rata terendah
    // Loop 'for' akan berjalan dari i=1 hingga i<n (sebanyak n-1 kali), karena bilangan pertama sudah dibaca.
    for (int i = 1; i < n; i++) {
        printf("Masukkan bilangan ke-%d: ", i + 1); // Pesan panduan untuk pengguna
        scanf("%d", &num); // Membaca bilangan berikutnya

        // Memperbarui nilai minimum jika 'num' lebih kecil
        if (num < min_val) {
            min_val = num;
        }

        // Memperbarui nilai maksimum jika 'num' lebih besar
        if (num > max_val) {
            max_val = num;
        }

        // Hanya hitung rata-rata jika ada setidaknya dua bilangan (i > 0)
        // (i = 1 adalah bilangan kedua, jadi pasangan pertama (bilangan ke-1 dan ke-2) terbentuk)
        float current_avg = (float)(prev_num + num) / 2.0; // Hitung rata-rata pasangan saat ini
        if (current_avg < min_avg) {
            min_avg = current_avg; // Perbarui min_avg jika rata-rata saat ini lebih kecil
        }

        prev_num = num; // Perbarui bilangan sebelumnya untuk iterasi berikutnya
    }

    // 3. Menampilkan tiga baris keluaran
    // Mencetak nilai terkecil
    printf("%d\n", min_val);

    // Mencetak nilai terbesar
    printf("%d\n", max_val);

    // Mencetak nilai rata-rata terendah dari pasangan berturut-turut, dengan 2 digit presisi
    // Jika n < 2, artinya tidak ada pasangan yang bisa dibentuk untuk dihitung rata-ratanya.
    // Dalam kasus ini, min_avg akan tetap FLT_MAX atau perlu penanganan khusus.
    // Karena spesifikasi "n adalah bilangan bulat positif", dan "n+1 baris masukan",
    // jika n=1, maka hanya ada satu bilangan, sehingga tidak ada rata-rata pasangan.
    // Program ini diasumsikan berjalan dengan n >= 2 untuk perhitungan rata-rata.
    if (n >= 2) {
        printf("%.2f\n", min_avg);
    } else {
        // Jika n=1, tidak ada pasangan untuk dihitung rata-rata terendah
        printf("Tidak ada pasangan bilangan untuk dihitung rata-rata.\n");
    }

    return 0; // Mengindikasikan program berakhir dengan sukses
}
