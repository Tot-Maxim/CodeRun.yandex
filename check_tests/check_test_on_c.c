#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monotonic.h"
#include "saper.h"

// Объявление функции из другого файла
void process_input();
void process_saper();


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

void run_saper(const char *input, const char *expected_output) {
    // Создаем временные файлы для stdin и stdout
    FILE *original_input = stdin;
    FILE *original_output = stdout;
    char buffer[1024];  // Создаем буфер для захвата вывода
    FILE *output = fmemopen(buffer, sizeof(buffer), "w");

    if (!output) {
        perror("Ошибка при создании выходного буфера");
        return;
    }

    // Подменяем stdin на вводимые данные
    stdin = fmemopen((void*)input, strlen(input), "r");
    stdout = output;

    process_saper();

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

   
    run_saper("3 2 2\n1 1\n2 2\n", "* 2\n2 *\n1 1\n");
    run_saper("4 4 4\n1 3\n2 1\n4 2\n4 4\n", "1 2 * 1\n* 2 1 1\n2 2 2 1\n1 * 2 *\n");

    return 0;
}
