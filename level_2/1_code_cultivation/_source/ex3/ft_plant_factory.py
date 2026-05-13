class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self) -> None:
        info = f"{self.name}: {self.height:.1f}cm, {self.age} days old"
        print(f"Created: {info}")

    def grow(self) -> None:
        self.height += 0.8

    def grow_older(self) -> None:
        self.age += 1


if __name__ == "__main__":
    print("=== Plant Factory Output ===")
    rose = Plant("Rose", 25, 30)
    rose.show()
    dak = Plant("Dak", 200, 365)
    dak.show()
    cactus = Plant("Cactus", 5, 90)
    cactus.show()
    sunflower = Plant("Sunflower", 80, 45)
    sunflower.show()
    fern = Plant("Fern", 15, 120)
    fern.show()
