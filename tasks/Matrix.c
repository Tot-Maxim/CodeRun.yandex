#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    // Выделяем память для матриц A и B
    int** A = (int**)malloc(n * sizeof(int*));
    int** B = (int**)malloc(m * sizeof(int*));
    int** C = (int**)malloc(n * sizeof(int*)); // Результат умножения A * B
    int** CT = (int**)malloc(k * sizeof(int*)); // Транспонированная матрица C

    for (int i = 0; i < n; i++) {
        A[i] = (int*)malloc(m * sizeof(int));
        C[i] = (int*)malloc(k * sizeof(int));
    }
    for (int i = 0; i < m; i++) {
        B[i] = (int*)malloc(k * sizeof(int));
    }
    for (int i = 0; i < k; i++) {
        CT[i] = (int*)malloc(n * sizeof(int));
    }

    // Считываем матрицу A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Считываем матрицу B
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Умножаем матрицы A и B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = 0;
            for (int l = 0; l < m; l++) {
                C[i][j] += A[i][l] * B[l][j];
            }
        }
    }

    // Транспонируем матрицу C
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            CT[j][i] = C[i][j];
        }
    }

    // Выводим транспонированную матрицу CT
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", CT[i][j]);
        }
        printf("\n");
    }

    // Освобождаем выделенную память
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(C[i]);
    }
    for (int i = 0; i < m; i++) {
        free(B[i]);
    }
    for (int i = 0; i < k; i++) {
        free(CT[i]);
    }
    free(A);
    free(B);
    free(C);
    free(CT);

    return 0;
}