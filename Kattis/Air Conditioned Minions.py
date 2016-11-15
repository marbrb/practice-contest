numMinions = int(input())
listRanges = []

for i in range(numMinions):
    st = input().split()
    num1 = int(st[0])
    num2 = int(st[1])+1
    listRanges.append(set(range(num1,num2)))
print(listRanges)

def comp(item, lis):
    i = item
    for x in lis:
        if not item.intersection(x):
            i = x
            break
    # print(i)
    # print(lis)
    # print(lis.index(i))
    return(lis.index(i)+1)
i = 0
cont = 0
while listRanges[i:]:
# while cont <1:
    i = comp(listRanges[i], listRanges[i+1:])
    print(i)
    cont += 1
print(cont)
