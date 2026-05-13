import sys


def to_int(arg):
    try:
        return int(arg)
    except ValueError:
        print(f"Invalid parameter: '{arg}'")
        return None


def script():
    print("=== Player Score Analytics ===")
    scores = [to_int(arg) for arg in sys.argv[1:]]
    scores = [s for s in scores if s is not None]

    if not scores:
        print(
            f"No scores provided. Usage: python3 ft_score_analytics.py <score1> <score2> ..."
        )
        return

    print(f"Scores processed: {scores}")
    print(f"Total players: {len(scores)}")
    print(f"Total score: {sum(scores)}")
    print(f"Average score: {sum(scores) / len(scores)}")
    print(f"High score: {max(scores)}")
    print(f"Low score: {min(scores)}")
    print(f"Score range: {max(scores) - min(scores)}")


script()
