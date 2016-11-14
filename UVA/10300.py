
def premium(size, animals, friend):
    average = float(size)/float(animals)    
    return (average*friend)*animals
    
cases = int(input())

for case in range(0,cases):
     farmers = int(input())
     cont = 0
     for farmer in range(0, farmers):
        data = input().split()
        size = int(data[0])
        animals = int(data[1])
        friend = int(data[2])
        cont += premium(size,animals,friend)
     
     print(round(cont))