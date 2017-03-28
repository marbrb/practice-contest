def solution(n, nums):
    lis = [x for x in range(n)]
    pivot = 0
    for a in nums:
        steps = a%len(lis)
        borr = (pivot + steps) % len(lis)
        print(lis[borr] +1 , end = " ")
        del lis[borr]
        pivot = borr


def main():
    n, k = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    solution(n, a)

main()
