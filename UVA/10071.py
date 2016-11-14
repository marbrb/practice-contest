from sys import stdin
lines = stdin.read().splitlines()

for line in lines:
    a = line.split(" ")
    a[0] = int(a[0])
    a[1] = int(a[1])
    print ((a[0]*2)*a[1])
