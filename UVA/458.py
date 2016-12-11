from sys import stdin
lines = stdin.read().splitlines()

for line in lines:
    for letter in line:
        d = ord(letter)
        print("%c"%(d-7), end="")
    print()
