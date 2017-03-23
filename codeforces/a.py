def solution(a, b, c, d):
    mult = 0
    seti = set()

    while(1):
        aux = b + (mult*a)
        if aux not in seti:
            seti.add(aux)
        else:
            return aux

        aux = d + (mult*c)
        if aux not in seti:
            seti.add(aux)
        else:
            return aux
        mult += 1


def main():
    a, b = [int(x) for x in input().split()]
    c, d = [int(x) for x in input().split()]
    if b > d:
        if c > a:
            print(solution(a, b, c, d))
        else:
            print("-1")

    elif b < d:
        if c < a:
            print(solution(a, b, c, d))
        else:
            print("-1")

    else:
        print("1")

main()
