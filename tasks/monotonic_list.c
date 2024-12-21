#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000]; // Предполагаем, что строка не будет длинее 1000 символов
    int *arr = NULL;
    int n = 0;
    while (1) {
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Если достигнут конец файла или произошла ошибка, выходим из цикла
        }

        // Удаляем символ новой строки, если он есть
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        char *token = strtok(input, " ");
        n = 0;

        // Разбираем строку и заполняем массив числами
        while (token != NULL) {
            // Увеличиваем размер массива
            arr = (int *)realloc(arr, (n + 1) * sizeof(int));
            if (arr == NULL) {
                fprintf(stderr, "Ошибка выделения памяти\n");
                return 1;
            }
            arr[n] = atoi(token);
            token = strtok(NULL, " ");
            n++;
        }

        int is_monotonic = 1; // Предполагаем, что массив монотонно возрастает

        for (int i = 1; i < n; i++) {
            if (arr[i] <= arr[i - 1]) {
                is_monotonic = 0; // Если текущий элемент не больше предыдущего, то массив не монотонно возрастает
                break;
            }
        }

        if (is_monotonic) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

        // Освобождаем память перед следующей итерацией
        free(arr);
        arr = NULL;
    }
        return 0;
}