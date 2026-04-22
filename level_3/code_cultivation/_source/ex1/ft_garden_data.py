class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self) -> None:
        print(f"{self.name}: {round(self.height, 1)}cm, {self.age} days old")
    def grow(self) -> None:
        self.height += 0.8
    def grow_older(self) -> None:
        self.age += 1

if __name__ == "__main__":
    print("=== Garden Plant Growth ===")
    rose = Plant("Rose", 25, 30)
    initial_height = rose.height
    rose.show()
    for i in range(7):
        print(f"=== Day {i+1} ===")
        rose.grow()
        rose.grow_older()
        rose.show()
    print(f"Growth this week: {round(rose.height - initial_height, 1)}cm")