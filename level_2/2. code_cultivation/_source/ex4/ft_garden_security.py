class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self._height = height
        self._age = age

    def show(self) -> None:
        info = f"{self.name}: {self._height:.1f}cm, {self._age} days old"
        print(f"Plant created: {info}")

    def grow(self) -> None:
        self._height += 0.8

    def grow_older(self) -> None:
        self._age += 1

    def set_height(self, height: float) -> None:
        if height < 0:
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = height
            print(f"Height updated: {self._height}cm")

    def set_age(self, age: int) -> None:
        if age < 0:
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age = age
            print(f"Age updated: {self._age} days")

    def get_age(self) -> int:
        return self._age

    def get_height(self) -> float:
        return self._height


if __name__ == "__main__":
    print("=== Garden Security System ===")
    rose = Plant("Rose", 15, 10)
    rose.show()
    print()
    rose.set_height(25)
    rose.set_age(30)
    print()
    rose.set_height(-10)
    rose.set_age(-10)
    print()
    info = f"{rose.name}: {rose.get_height():.1f}cm, {rose.get_age()} days old"
    print(f"Current state: {info}")
