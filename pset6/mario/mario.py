from cs50 import get_int


while True:
    pyramid_height = get_int("Enter the height of the pyramid: ")
    if (pyramid_height >= 1) and (pyramid_height <= 8):
        break

for level in range(pyramid_height):
    spaces = pyramid_height - level - 1
    print(" " * spaces, end="")
    hashes = level + 1
    print("#" * hashes)





