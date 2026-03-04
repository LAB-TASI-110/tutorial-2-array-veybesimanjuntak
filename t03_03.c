#include <stdio.h>  // Untuk fungsi input/output
#include <stdlib.h> // Untuk malloc dan free
#include <float.h>  // Untuk FLT_MAX dan FLT_MIN (nilai float terbesar dan terkecil)

int main() {
    int n; 
    scanf("%d", &n); 
    
    int *numbers = (int *)malloc(n * sizeof(int));
    if (numbers == NULL) {
        return 1; 
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    int min_val = numbers[0]; 
    int max_val = numbers[0]; 

    for (int i = 1; i < n; i++) {
        if (numbers[i] < min_val) {
            min_val = numbers[i];
        }
        if (numbers[i] > max_val) {
            max_val = numbers[i];
        }
    }

    printf("%d\n", min_val);
    printf("%d\n", max_val);

    float min_avg_consecutive = FLT_MAX; // Inisialisasi dengan nilai float terbesar
    float max_avg_consecutive = FLT_MIN; // Inisialisasi dengan nilai float terkecil

    // Hanya mencari rata-rata jika ada setidaknya satu pasangan (n >= 2)
    if (n >= 2) {
        for (int i = 0; i < n - 1; i++) { // Loop sampai elemen ke-n-2 untuk mendapatkan pasangan terakhir
            float current_avg = (float)(numbers[i] + numbers[i+1]) / 2.0;
            if (current_avg < min_avg_consecutive) {
                min_avg_consecutive = current_avg;
            }
            if (current_avg > max_avg_consecutive) {
                max_avg_consecutive = current_avg;
            }
        }
        printf("%.2f\n", min_avg_consecutive);
        printf("%.2f\n", max_avg_consecutive);
    }

    free(numbers);
    return 0; 
}
