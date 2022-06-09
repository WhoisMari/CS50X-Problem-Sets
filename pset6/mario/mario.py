from cs50 import get_int

s = 0

while (s < 1 or s > 8):
    s = get_int("Height: ")

blanckspaces = s
hashes = 0
for i in range(s):
    blanckspaces -= 1
    hashes += 1
    print(" " * blanckspaces, end="")
    print("#" * hashes, end="")
    print("")