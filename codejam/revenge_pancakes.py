cases = int(input())

def invert(string):
    ind = string.rfind("-")
    newString = string[ind+1:]
    if ind == 0:
        return("+"+string[1:])
    elif ind == -1:
        return string

    for item in string[:ind+1][::-1]:
        if item == "-":
            newString = "+" + newString
        else:
            newString = "-" + newString
    return(newString)

for case in range(1, cases+1):
    INstring = input()
    cont = 0
    if "-" not in INstring:
        print("Case #" + str(case) + ": 0")
        continue
    algo = invert(INstring)
    cont += 1
    while True:
        if "-" in algo:
            algo = invert(algo)
            cont += 1
        else:
            break
    print("Case #" + str(case) + ": " + str(cont))
