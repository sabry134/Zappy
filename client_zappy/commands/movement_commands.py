import threading

def send_forward_command(client):
    command = "Forward\n"

    if len(client.cmd_buff) < 10:
        client.cmd_buff.append("Forward")
        client.write_response_to_socket(command)


def send_right_command(client):
    command = "Right\n"

    if len(client.cmd_buff) < 10:
        client.cmd_buff.append("Right")
        client.write_response_to_socket(command)

def send_left_command(client):
    command = "Left\n"

    if len(client.cmd_buff) < 10:
        client.cmd_buff.append("Left")
        client.write_response_to_socket(command)


def process_response(response):
    response_list = [x.strip() for x in response.split(',')]
    response_table = [[item] for item in response_list]
    return response_table

def send_look_command(client):
    command = "Look\n"

    if len(client.cmd_buff) < 10:
        print("Sending look command")
        client.cmd_buff.append("Look")
        client.write_response_to_socket(command)


def send_inventory_command(client) -> str:
    command = "Inventory\n"

    if len(client.cmd_buff) < 10:
        print("Sending inventory command")
        client.cmd_buff.append("Inventory")
        client.write_response_to_socket(command)

def send_broadcast_text_command(client, text: str):
    command = "Broadcast " + text + "\n"

    if len(client.cmd_buff) < 10:
        client.cmd_buff.append("Broadcast")
        client.write_response_to_socket(command)