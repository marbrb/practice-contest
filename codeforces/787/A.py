def solution(a, b, c, d):
    mult = 0
    seti = set()

    for i  in range(10000):
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
    return -1


def main():
    a, b = [int(x) for x in input().split()]
    c, d = [int(x) for x in input().split()]
    print(solution(a, b, c, d))

main()
