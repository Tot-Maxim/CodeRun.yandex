from collections import Counter

class SortTools:

    def __init__(self):
        pass

    @staticmethod
    def sort_intervals(intervals):
        """Сортирует список интервалов по их длине."""
        def interval_length(interval):
            return interval[1] - interval[0]
        
        sorted_intervals = sorted(intervals, key=interval_length)
        return sorted_intervals

    @staticmethod
    def count_target_letters(my_list, target_letters):
        """Подсчитывает количество целевых букв в списке строк."""
        letter_count = {letter: 0 for letter in target_letters}
        for word in my_list:
            for letter in word:
                if letter in letter_count:
                    letter_count[letter] += 1
        return letter_count

    @staticmethod
    def count_all_letters(my_list):
        """Подсчитывает количество всех букв в списке строк."""
        combined = ''.join(my_list)  # Объединяем все строки в одну
        letter_count = Counter(combined)
        return letter_count

    @staticmethod
    def custom_letter_count(my_list):
        """Подсчитывает количество букв в списке строк (с использованием словаря)."""
        letter_count = {}
        for word in my_list:
            for letter in word:
                if letter in letter_count:
                    letter_count[letter] += 1
                else:
                    letter_count[letter] = 1
        return letter_count

    @staticmethod
    def check_even_numbers(my_list):
        """Проверяет, есть ли в списке хотя бы одно четное число."""
        return any(x % 2 == 0 for x in my_list)

    @staticmethod
    def check_value_in_list(my_list, value):
        """Проверяет, есть ли значение в списке."""
        return value in my_list


# Применение класса SortTools
if __name__ == "__main__":
    intervals = [(1, 5), (2, 3), (4, 10), (7, 8), (3, 7)]
    sorted_intervals = SortTools.sort_intervals(intervals)
    print("Отсортированные интервалы:", sorted_intervals)

    my_list = ["apple", "banana", "cherry"]
    target_letters = "aeiou"
    letter_counts = SortTools.count_target_letters(my_list, target_letters)
    print("Подсчет целевых букв:", letter_counts)

    all_letter_counts = SortTools.count_all_letters(my_list)
    print("Подсчет всех букв:", all_letter_counts)

    custom_letter_counts = SortTools.custom_letter_count(my_list)
    print("Пользовательский подсчет букв:", custom_letter_counts)

    my_list = [1, 3, 5, 7, 8]
    if SortTools.check_even_numbers(my_list):
        print("В списке есть хотя бы одно четное число.")
    else:
        print("Все числа в списке нечетные.")

    my_list = [1, 2, 3, 4, 5]
    value_to_check = 3
    if SortTools.check_value_in_list(my_list, value_to_check):
        print(f"{value_to_check} есть в списке.")
    else:
        print(f"{value_to_check} нет в списке.")
