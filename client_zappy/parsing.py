##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-aurelien.duval
## File description:
## parsing
##

from client import *
from commands.movement_commands import *
import unittest
import sys
import io

class TestSendLookCommand(unittest.TestCase):

    def test_valid_response(self):
        # Mock the client and server response
        class MockClient:
            def write_response_to_socket(self, command):
                pass

            def receive_server_response(self):
                return "player, food, item,,,,,"

        client = MockClient()

        # Call the function and capture the output
        captured_output = io.StringIO()
        sys.stdout = captured_output

        send_look_command(client)

        # Restore sys.stdout
        sys.stdout = sys.__stdout__

        # Check the output
        expected_output = "[['player'], ['food'], ['item'], [''], [''], [''], ['']]\n"
        self.assertEqual(captured_output.getvalue(), expected_output)

    def test_invalid_response(self):
        # Mock the client and server response
        class MockClient:
            def write_response_to_socket(self, command):
                pass

            def receive_server_response(self):
                return "Unknown response"

        client = MockClient()

        # Call the function and capture the output
        captured_output = io.StringIO()
        sys.stdout = captured_output

        send_look_command(client)

        # Restore sys.stdout
        sys.stdout = sys.__stdout__

        # Check the output
        expected_output = "Unknown server response: Unknown response\n"
        self.assertEqual(captured_output.getvalue(), expected_output)

if __name__ == '__main__':
    unittest.main()
