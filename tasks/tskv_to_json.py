import json


def tskv_to_json():

    tskv_dict = {}

    print("Введите значения в формате key=value (или нажмите Enter, чтобы выйти):")

    while True:

        entry = input()  # Считываем ввод

        if entry.strip() == "":

            break  # Выход из цикла при пустой строке

        try:

            key, value = entry.split('=', 1)  # Разделяем только по первому =, чтобы поддерживать значения с =

            tskv_dict[key.strip()] = value.strip()  # Добавляем в словарь

        except ValueError:

            print("Неверный формат. Пожалуйста, используйте формат key=value.")


    json_output = json.dumps(tskv_dict, ensure_ascii=False, indent=4)

    print(json_output)
