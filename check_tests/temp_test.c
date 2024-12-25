#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "saper.h"

// Объявление функции из другого файла
void process_saper();

void run_test(const char *input, const char *expected_output) {
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
    // Тестовые кейсы
    run_test("3 2 2\n1 1\n2 2\n", "* 2\n2 *\n1 1\n"); // Тест 1
    run_test("4 4 4\n1 3\n2 1\n4 2\n4 4\n", "1 2 * 1\n* 2 1 1\n2 2 2 1\n1 * 2 *\n"); // Тест 2

    return 0;
}
