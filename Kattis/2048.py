change = False

def move(fila):
    global change
    for i in range(1, 4):
        if fila[i-1] == 0:
            del fila [i-1]
            fila.append(0)
        elif fila[i-1] == fila[i]:
            fila[i-1] = 2 * fila[i-1]
            change = True
            del fila[i]
            fila.append(0)

    return (fila)

def left(fila):
    global change
    for i in range(3):
        if not change:
            move(fila)

    return fila

def right(fila):
    return left(fila)[::-1]

def up(fila):
    return left(fila)

def down(fila):
    return right(fila)

def main():
    global change
    mat = [[int(x) for x in input().split()] for i in range(4)]
    op = int(input())

    if op == 0:
        for x in mat:
            change = False
            res = [str(y) for y in left(x)]
            for p in [res]:
                print(" ".join(p))

    elif op == 1:

        res = []
        for i in range(4):
            change = False
            res.append(up([x[i] for x in mat]))
        for i in range(4):
            print(" ".join([str(x[i]) for x in res]))

#TODO: terminar 2 y 3

main()
