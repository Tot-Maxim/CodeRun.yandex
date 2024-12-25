#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "saper.h"

void process_saper() {

    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    // Создаем двумерный массив для поля
    int field[N][M];
    int i, j;

    // Инициализируем поле нулями
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            field[i][j] = 0;
        }
    }

    // Читаем координаты мин и устанавливаем их на поле
    for (int k = 0; k < K; k++) {
        int p, q;
        scanf("%d %d", &p, &q);
        field[p-1][q-1] = -1; // Устанавливаем мину как -1
    }

    // Обновляем числа вокруг мин
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (field[i][j] == -1) {
                // Проверяем все восемь соседних клеток
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int x = i + dx;
                        int y = j + dy;
                        if (x >= 0 && x < N && y >= 0 && y < M && field[x][y] != -1) {
                            field[x][y]++;
                        }
                    }
                }
            }
        }
    }

    // Выводим поле
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (field[i][j] == -1) {
                printf("*");
            } else if (field[i][j] == 0) {
                printf("0");
            } else {
                printf("%d", field[i][j]);
            }
            if (j < M - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

}
