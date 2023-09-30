import re

def send_take_object_command(client, item: str):
    command = "Take " + item + "\n"
    print(f"Attempting to send command {command}")
    if len(client.cmd_buff) < 10:
        client.cmd_buff.append("Take")
        client.write_response_to_socket(command)

def send_set_object_command(client, item: str):
    command = "Set " + item + "\n"

    if len(client.cmd_buff) < 10:
        client.cmd_buff.append("Set")
        client.write_response_to_socket(command)

def send_incantation_command(client):
    command = "Incantation\n"

    if len(client.cmd_buff) < 10:
        client.cmd_buff.append("Incantation_start")
        client.cmd_buff.append("Incantation_end")
        client.write_response_to_socket(command)
