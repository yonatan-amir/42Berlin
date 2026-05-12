def print_error(Error, params=None, catch_param=None):
    catch_class = catch_param if catch_param else Error
    try:
        if params:
            raise Error(params)
        else:
            raise Error
    except catch_class as e:
        print(f"Caught {catch_class.__name__}: {e}")


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
        return f"The {self.plant_name} plant is wilting!"


class WaterError(GardenError):
    "For problems with watering (inherits from GardenError)"

    def __init__(self, message: str | None = None) -> None:
        super().__init__(message)

    def __str__(self) -> str:
        return "Not enough water in the tank!"


if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===")
    print()
    print("Testing PlantError...")
    print_error(PlantError, "tomato")
    print()
    print("Testing WaterError...")
    print_error(WaterError)
    print()
    print("Testing catching all garden errors...")
    print_error(PlantError, "tomato", catch_param=GardenError)
    print_error(WaterError, catch_param=GardenError)
    print()
    print("All custom error types work correctly!")
