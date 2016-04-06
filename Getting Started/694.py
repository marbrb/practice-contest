def terms(A, limit):
    cont = 0
    while A <= limit:    #menor o igual depronto
        if A == 1:
            cont += 1
            break
        if A%2 == 0:
            A /= 2
            cont += 1
        else:
            A = (A*3) + 1
            cont += 1
    return cont

case = 1
while True:
    line= input().split()
    num = int(line[0])
    lim = int(line[1])
    if num < 0 and lim < 0:
        break
    
    print("Case " + str(case) + ": " + "A = "+ line[0] + ", limit = " + line[1] + ", number of terms = " + str(terms(num, lim)) )
    case += 1