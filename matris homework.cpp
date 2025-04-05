#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SATIR_A 2
#define SUTUN_A 3
#define SATIR_B 3
#define SUTUN_B 2

// rastgele sayılar içeren Matris A fonksiyonu
void matrisDoldurA(int matris[][SUTUN_A], int satir, int sutun) {
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            matris[i][j] = rand() % 100 + 1; // 1 ile 100 arasında rastgele sayı
        }
    }
}

// rastgele sayılar içeren Matris B fonksiyonu
void matrisDoldurB(int matris[][SUTUN_B], int satir, int sutun) {
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            matris[i][j] = rand() % 100 + 1; // 1 ile 100 arasında rastgele sayı
        }
    }
}

// Matris yazdırma fonksiyonu
void matrisYazdir(int satir, int sutun, int matris[satir][sutun]) {
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            printf("%3d ", matris[i][j]); // 4 karakter genişliğinde hizalama
        }
        printf("\n");
    }
}

// Matris çarpma işlemi fonksiyonu (A*B)
void matrisCarp(int A[][SUTUN_A], int B[][SUTUN_B], int C[][SUTUN_B]) {
    for (int i = 0; i < SATIR_A; i++) {
        for (int j = 0; j < SUTUN_B; j++) {
            C[i][j] = 0;
            for (int k = 0; k < SUTUN_A; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Matris transpozu fonksiyonu
void matrisTranspoze(int satir, int sutun, int matris[satir][sutun], int transpoz[sutun][satir]) {
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            transpoz[j][i] = matris[i][j];
        }
    }
}

int main() {
    srand(time(NULL)); 

    int A[SATIR_A][SUTUN_A]; // Matris A için değişken (2x3)
    int B[SATIR_B][SUTUN_B]; // Matris B için değişken (3x2)
    int C[SATIR_A][SUTUN_B]; // Çarpım matrisi için değişken (2x2)
    int C_T[SUTUN_B][SATIR_A]; // C matrisinin transpoz matrisi değişkeni (2x2'nin transpozu 2x2)

    // Matrisleri rastgele doldurma
    matrisDoldurA(A, SATIR_A, SUTUN_A);
    matrisDoldurB(B, SATIR_B, SUTUN_B);

    // Matrisleri ekrana yazdırma
    printf("Matris A:\n");
    matrisYazdir(SATIR_A, SUTUN_A, A);

    printf("\nMatris B:\n");
    matrisYazdir(SATIR_B, SUTUN_B, B);

    // Çarpma işlemi
    matrisCarp(A, B, C);

    printf("\nMatris Carpimi (A * B):\n");
    matrisYazdir(SATIR_A, SUTUN_B, C);

    // Matrisin transpozu
    matrisTranspoze(SATIR_A, SUTUN_B, C, C_T);

    printf("\nMatris Carpiminin Transpozu (C_T):\n");
    matrisYazdir(SUTUN_B, SATIR_A, C_T);

    return 0;
}
