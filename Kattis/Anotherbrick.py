height, width, num_bricks = input().split()
widths_list = [int(x) for x in input().split()]

res = 0
h = 0
width = int(width)
while widths_list:
    res += widths_list.pop(0)
    if res == width:
        h += 1
        if h == int(height):
            print("YES")
            break
        res = 0
    elif res > width:
        print("NO")
        break
