def moreTicks(lis):
    mins = lis[0][0], lis[0][1]
    min = lis[0][1]/lis[0][0]
    for x,y in lis[1:]:
        if y/x == min and y>lis[0][1]:
            mins = x,y
        else:
            break
    return mins

while 1:
    numLines, numTic = [int(x) for x in input().split()]
    if numLines == 0 and numTic == 0:
        break
    vals = []
    mins = int()

    for i in range(0, numLines):
        a, b =  [int(x) for x in input().split()]
        if a <= numTic:
            vals.append((a,b))
    vals.sort(key=lambda x: x[1]/x[0])

    if vals:
        mins = moreTicks(vals)
    try:
        print("Buy {} tickets for ${}".format(mins[0],mins[1]))
    except:
        print("No suitable tickets offered")
