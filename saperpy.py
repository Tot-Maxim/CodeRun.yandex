#!/usr/bin/env python3
import sys

def main():
    # Считываем размеры поля и количество мин
    N, M, K = map(int, input().split())

    # Создаем двумерный массив для поля и инициализируем его нулями
    field = [[0] * M for _ in range(N)]

    # Читаем координаты мин и устанавливаем их на поле
    for _ in range(K):
        p, q = map(int, input().split())
        field[p-1][q-1] = -1  # Устанавливаем мину как -1

    # Обновляем числа вокруг мин
    for i in range(N):
        for j in range(M):
            if field[i][j] == -1:
                # Проверяем все восемь соседних клеток
                for dx in range(-1, 2):
                    for dy in range(-1, 2):
                        x = i + dx
                        y = j + dy
                        if 0 <= x < N and 0 <= y < M and field[x][y] != -1:
                            field[x][y] += 1

    # Выводим поле
    for i in range(N):
        for j in range(M):
            if field[i][j] == -1:
                print("*", end="")
            else:
                print(field[i][j], end="")
            if j < M - 1:
                print(" ", end="")
        print()

if __name__ == "__main__":
    main()