import re

item_found = r'^message ([1-8]), ([A-Za-z]+) ([1-7]) ([A-Za-z]+)$'
ready = r'^message ([1-8]), ([A-Za-z]+) ([1-7]) READY+$'

def check_broadcast_pattern(pattern: str, client):
    print(f"received broadcast pattern {pattern}")
    match = re.match(ready, pattern)
    if match:
        ready_for_upgrade_signal(match, client)
        return
    match = re.match(item_found, pattern)
    if match:
        item_found_signal(match, client)

def ready_for_upgrade_signal(match, client):
    k = int(match.group(1))
    team = match.group(2)
    level = int(match.group(3))
    if team != client.team:
        return
    if level != client.level or level == 1:
        return
    compute_direction(k, client)
    client.gathering = []
    return

def item_found_signal(match, client):
    k = int(match.group(1))
    team = match.group(2)
    level = int(match.group(3))
    item = match.group(4)
    if team != client.team:
        return
    if level != client.level or level == 1:
        return
    client.team_items[item] += 1
    return

def compute_direction(k,client):
    if k == 0:
        client.direction = []
    if k == 1:
        client.direction = ["Forward"]
    if k == 2:
        client.direction = ["Forward", "Left", "Forward", "Right"]
    if k == 3:
        client.reposition = ["Left"]
        client.direction = ["Forward"]
    if k == 4:
        client.reposition = ["Left", "Left"]
        client.direction = ["Forward", "Rigth", "Forward", "Left"]
    if k == 5:
        client.reposition = ["Left", "Left"]
        client.direction = ["Forward"]
    if k == 6:
        client.reposition = ["Left", "Left"]
        client.direction = ["Forward", "Left", "Forward", "Right"]
    if k == 7:
        client.reposition = ["Right"]
        client.direction = ["Forward"]
    if k == 8:
        client.direction = ["Forward", "Rigth", "Forward", "Left"]
