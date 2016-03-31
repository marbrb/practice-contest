from sys import stdin
lines = stdin.read().splitlines()

for line in lines:
    words = 0
    lineSplit = line.split()
    string = str()

    for letter in line:
        if letter.isalpha():
            string += letter
        else:
            string += " "
    
    for algo in string.split():
        words += 1
        
    print(words)
     