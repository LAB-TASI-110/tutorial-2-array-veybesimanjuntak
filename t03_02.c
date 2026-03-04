#include <stdio.h> // Untuk fungsi input/output seperti scanf dan printf
#include <stdlib.h> // Untuk fungsi dynamic memory allocation seperti malloc dan free

int main() {
    int n; // Variabel untuk menyimpan jumlah bilangan yang akan diinput
    
    scanf("%d", &n); 
    
    int *numbers = (int *)malloc(n * sizeof(int));
    
    if (numbers == NULL) {
        return 1; 
    }

    int min_val; 
    int max_val; 

    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    min_val = numbers[0];
    max_val = numbers[0];

    for (int i = 1; i < n; i++) {
        if (numbers[i] < min_val) {
            min_val = numbers[i];
        }
        if (numbers[i] > max_val) {
            max_val = numbers[i];
        }
    }

    // Mencetak nilai terkecil dan terbesar
    printf("%d\n", min_val);
    printf("%d\n", max_val);

    // Menghitung rata-rata dari dua elemen pertama
    // Pastikan n minimal 2 untuk menghindari akses out-of-bounds
    // Asumsi dari problem statement dan contoh, n akan selalu cukup.
    if (n >= 2) {
        float avg_first_two = (float)(numbers[0] + numbers[1]) / 2.0;
        printf("%.2f\n", avg_first_two); // Mencetak rata-rata dengan 2 digit presisi
    }

    free(numbers);
    
    return 0; 
}
