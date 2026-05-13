import sys

inventory = {}

print("=== Inventory System Analysis ===")
for arg in sys.argv[1:]:
    parts = arg.split(":")
    if len(parts) != 2:
        print(f"Error - invalid parameter '{arg}'")
        continue
    name = parts[0]
    if name in inventory:
        print(f"Redundant item '{name}' - discarding")
        continue
    try:
        quantity = int(parts[1])
        inventory[name] = quantity
    except ValueError as e:
        print(f"Quantity error for '{name}': {e}")

print(inventory)
print(f"Item list: {list(inventory.keys())}")
total = 0
for item in inventory:
    total += inventory[item]
print(f"Total quantity of the {len(inventory.keys())} items: {total}")
