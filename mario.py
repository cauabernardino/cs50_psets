from cs50 import get_int

height = 0
while height <= 0 or height > 8:
    height = get_int("Height: ")

for i in range(height):
    for j in range(height):
        if i + j < height - 1:
            print(" ", end="")
        else:
            print("#", end="")
    print()