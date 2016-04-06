while True:
    round = int(input())
    if round == -1:
        break
    solution = input()
    word = input()
    errors = 0
    errorsList = list()
    newWord = str()
    for letter in word:
        if letter not in newWord:
            newWord += letter
            
    for letter in newWord:
        if letter in solution:            
            solution =  solution.replace(letter, "")
        else:
            if letter not in errorsList:
                errors += 1
                if errors == 7:
                    break
                errorsList.append(letter)
                
    print("Round", round)
            
    
    
    if errors >= 7 and solution != "":
        print("You lose.")
    elif solution == "":
        print("You win.")
    else:
        print("You chickened out.")
        