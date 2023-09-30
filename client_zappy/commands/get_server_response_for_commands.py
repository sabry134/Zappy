##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-aurelien.duval
## File description:
## get_server_response_for_commands
##

from commands.movement_commands import send_inventory_command
from client import Client
from typing import Dict


def init_command() -> Dict[str, str]:
    command = {}
    command["Forward"] = "ok"
    command["Right"] = "ok"
    command["Left"] = "ok"
    command["Look"] = "ok" # Replace with the player tiles
    command["Inventory"] = "ok" # replace with the command
    command["Broadcast"] = "ok"
    command["Connect_nbr"] = 0
    command["Fork"] = "ok"
    command["Eject"] = "ok", "ko"
    command["Take"] = "ok", "ko"
    command["Set"] = "ok", "ko"
    command["Incantation"] = "Current level:"


    return command

def get_command_response(command: str) -> str:
    command_responses = init_command()
    return command_responses.get(command, "Unknown command")
