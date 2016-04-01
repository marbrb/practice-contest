from sys import stdin
lines = stdin.read().splitlines()

for line in lines:
    cadena = str()
    for letter in line:
        if ord(letter) > 38 and ord(letter) < 133:
            cadena += (chr(ord(letter)-7))
    print(cadena)