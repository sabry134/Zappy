import unittest
import sys
import io
from client import Client

class TestResponseChecker(unittest.TestCase):

    def test_unknown(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Forward")

        test_response = "ko"
        expected = 0
        self.assertEqual(client.check_response(test_response), expected)

    def test_movement_response(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Forward")

        test_response = "ok"
        expected = 1
        self.assertEqual(client.check_response(test_response), expected)
    
    def test_connect_number_response_correct(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Forward")
        client.cmd_buff.append("Connect_nbr")

        test_response = "53"
        expected = 1
        self.assertEqual(client.check_response(test_response), expected)
    
    def test_connect_number_response_incorrect(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Forward")
        client.cmd_buff.append("Connect_nbr")

        test_response = "a"
        expected = 0
        self.assertEqual(client.check_response(test_response), expected)
    
    def test_eject_response_correct(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Eject")

        test_response = "ok"
        expected = 1
        self.assertEqual(client.check_response(test_response), expected)
    
    def test_eject_response_correct2(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Eject")

        test_response = "ko"
        expected = 1
        self.assertEqual(client.check_response(test_response), expected)
    
    def test_eject_response_incorrect(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Eject")

        test_response = "asd"
        expected = 0
        self.assertEqual(client.check_response(test_response), expected)
    
    def test_incantation_response_correct(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Incantation")

        test_response = "Elevation underway Current level: 5"
        expected = 1
        self.assertEqual(client.check_response(test_response), expected)
    
    def test_incantation_response_correct2(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Incantation")

        test_response = "ko"
        expected = 1
        self.assertEqual(client.check_response(test_response), expected)
    
    def test_incantation_response_incorrect(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Incantation")

        test_response = "Elevation underway Current level: 9"
        expected = 0
        self.assertEqual(client.check_response(test_response), expected)
    
    def test_look_response_correct(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Look")

        test_response = "[food, limestone food, player,,player food, test]"
        expected = 1
        self.assertEqual(client.check_response(test_response), expected)
    
    def test_look_response_incorrect(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Look")

        test_response = "ok"
        expected = 0
        self.assertEqual(client.check_response(test_response), expected)
    
    def test_inventory_response_correct(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Inventory")

        test_response = "[food 4, limestone 2]"
        expected = 1
        self.assertEqual(client.check_response(test_response), expected)
    
    def test_inventory_response_incorrect(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Inventory")

        test_response = "ok"
        expected = 0
        self.assertEqual(client.check_response(test_response), expected)
    
    def test_inventory_response_incorrect2(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Inventory")

        test_response = "[food 4, limestone, test 12]"
        expected = 0
        self.assertEqual(client.check_response(test_response), expected)
    
    def test_dead_response(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Inventory")

        test_response = "dead"
        expected = 2
        self.assertEqual(client.check_response(test_response), expected)
    
    def test_message_response(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Inventory")

        test_response = "message 5, hello asdkjlh"
        expected = 2
        self.assertEqual(client.check_response(test_response), expected)
    
    def test_ejected_response(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Inventory")

        test_response = "eject: S"
        expected = 2
        self.assertEqual(client.check_response(test_response), expected)

if __name__ == '__main__':
    unittest.main()