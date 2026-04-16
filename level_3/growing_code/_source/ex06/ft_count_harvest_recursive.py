def ft_count_harvest_recursive():
    days = int(input("Days until harvest: "))

    def recursion(current):
        if current > days:
            return
        print("Day", current)
        recursion(current + 1)

    recursion(1)
    print("Harvest time!")
