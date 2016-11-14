from sys import stdin
from collections import deque

lines = stdin.read().splitlines()
for line in lines:
    splitLine = line.split()
    num1 = int(splitLine[0])
    num2 = int(splitLine[1])
    print(abs(num1-num2))
