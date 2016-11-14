from sys import stdin
from collections import deque

lines = deque(stdin.read().splitlines())

while lines:
    first = lines.popleft()
    second = lines.popleft()
    if len(first) < len(second):
        print("no")
    else:
        print("go")
