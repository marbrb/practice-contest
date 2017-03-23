def solution(vals):
    lis = []
    for val in vals:
        if -val not in lis:
            lis.append(val)
        else:
            #no hay pedo
            return False
    #si no rompio arriba, si hay pedo
    return True

def main():
    universos, grupos = [int(x) for x in input().split()]
    for i in range(grupos):
        n, *vals = [int (x) for x in input().split()]

        if solution(vals):
            print("YES")
            return
    print("NO")
main()
