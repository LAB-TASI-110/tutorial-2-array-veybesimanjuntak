#include <stdio.h>  // Diperlukan untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Diperlukan untuk INT_MAX dan INT_MIN untuk inisialisasi min/max
#include <float.h>  // Diperlukan untuk FLT_MAX untuk inisialisasi min_avg

int main() {
    // Deklarasi variabel
    int n;           // Variabel 'n' bertipe integer untuk menyimpan jumlah baris masukan berikutnya.
    int num;         // Variabel 'num' bertipe integer untuk menyimpan setiap bilangan yang dibaca dari input.
    int min_val;     // Variabel 'min_val' bertipe integer untuk menyimpan nilai terkecil yang ditemukan.
    int max_val;     // Variabel 'max_val' bertipe integer untuk menyimpan nilai terbesar yang ditemukan.
    int prev_num;    // Variabel 'prev_num' bertipe integer, menyimpan bilangan sebelumnya untuk perhitungan rata-rata pasangan.
    float min_avg;   // Variabel 'min_avg' bertipe float, menyimpan nilai rata-rata terendah dari SEMUA pasangan bilangan berturut-turut.
    float avg_third_fourth; // Variabel 'avg_third_fourth' bertipe float, menyimpan nilai rata-rata dari elemen ketiga dan keempat.
    int third_element = 0;  // Variabel 'third_element' bertipe integer, untuk menyimpan nilai bilangan ke-3.
    int fourth_element = 0; // Variabel 'fourth_element' bertipe integer, untuk menyimpan nilai bilangan ke-4.
    
    // 1. Membaca baris pertama masukan: jumlah bilangan 'n'
    printf("Masukkan jumlah bilangan (n): "); // Pesan panduan untuk pengguna
    scanf("%d", &n);

    // Pastikan n adalah bilangan bulat positif sesuai spesifikasi
    if (n <= 0) {
        printf("Jumlah bilangan (n) harus positif.\n");
        return 1; // Mengembalikan kode error
    }

    // Membaca bilangan pertama untuk inisialisasi awal
    printf("Masukkan bilangan ke-1: "); // Pesan panduan untuk pengguna
    scanf("%d", &num);
    min_val = num; // Inisialisasi min_val dengan bilangan pertama
    max_val = num; // Inisialisasi max_val dengan bilangan pertama
    prev_num = num; // Simpan bilangan pertama sebagai bilangan sebelumnya
    min_avg = FLT_MAX; // Inisialisasi min_avg dengan nilai floating-point maksimum

    // 2. Membaca n-1 baris masukan berikutnya dan mencari nilai terkecil, terbesar, dan rata-rata
    // Loop 'for' akan berjalan dari i=1 hingga i<n.
    // Variabel 'i' di sini secara efektif mewakili indeks bilangan yang sedang diproses setelah bilangan pertama (i=1 untuk bilangan ke-2, i=2 untuk bilangan ke-3, dst.).
    for (int i = 1; i < n; i++) {
        printf("Masukkan bilangan ke-%d: ", i + 1); // Pesan panduan untuk pengguna
        scanf("%d", &num); // Membaca bilangan berikutnya

        // Memperbarui nilai minimum dan maksimum
        if (num < min_val) {
            min_val = num;
        }
        if (num > max_val) {
            max_val = num;
        }

        // Menyimpan nilai elemen ketiga dan keempat secara spesifik
        if (i + 1 == 3) { // Jika ini adalah bilangan ke-3 (karena i dimulai dari 1 untuk bilangan ke-2)
            third_element = num;
        }
        if (i + 1 == 4) { // Jika ini adalah bilangan ke-4
            fourth_element = num;
        }

        // Menghitung rata-rata pasangan saat ini untuk mencari 'min_avg' dari semua pasangan berturut-turut
        float current_avg_pair = (float)(prev_num + num) / 2.0; 
        if (current_avg_pair < min_avg) {
            min_avg = current_avg_pair; // Perbarui min_avg jika rata-rata saat ini lebih kecil
        }

        prev_num = num; // Perbarui bilangan sebelumnya untuk iterasi berikutnya
    }

    // 3. Menghitung rata-rata elemen ketiga dan keempat jika tersedia
    if (n >= 4) { // Memastikan ada setidaknya 4 elemen untuk menghitung rata-rata elemen ketiga dan keempat
        avg_third_fourth = (float)(third_element + fourth_element) / 2.0;
    }

    // 4. Menampilkan semua keluaran
    // Mencetak nilai terkecil
    printf("%d\n", min_val);

    // Mencetak nilai terbesar
    printf("%d\n", max_val);

    // Mencetak nilai rata-rata terendah dari SEMUA pasangan berturut-turut, dengan 2 digit presisi
    // Baris ini akan mencetak '2.50' sesuai contoh Anda untuk rata-rata (8, -3).
    if (n >= 2) { 
        printf("%.2f\n", min_avg);
    } else {
        printf("Tidak ada pasangan bilangan untuk dihitung rata-rata.\n");
    }
    
    // Mencetak nilai rata-rata dari elemen ketiga dan keempat, dengan 2 digit presisi
    // Baris ini akan mencetak '46.50' sesuai contoh Anda untuk rata-rata (16, 77).
    if (n >= 4) { 
        printf("%.2f\n", avg_third_fourth);
    }
    // Jika n < 4, baris output ini tidak akan muncul, sesuai dengan contoh output yang Anda berikan.

    return 0; // Mengindikasikan program berakhir dengan sukses
}
