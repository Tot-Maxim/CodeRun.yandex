import unittest
from unittest.mock import patch
from io import StringIO
import json
import sys
import os

# Добавляем путь к родительскому каталогу, чтобы импортировать tskv_to_json.py
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

# Импорт функции для тестирования
from tskv_to_json import tskv_to_json


class TestTskvToJson(unittest.TestCase):

    @patch('builtins.input', side_effect=['key1=value1', 'key2=value2', ''])

    @patch('sys.stdout', new_callable=StringIO)

    def test_tskv_to_json(self, mock_stdout, mock_input):

        tskv_to_json()

        # Получаем выведенный результат

        output = mock_stdout.getvalue()


        # Ожидаемый результирующий JSON

        expected_json = {

            "key1": "value1",

            "key2": "value2"

        }


        # Проверяем, что вывод содержит ожидаемый JSON

        self.assertIn("Результирующий JSON:", output)

        self.assertIn(json.dumps(expected_json, ensure_ascii=False, indent=4), output)


if __name__ == '__main__':
    unittest.main()
