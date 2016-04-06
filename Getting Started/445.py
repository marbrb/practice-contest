from sys import stdin
lines = stdin.read().splitlines()

num = 0
for line in lines:
    string = ""
    for letter in line:
        if letter != "!" and letter != "\n":
            if letter.isdigit():
                num += int(letter)
                
            elif letter.isalpha() and letter != "b":
                string += (letter*num)
                num = 0
            
            elif letter == "*":
                string += (letter*num)
                num = 0
            
            elif letter == "b":
                string += (" "*num)
                num = 0
        else:
            string += ("\n")

    print(string)
        