from typing import Dict

ritual_needs = {
    1: {
        'players': 1,
        'linemate': 1,
        'deraumere': 0,
        'sibur': 0,
        'mendiane': 0,
        'phiras': 0,
        'thystame': 0
    },
    2: {
        'players': 2,
        'linemate': 1,
        'deraumere': 1,
        'sibur': 1,
        'mendiane': 0,
        'phiras': 0,
        'thystame': 0
    },
    3: {
        'players': 2,
        'linemate': 2,
        'deraumere': 0,
        'sibur': 1,
        'mendiane': 0,
        'phiras': 2,
        'thystame': 0
    },
    4: {
        'players': 4,
        'linemate': 1,
        'deraumere': 1,
        'sibur': 2,
        'mendiane': 0,
        'phiras': 1,
        'thystame': 0
    },
    5: {
        'players': 4,
        'linemate': 1,
        'deraumere': 2,
        'sibur': 1,
        'mendiane': 3,
        'phiras': 0,
        'thystame': 0
    },
    6: {
        'players': 6,
        'linemate': 1,
        'deraumere': 2,
        'sibur': 3,
        'mendiane': 0,
        'phiras': 1,
        'thystame': 0
    },
    7: {
        'players': 6,
        'linemate': 2,
        'deraumere': 2,
        'sibur': 2,
        'mendiane': 2,
        'phiras': 2,
        'thystame': 1
    }
}

def init_inventory() -> Dict[str, int]:
    inventory = {}
    inventory["food"] = 0
    inventory["linemate"] = 0
    inventory["deraumere"] = 0
    inventory["sibur"] = 0
    inventory["mendiane"] = 0
    inventory["phiras"] = 0
    inventory["thystame"] = 0

    return inventory

def get_inventory(client, inventory_str: str) -> Dict[str, int]:
    # we initialize a dict to store the items
    inventory = init_inventory()

    # we split the string into a list of items and their quantity
    items = inventory_str.split(",")

    # iterate through items in the inventory and add them to the dict
    for item in items:
        item = item.strip()
        item = item.strip("[")
        item = item.strip("]")
        item_name, item_quantity = item.split()
        item_quantity = int(item_quantity)
        inventory[item_name] = item_quantity
    
    print(f"player inventory is {inventory}")
    
    client.inventory = inventory

def check_inventory(client, response: str):
    # get the inventory
    get_inventory(client, response)

    missing = {}

    # we check if we are missing items for the next levelup
    for item in ritual_needs[client.level]:
        if item == "players":
            continue
        q = ritual_needs[client.level][item]
        if q > client.inventory[item]:
            missing[item] = q - client.inventory[item]

    print(f"missing items are {missing}")
    return missing

def check_tile_for_players(client, tile: str):
    players = tile.count("player")
    if players < ritual_needs[client.level]["players"]:
        return False
    return True