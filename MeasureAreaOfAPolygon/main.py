import os
from PolygonArea import polygon_area

lats = []
longs = []


def print_area():
    try:
        area = polygon_area(lats, longs)
        print('# Geodesic area: {:12.3f} m²'.format(area))
        print('#                {:12.3f} km²'.format(area/1e6))
    except ValueError as err:
        print(err)


def calculate_print_area():
    print_area()
    lats.clear()
    longs.clear()


def parse_input(data):
    for line in data:
        if line:
            a, b = line.split(",")
            a.replace(" ", "")
            b.replace(" ", "")
            lats.append(float(a))
            longs.append(float(b))
        else:
            calculate_print_area()
    calculate_print_area()


if __name__ == "__main__":

    dir = os.path.abspath(os.path.dirname(__file__))
    with open(os.path.join(dir, "input.txt")) as file:
        data = file.read().splitlines()
        parse_input(data)
