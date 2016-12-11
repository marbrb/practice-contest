from sys import stdin

aux = "1"
di = dict()
aux = input()

while aux != '':
    lis = aux.split()
    di[lis[1]] = lis[0]
    aux = input()

words = stdin.read().split()
for word in words:
    try:
        print(di[word])
    except:
        print('eh')
