#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monotonic.h"

// Объявление функции из другого файла
void process_input();

void run_test(const char *input, const char *expected_output) {
    // Перенаправим вывод в буфер
    char buffer[128];
    FILE *output = fmemopen(buffer, sizeof(buffer), "w"); // Подготовим буфер для вывода
    if (output == NULL) {
        fprintf(stderr, "Ошибка при создании буфера для вывода\n");
        return;
    }

    // Перенаправим stdin и stdout
    FILE *original_input = stdin;
    FILE *original_output = stdout;
    stdin = fmemopen((void*)input, strlen(input), "r");
    stdout = output;

    // Запускаем вашу основную функцию
    process_input();

    // Восстанавливаем стандартный ввод и вывод
    stdin = original_input;
    stdout = original_output;

    // Закрываем буфер
    fflush(output);
    fclose(output);

    // Проверяем результат
    if (strncmp(buffer, expected_output, strlen(expected_output)) == 0) {
        printf("Тест пройден: \"input: %s\" => \"output: %s\"\n", input, buffer);
    } else {
        printf("Тест не пройден: \"input: %s\" => \"output: %s\", ожидалось: \"%s\"\n", input, buffer, expected_output);
    }
}

int main() {
    run_test("1 2 3\n", "YES\n");
    run_test("1 9 7\n", "NO\n");
    run_test("9 10 11 12\n", "YES\n");

    return 0;
}
