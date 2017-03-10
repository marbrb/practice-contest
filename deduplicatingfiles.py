from functools import reduce

def solution(strings):
    unics = []
    hash_list = []
    colisions = 0
    for string in strings:
        key = [lambda x,y: x^y, string]
        if key in hash_list:
            colisions += 1
            if string not in unics:
                unics.append(string)
        else:
            hash_list.append(key)





# def main():


# main()
