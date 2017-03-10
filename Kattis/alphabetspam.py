string = input()
low = 0
upe = 0
spa = 0
oth = 0
for letter in string:
    if letter.islower():
        low +=1
    elif letter.isupper():
        upe +=1
    elif letter == "_":
        spa +=1
    else:
        oth +=1
l = len(string)
print("{:0.16f}".format(spa/l))
print("{:0.16f}".format(low/l))
print("{:0.16f}".format(upe/l))
print("{:0.16f}".format(oth/l))
