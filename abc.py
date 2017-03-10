nums = [int(x) for x in input().split()]
nums.sort()
abc = input()
dic = dict(zip(["A","B","C"], nums))
for x in abc: print(dic[x], end=" ")
