#include <stdio.h> // Untuk fungsi input/output seperti scanf dan printf
#include <stdlib.h> // Untuk fungsi dynamic memory allocation seperti malloc dan free

int main() {
    int n; // Variabel untuk menyimpan jumlah bilangan yang akan diinput
    
    // Membaca nilai n dari input
    scanf("%d", &n); 
    
    // Mengalokasikan memori secara dinamis untuk menyimpan n bilangan bulat
    // sizeof(int) mengembalikan ukuran satu integer dalam byte
    int *numbers = (int *)malloc(n * sizeof(int));
    
    // Cek apakah alokasi memori berhasil. Jika gagal, program keluar.
    if (numbers == NULL) {
        return 1; // Mengembalikan kode error
    }

    int min_val; // Variabel untuk menyimpan nilai terkecil
    int max_val; // Variabel untuk menyimpan nilai terbesar

    // Membaca n bilangan dan menyimpannya ke dalam array
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    // Inisialisasi min_val dan max_val dengan elemen pertama array
    // Ini aman karena n adalah bilangan bulat positif, jadi pasti ada setidaknya satu elemen
    min_val = numbers[0];
    max_val = numbers[0];

    // Iterasi dari elemen kedua untuk mencari nilai min dan max
    for (int i = 1; i < n; i++) {
        if (numbers[i] < min_val) {
            min_val = numbers[i];
        }
        if (numbers[i] > max_val) {
            max_val = numbers[i];
        }
    }

    // Mencetak nilai terkecil dan terbesar, masing-masing pada baris baru
    printf("%d\n", min_val);
    printf("%d\n", max_val);

    // Membebaskan memori yang telah dialokasikan secara dinamis
    free(numbers);
    
    return 0; // Mengembalikan 0 menandakan program berakhir dengan sukses
}
