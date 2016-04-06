from sys import stdin
lines = stdin.read().splitlines()

cases = int(lines[0])
start = 2
finish = 3

maxLine = int(lines[start])
repeat = int(lines[finish])
for case in range(0,cases):
    for r in range(0,repeat):
        for x in range(1,maxLine+1):
            print(str(x)*x)

        for x in range(-maxLine+1, 0):
            print(str(-x)*-x)

        if case == cases-1 and r ==repeat-1:
            break
        print()
        start += 3
        finish += 3
