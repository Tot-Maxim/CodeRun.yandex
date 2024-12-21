import json
import unittest
from unittest.mock import patch
from io import StringIO
import sys
import os


sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))
from tskv_to_json import tskv_to_json


class TestTskvToJson(unittest.TestCase):

    @patch('builtins.input', side_effect=['key1=value1', 'key2=value2', ''])
    @patch('sys.stdout', new_callable=StringIO)

    def test_valid_input(self, mock_stdout, mock_input):
        tskv_to_json()
        output = mock_stdout.getvalue()
        expected_json = {
            "key1": "value1",
            "key2": "value2"
        }
        self.assertIn(json.dumps(expected_json, ensure_ascii=False, indent=4), output)
    @patch('builtins.input', side_effect=[''])
    @patch('sys.stdout', new_callable=StringIO)

    
    def test_empty_input(self, mock_stdout, mock_input):
        tskv_to_json()
        output = mock_stdout.getvalue()
        expected_json = {}
        self.assertIn(json.dumps(expected_json, ensure_ascii=False, indent=4), output)


if __name__ == '__main__':
    unittest.main()
