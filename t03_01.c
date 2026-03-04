#include <stdio.h> // Header ini diperlukan untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Header ini diperlukan untuk menggunakan INT_MAX dan INT_MIN sebagai nilai inisialisasi awal

int main() {
    // Deklarasi variabel
    int n;          // Variabel 'n' bertipe integer untuk menyimpan jumlah baris masukan berikutnya.
                    // Ini akan menjadi jumlah bilangan yang akan diproses.
    int num;        // Variabel 'num' bertipe integer untuk menyimpan setiap bilangan yang dibaca dari input.
    int min_val;    // Variabel 'min_val' bertipe integer untuk menyimpan nilai terkecil yang ditemukan.
    int max_val;    // Variabel 'max_val' bertipe integer untuk menyimpan nilai terbesar yang ditemukan.

    // 1. Membaca baris pertama masukan: jumlah bilangan 'n'
    // Fungsi scanf digunakan untuk membaca input dari keyboard. "%d" menunjukkan bahwa input yang diharapkan adalah integer,
    // dan '&n' adalah alamat memori tempat nilai yang dibaca akan disimpan.
    printf("Masukkan jumlah bilangan (n): "); // Pesan panduan untuk pengguna (opsional, untuk UX)
    scanf("%d", &n);

    // Inisialisasi nilai minimum dan maksimum
    // Kita perlu membaca bilangan pertama terlebih dahulu untuk menginisialisasi min_val dan max_val.
    // Ini penting karena n adalah bilangan bulat positif, jadi pasti ada setidaknya satu bilangan.
    // Jika kita menginisialisasi dengan INT_MAX dan INT_MIN dari <limits.h>, maka inisialisasi dengan nilai pertama
    // akan selalu bekerja dengan baik untuk menemukan min/max dari seluruh set.
    // Sebagai alternatif, bisa juga min_val = INT_MAX dan max_val = INT_MIN.
    // Namun, cara yang lebih robust adalah membaca elemen pertama untuk inisialisasi.

    if (n > 0) { // Pastikan ada setidaknya satu angka untuk dibaca, karena n adalah bilangan bulat positif.
        // Membaca bilangan pertama
        printf("Masukkan bilangan ke-1: "); // Pesan panduan untuk pengguna
        scanf("%d", &num);
        min_val = num; // Inisialisasi min_val dengan bilangan pertama
        max_val = num; // Inisialisasi max_val dengan bilangan pertama

        // 2. Membaca n-1 baris masukan berikutnya dan mencari nilai terkecil dan terbesar
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
        }
    } else {
        // Kasus ini seharusnya tidak terjadi berdasarkan spesifikasi (n adalah bilangan bulat positif),
        // namun disertakan untuk penanganan error yang lebih baik jika input tidak valid.
        printf("Jumlah bilangan (n) harus positif.\n");
        return 1; // Mengembalikan kode error
    }

    // 3. Menampilkan tiga baris keluaran
    // Mencetak nilai terkecil
    printf("%d\n", min_val);

    // Mencetak nilai terbesar
    printf("%d\n", max_val);

    return 0; // Mengindikasikan program berakhir dengan sukses
}
