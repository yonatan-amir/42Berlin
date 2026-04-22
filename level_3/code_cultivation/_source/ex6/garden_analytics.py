class Plant:
    def __init__(
            self,
            name: str,
            height: float,
            age: int
    ) -> None:
        self.name = name
        self._height = height
        self._age = age
        self._statistics = self.Statistics()

    class Statistics:
        def __init__(self) -> None:
            self._show_calls = 0
            self._age_calls = 0
            self._grow_calls = 0

        def record_show(self) -> None:
            self._show_calls += 1

        def record_age(self) -> None:
            self._age_calls += 1

        def record_grow(self) -> None:
            self._grow_calls += 1

        def display(self) -> None:
            print( f"Stats: {self._grow_calls} grow, {self._age_calls} age, {self._show_calls} show")

    def show(self) -> None:
        print(f"{self.name}: {self._height:.1f}cm, {self._age} days old")
        self._statistics.record_show()

    def grow(self) -> None:
        self._height += 8
        self._statistics.record_grow()

    def age(self) -> None:
        self._age += 1
        self._statistics.record_age()

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

    def show_statistics(self):
        self._statistics.display()

    @staticmethod
    def plant_older_than_year(age: int) -> bool:
        return age > 365

    @classmethod
    def anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0)

class Flower(Plant):
    def __init__(
            self,
            name: str,
            height: float,
            age: int,
            color: str
    ) -> None:
        super().__init__(name, height, age)
        self._color = color
        self._bloom = False



    def show(self) -> None:
        super().show()
        print(f" Color: {self.get_color()}")
        self.is_blooming()

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
    def __init__(
            self,
            name: str,
            height: float,
            age: int,
            trunk_diameter: float
    ) -> None:
        super().__init__(name, height, age)
        self._statistics: "Tree.Statistics" = self.Statistics()
        self._trunk_diameter = trunk_diameter
        self._shade = False

    class Statistics(Plant.Statistics):
        def __init__(self) -> None:
            super().__init__()
            self._shade_calls = 0

        def record_shade(self) -> None:
            self._shade_calls += 1

        def display(self) -> None:
            super().display()
            print(f" {self._shade_calls} shade")

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.get_trunk_diameter():.1f}cm")

    def produce_shade(self) -> None:
        self._shade = True
        self._statistics.record_shade()

    def get_shade(self) -> None:
        if not self._shade:
            print(f"Tree {self.name} is not producing shade yet")
        else:
            print(f"Tree {self.name} now produces a shade of {self._height:.1f}cm long and {self._trunk_diameter:.1f}cm wide.")

    def get_trunk_diameter(self) -> float:
        return self._trunk_diameter

class Vegetable(Plant):
    def __init__(self, name: str, height: float, age: int, harvest_season: str)-> None:
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

def display_statistics(plant: Plant) -> None:
    plant.show_statistics()


class Seed(Flower):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age, color)
        self._seed_count = 0

    def get_seed_count(self) -> int:
        return self._seed_count

    def show(self) -> None:
        super().show()
        print(f" Seeds: {self._seed_count:.0f}")

    def age(self) -> None:
        super().age()
        self._age += 19
        # if self._bloom:
        #     self._seed_count += 1

    def grow(self) -> None:
        super().grow()
        self._height += 22
        if self._bloom:
            self._seed_count = 42


if __name__ == "__main__":
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.plant_older_than_year(30)}")
    print(f"Is 400 days more than a year? -> {Plant.plant_older_than_year(400)}")
    print()
    print("=== Flower")
    rose = Flower("Rose", 15, 10, "red")
    rose.show()
    print("[statistics for Rose]")
    rose.show_statistics()
    print("[asking the rose to grow and bloom]")
    rose.grow()
    rose.bloom()
    rose.show()
    print("[statistics for Rose]")
    rose.show_statistics()
    print()
    print("=== Tree")
    tree = Tree("Oak", 200, 365, 5)
    tree.show()
    print("[statistics for Oak]")
    tree.show_statistics()
    print("[asking the oak to produce shade]")
    tree.produce_shade()
    tree.get_shade()
    print("[statistics for Oak]")
    tree.show_statistics()
    print()
    print("=== Seed")
    sunflower = Seed("Sunflower", 80, 45, "yellow")
    sunflower.show()
    print("[make sunflower grow, age and bloom]")
    sunflower.bloom()
    sunflower.grow()
    sunflower.age()
    sunflower.show()
    print("[statistics for Sunflower]")
    sunflower.show_statistics()
    print()
    print("=== Anonymous")
    anonymous = Plant.anonymous()
    anonymous.show()
    print("[statistics for Unknown plant]")
    anonymous.show_statistics()


