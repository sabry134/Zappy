import math
from inventory import check_inventory
from inventory import ritual_needs
from inventory import check_tile_for_players
from broadcast import check_broadcast_pattern
from commands.movement_commands import *
from commands.players_commands import *
from commands.object_commands import *
from commands.status import *
from commands.look_movement import setup_movement
import subprocess

def decide_forward(client, response: str):
    client.cmd_buff.remove("Forward")

def decide_right(client, response: str):
    client.cmd_buff.remove("Right")

def decide_left(client, response: str):
    client.cmd_buff.remove("Left")

def check_tile_for_players(client, tile: str):
    players = tile.count("player")
    if players < ritual_needs[client.level]["players"]:
        return False
    return True

tile_order = [0, 2, 1, 3, 6, 12, 5, 7, 11, 13, 4, 8, 10, 14, 9, 15]

def pick_up_decision(client, tile, no) -> int:
    rarity_sorted = ["food", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"]
    for item in client.missing:
        if item == "player":
            continue
        if item in tile:
            if no == 0 and "Take" not in client.cmd_buff:
                print(f"attempting to pick up {item}")
                send_take_object_command(client, item)
                client.taking.append(item)
            return 3
    if "food" in tile:
        if no == 0 and "Take" not in client.cmd_buff:
            send_take_object_command(client, "food")
            client.taking.append("food")
        return 2
    for item in rarity_sorted:
        if item in tile:
            if no == 0 and "Take" not in client.cmd_buff:
                send_take_object_command(client, item)
                client.taking.append(item)
            return 1
    return 0

def check_tile_for_needed_items(client, tile):
    for item in ritual_needs[client.level]:
        if item == "players":
            continue
        if tile.count(item) < ritual_needs[client.level][item]:
            return False
    return True

def decide_look(client, response: str):
    client.cmd_buff.remove("Look")
    tile_list = [x.strip() for x in response.split(',')]
    tiles = []
    for tile in tile_list:
        tiles.append(tile.strip("[]").split(' '))
    for i in range(len(tiles), 16):
        tiles.append([])
    pick_up = 0
    pick_tile = 0
    
    print(f"current tile : {tiles[0]}")
    
    if client.status == NORMAL and client.level == 1 and check_tile_for_needed_items(client, tiles[0]):
        client.status = CHANTING
        return

    if check_tile_for_players(client, tiles[0]):
        if (client.status == JOINING or client.status == CALLING):
            client.status = SETTING
            return
        if client.status == WAITING and check_tile_for_needed_items(client, tiles[0]):
            client.status = CHANTING
            return
    
    if client.status == JOINING or client.status == CALLING or client.status == SETTING:
        return

    for tile_no in tile_order:
        tmp = pick_up_decision(client, tiles[tile_no], tile_no)
        if tmp > pick_up:
            pick_up = tmp
            pick_tile = tile_no
    
    if pick_up > 0:
        pick_up = 0
        if pick_tile > 0:
            setup_movement(client, pick_tile)
            pick_tile = 0
        return
    
    send_forward_command(client)

def decide_inventory(client, response: str):
    client.cmd_buff.remove("Inventory")
    if client.status != NORMAL:
        return
    client.missing = check_inventory(client, response)
    global_missing = True
    for item in client.missing:
        if client.missing[item] <= client.team_items[item]:
            global_missing = False
            break
    if client.missing == {}:
        global_missing = False
    if global_missing == False and client.level != 1:
        send_broadcast_text_command(client, f"{client.team} {client.level} READY")
        client.status = CALLING
    elif global_missing == False and client.level == 1:
        for item in ritual_needs[client.level]:
            if item == "players":
                continue
            for i in range(min(client.inventory[item], ritual_needs[client.level][item])):
                client.setting_items.append(item)
        client.status = SETTING

def decide_broadcast(client, response: str):
    client.cmd_buff.remove("Broadcast")

def decide_connect_nbr(client, response: str):
    client.cmd_buff.remove("Connect_nbr")
    #print(f"response to connect_nbr is : {response}")
    #num = int(response)
    #if num == 0 and client.inventory["food"] > 3:
    #    send_fork_command(client)

def decide_fork(client, response: str):
    client.cmd_buff.remove("Fork")
    if response == "ko":
        return
    command = ["python3", "zappy_ai", "-p", str(client.port), "-n", client.team, "-h", client.machine]
    print("About to fork to a subprocess")
    subprocess.Popen(command)

def decide_eject(client, response: str):
    client.cmd_buff.remove("Eject")

def decide_take(client, response: str):
    client.cmd_buff.remove("Take")
    if response == "ko" or client.taking[0] == "food":
        client.taking.pop(0)
        return
    if client.level > 1:
        if client.taking[0] == "thystame" and client.inventory["food"] > 3:
            send_fork_command(client)
        send_broadcast_text_command(client, f"{client.team} {client.level} {client.taking[0]}")
    client.taking.pop(0)

def decide_set(client, response: str):
    client.cmd_buff.remove("Set")

def decide_incantation_start(client, response: str):
    if "Incantation_start" in client.cmd_buff:
        client.cmd_buff.remove("Incantation_start")
    if response == "ko":
        client.status = 0
        return
    print("Elevation has started")

def decide_incantation_end(client, response: str):
    if "Incantation_end" in client.cmd_buff:
        client.cmd_buff.remove("Incantation_end")
    client.status = 0
    if response == "ko":
        return
    client.level += 1
    print("succesfully leveled up after incantation")

def died(client, response: str):
    client.status = DEAD

def decide_heard(client, response: str):
    check_broadcast_pattern(response, client)

def decide_ejected(client, response: str):
    pass
