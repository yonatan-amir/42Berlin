class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self._height = height
        self._age = age

    def show(self) -> None:
        print(f"{self.name}: {self._height:.1f}cm, {self._age} days old")

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


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self._color = color
        self._bloom = False

    def show(self) -> None:
        super().show()
        print(f" Color: {self.get_color()}")

    def is_blooming(self) -> None:
        if not self._bloom:
            print(f" {self.name} has not bloomed yet")
        else:
            print(f" {self.name} is blooming beautifully!")

    def bloom(self) -> None:
        self._bloom = True

    def get_color(self) -> str:
        return self._color


class Tree(Plant):
    def __init__(self,
                 name: str,
                 height: float,
                 age: int,
                 trunk_diameter: float
                 ) -> None:
        super().__init__(name, height, age)
        self._trunk_diameter = trunk_diameter
        self._shade = False

    class Statistics:
        def __init__(self) -> None:
            super().__init__()
            self._shade_calls = 0

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.get_trunk_diameter():.1f}cm")

    def produce_shade(self) -> None:
        self._shade = True
        self._statistics._shade_calls += 1

    def get_shade(self) -> None:
        if not self._shade:
            print(f"Tree {self.name} is not producing shade yet")
        else:
            shade = (
                f"Tree {self.name} now produces a shade of "
                f"{self._height:.1f}cm long and "
                f"{self._trunk_diameter:.1f}cm wide."
            )
            print(shade)

    def get_trunk_diameter(self) -> float:
        return self._trunk_diameter


class Vegetable(Plant):
    def __init__(
            self, name: str, height: float,
            age: int, harvest_season: str) -> None:
        super().__init__(name, height, age)
        self._harvest_season = harvest_season
        self._nutritional_value = 0

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.get_harvest_season()}")
        print(f" Nutritional value: {self.get_nutritional_value()}")

    def get_harvest_season(self) -> str:
        return self._harvest_season

    def get_nutritional_value(self) -> str:
        return str(self._nutritional_value)

    def grow(self) -> None:
        self._height += 2.1

    def age(self) -> None:
        self._age += 1

    def increase_nutrients(self) -> None:
        self._nutritional_value += 1


if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    print("=== Flower")
    rose = Flower("Rose", 15, 10, "red")
    rose.show()
    rose.is_blooming()
    print("[asking the rose to bloom]")
    rose.bloom()
    rose.show()
    rose.is_blooming()
    print()
    print("=== Tree")
    tree = Tree("Oak", 200, 365, 5)
    tree.show()
    print("[asking the oak to produce shade]")
    tree.produce_shade()
    tree.get_shade()
    print()
    print("=== Vegetable")
    tomato = Vegetable("Tomato", 5, 10, "April")
    tomato.show()
    print("[make tomato grow and age for 20 days]")
    for i in range(20):
        tomato.grow()
        tomato.age()
        tomato.increase_nutrients()
    tomato.show()
