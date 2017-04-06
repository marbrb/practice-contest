#Stepan and Vowles
e = ""
def ver(res,l, sig):
    global e
    if res[-1] == l:
        if sig == l:
            e = "e"
            return False
        if e =="e":
            return False

        if res[-2] != l:
            return True
        else:
            return False
    else:
        return True


def solution(s):
    global e
    vowels = ['a','e','i','o','u','y']
    res = []
    for i in range(len(s)):
        if len(res) == 0:
            res.append(s[i])
            continue

        if s[i] in vowels:
            if s[i] == 'e':
                if len(res) == 1:
                    res.append(s[i])
                else:
                    if ver(res, "e", s[i+1]):
                        res.append(s[i])
            elif s[i] == 'o':
                if len(res) == 1:
                    res.append(s[i])
                else:
                    if ver(res, "o", s[i+1]):
                        res.append(s[i])
            else:
                e = ""
                if res[-1] != s[i]:
                    res.append(s[i])
        else:
            e = ""
            res.append(s[i])
    return "".join(res)

def main():
    n = input()
    string = input()
    print(solution(string))


main()
