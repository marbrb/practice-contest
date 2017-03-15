
a  = [int(x) for x in input().split()]
barril = a[0]
diario = a[1]
MAX = barril

def main():
    global barril
    dia = 1
    if diario >= barril:
        print (barril)
        return
        
    while barril > 0:
        llenar(diario)
        barril -= dia
        dia += 1
    print(dia-1)


def llenar(diario):
    global barril
    posible = MAX - barril
    if posible < diario:
        barril = MAX
    elif posible == diario:
        barril = MAX
    else:
        barril += diario

main()
