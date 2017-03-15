cases = input()

di = {"Tetrahedron" :4, "Cube":6, "Octahedron":8,"Dodecahedron":12, "Icosahedron":20}
sol = 0

for case in range(int(cases)):
    a=input()
    sol += di[a]
print(sol)
