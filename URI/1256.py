def printi(d, m):
    for i in range(m):
        if d[i] != []:
            aux = " -> ".join(d[i])
            print("{} -> {} -> \\".format(i, aux))
        else:
            print("{} -> \\".format(i))

def main():
    cases = int(input())
    for i in range(cases):
        m, c = [int(x) for x in input().split()]
        nums = [int(x) for x in input().split()]
        d = {x:[] for x in range(m)}
        for num in nums:
            a = num%m
            d[a].append(str(num))
        printi(d, m)
        if i < cases-1:
            print()

main()
