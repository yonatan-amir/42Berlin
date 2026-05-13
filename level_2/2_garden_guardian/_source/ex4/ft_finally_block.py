class GardenError(Exception):
    "Exception raised for all errors found"

    def __init__(self, message: str | None = None) -> None:
        super().__init__(message)
        self.message = message


class PlantError(GardenError):
    "For problems with plants (inherits from GardenError)"

    def __init__(self, plant_name: str, message: str | None = None) -> None:
        super().__init__(message)
        self.plant_name = plant_name

    def __str__(self) -> str:
        return f"Invalid plant name to water: '{self.plant_name}'"


def water_plant(plant_name):
    if plant_name == plant_name.capitalize():
        print(f"Watering {plant_name}: [OK]")
    else:
        raise PlantError(plant_name)


def test_watering_system():
    print("Testing valid plants...")
    print("Opening watering system")
    try:
        for plant in ["Tomato", "Lettuce", "Carrots"]:
            water_plant(plant)
    except PlantError as e:
        print(f"Caught PlantError: {e}")
        print(".. ending tests and returning to main")
    finally:
        print("Closing watering system")
    print()
    print("Testing invalid plants...")
    print("Opening watering system")
    try:
        for plant in ["Tomato", "lettuce"]:
            water_plant(plant)
    except PlantError as e:
        print(f"Caught PlantError: {e}")
        print(".. ending tests and returning to main")
    finally:
        print("Closing watering system")


if __name__ == "__main__":
    print("=== Garden Watering System ===")
    print()
    test_watering_system()
    print()
    print("Cleanup always happens, even with errors!")
