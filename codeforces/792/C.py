def right(num):
    while len(num) > 0:
        if int(num)%3 == 0:
            if num[0] == '0' and len(num) > 1:
                return num[1:]
            return num
        num = num[:-1]

    return "-1"

def left(num):
    while len(num) > 0:
        print(num)
        if int(num)%3 == 0:
            if num[0] == '0' and len(num) > 1:
                return num[1:]
            return num
        num = num[1:]

    return "-1"

def main():
    num = input()
    r = right(num)
    l = left(num)
    if r == -1:
        print(left(num))
    else:
        print(r)

main()
