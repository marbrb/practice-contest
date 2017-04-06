from math import factorial
d = {}
def fact(n):
    global d
    if n not in d:
        d[n] = factorial(n)

    return d[n]

def cat_direct(n):
    return fact(2*n) // fact(n + 1) // fact(n)

def main():
    n = int(input())
    for i in range(n):
        x = int(input())
        print(cat_direct(x))
main()
