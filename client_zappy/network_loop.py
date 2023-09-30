from client import Client
from commands.movement_commands import *
from commands.object_commands import *
from commands.players_commands import *
from commands.status import *
import threading

def network_loop(client: Client):
        response = ""
        
        while True:
            if client.status == DEAD:
                break
            try:
                response += client.sock.recv(1024).decode()
            except Exception as e:
                print(f"Error receiving response: {str(e)}")
            if response != "" and response[-1] == '\n':
                print(f"received response : {response}")
                client.check_response(response)
                response = ""
            if client.status == CHANTING:
                if len(client.cmd_buff) == 0:
                    send_incantation_command(client)
                continue
            if client.status == SETTING:
                if "Set" not in client.cmd_buff:
                    set_needed_items(client)
                continue
            if client.status == JOINING:
                join_incant()
            if client.status == GATHERING:
                gather(client)
                continue
            if "Look" not in client.cmd_buff:
                send_look_command(client)
            if "Inventory" not in client.cmd_buff:
                send_inventory_command(client)

        client.sock.close()

def gather(client: Client):
    while len(client.cmd_buff) < 10:
        if len(client.gathering) > 0:
            if client.gathering[0] == "Left":
                send_left_command(client)
                client.gathering.pop(0)
            elif client.gathering[0] == "Right":
                send_right_command(client)
                client.gathering.pop(0)
            else:
                send_forward_command(client)
                client.gathering.pop(0)
        else:
            client.status = NORMAL
            break

def set_needed_items(client: Client):
    if len(client.setting_items) == 0:
        if client.level == 1:
            print("set status to chanting")
            client.status = CHANTING
        else:
            client.status = WAITING
        return
    while len(client.setting_items) > 0:
        if len(client.cmd_buff) == 10:
            continue
        send_set_object_command(client, client.setting_items[0])
        client.setting_items.pop(0)

def all_items_set(items):
    for item in items:
        if items[item] > 0:
            return False
    return True 

def join_incant(client: Client):
    while len(client.cmd_buff) < 10:
        if len(client.reposition) > 0:
            if client.reposition[0] == "Left":
                send_left_command(client)
                client.reposition.pop(0)
            else:
                send_right_command(client)
                client.reposition.pop(0)
            continue
        if client.direction[client.direction_index] == "Forward":
            send_forward_command(client)
        elif client.direction[client.direction_index] == "Left":
            send_left_command(client)
        else:
            send_right_command(client)
        client.direction_index = client.direction_index % len(client.direction)
