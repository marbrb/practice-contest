k = int(input())
num = 0
ex = 1
while num < k:
    num = 2**ex
    ex += 1

print(num, len(bin(k)[2:].strip("0")))
