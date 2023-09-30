from commands.status import *

def setup_movement(client, tile_no):
    if tile_no == 1:
        client.gathering = ["Forward", "Left", "Forward"]
    elif tile_no == 2:
        client.gathering = ["Forward"]
    elif tile_no == 3:
        client.gathering = ["Forward", "Right", "Forward"]
    elif tile_no == 4:
        client.gathering = ["Forward", "Forward", "Left", "Forward", "Forward"]
    elif tile_no == 5:
        client.gathering = ["Forward", "Forward", "Left", "Forward"]
    elif tile_no == 6:
        client.gathering = ["Forward", "Forward"]
    elif tile_no == 7:
        client.gathering = ["Forward", "Forward", "Right", "Forward"]
    elif tile_no == 8:
        client.gathering = ["Forward", "Forward", "Right", "Forward", "Forward"]
    elif tile_no == 9:
        client.gathering = ["Forward", "Forward", "Forward", "Left", "Forward", "Forward", "Forward"]
    elif tile_no == 10:
        client.gathering = ["Forward", "Forward", "Forward", "Left", "Forward", "Forward"]
    elif tile_no == 11:
        client.gathering = ["Forward", "Forward", "Forward", "Left", "Forward"]
    elif tile_no == 12:
        client.gathering = ["Forward", "Forward", "Forward"]
    elif tile_no == 13:
        client.gathering = ["Forward", "Forward", "Forward", "Right", "Forward"]
    elif tile_no == 14:
        client.gathering = ["Forward", "Forward", "Forward", "Right", "Forward", "Forward"]
    elif tile_no == 15:
        client.gathering = ["Forward", "Forward", "Forward", "Right", "Forward", "Forward", "Forward"]
    client.status = GATHERING
