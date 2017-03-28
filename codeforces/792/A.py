MAX = 2e10
def solution(nums):
    dis = dict()
    dista = MAX
    for i in range(0,len(nums)-1):
        mini = abs(nums[i]-nums[i+1])
        if dis.get(mini) == None:
            dis[mini] = 1
        else:
            dis[mini] += 1

        dista = min(dista,mini)

    return "{} {}".format(dista, dis[dista])

def main():
    n = input()
    nums = sorted([int(x) for x in input().split()])
    print(solution(nums))
main()
