def is_palindrome(s):

    # Удаляем все непробельные символы и приводим к нижнему регистру

    cleaned = ''.join(char.lower() for char in s if char.isalnum())

    # Проверяем, является ли строка палиндромом

    return cleaned == cleaned[::-1]


def main():

    # Запрос ввода строки у пользователя

    user_input = input("Введите строку, которую хотите проверить на палиндром: ")

    # Проверка на палиндром

    if is_palindrome(user_input):

        print(f'"{user_input}" — это палиндром!')

    else:

        print(f'"{user_input}" — это не палиндром.')


if __name__ == "__main__":

    while True:
        main()