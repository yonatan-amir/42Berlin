import random

ALL_ACHIEVEMENTS = [
    "Crafting Genius",
    "Strategist",
    "World Savior",
    "Speed Runner",
    "Survivor",
    "Master Explorer",
    "Treasure Hunter",
    "Unstoppable",
    "First Steps",
    "Collector Supreme",
    "Untouchable",
    "Sharp Mind",
    "Boss Slayer",
    "Hidden Path Finder",
]


def gen_player_achievements():
    count = random.randint(5, 10)
    return set(random.sample(ALL_ACHIEVEMENTS, count))


players = {
    "42": gen_player_achievements(),
    "24": gen_player_achievements(),
    "424": gen_player_achievements(),
    "242": gen_player_achievements(),
}

full_set = set(ALL_ACHIEVEMENTS)

print("=== Achievement Tracker System ===")
for name in players:
    print(f"Player {name}: {players[name]}")

all_achievements = set()
for name in players:
    all_achievements = all_achievements.union(players[name])
print(f"\nAll distinct achievements: {all_achievements}")
print()

common = set(ALL_ACHIEVEMENTS)
for name in players:
    common = common.intersection(players[name])
print(f"Common achievements: {common}")

print()
for name in players:
    others = set()
    for other_name in players:
        if other_name != name:
            others = others.union(players[other_name])
    print(f"Only {name} has: {players[name].difference(others)}")

print()
for name in players:
    print(f"{name} is missing: {full_set.difference(players[name])}")
