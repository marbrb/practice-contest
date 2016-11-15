from math import ceil
cases = eval(input())
booksList = []
for case in range(cases):
    booksList.append(eval(input()))

booksList.sort(reverse=True)
init = 0
aux = 3
groups = []

for x in range(ceil(cases/3)-1):
    groups.append(booksList[:aux-1])
    init = aux
    aux += 3
groups.append(booksList[init:] if len(booksList[init:])<3 else booksList[init:-1])

res = 0
for group in groups:
    res += sum(group)

print(res)
