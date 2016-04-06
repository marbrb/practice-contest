from sys import stdin

lines = stdin.read().splitlines()
lenList = list()
for line in lines:
    lenList.append(len(line))


for letra in range(0, max(lenList)):
    string = str()
    for line in lines[::-1]:
        try:
            string += line[letra]
        except:
            string += " "
    print (string)