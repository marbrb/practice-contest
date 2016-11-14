rows = int(input()) 

def findSpace(lista):
    for x in lista:
        if " " in x:
            return True
    return False

def deleteSpaces(lista):
    for x in range(0,len(lista)):
        lista[x] = lista[x].rstrip(" ")
    
while rows != 0:
    linesList = list()
    listX = list()   
    nX = 0
    spaces = 0
    for x in range(0, rows):
        linesList.append(input())
    if findSpace(linesList):
        deleteSpaces(linesList)
        for row in linesList:
            numX=0
            for letter in row:
                if letter == "X":
                    numX += 1
                    
            listX.append(numX)
        for elemento in listX:
            nX += elemento
    
        maxRow = listX.index(max(listX))
        for letter in linesList[maxRow]:
            if letter == " ":
                spaces +=1
        print(25*rows-(nX+(spaces*rows)))      
    else:
        print("0")        
  
  
  
    rows = int(input())