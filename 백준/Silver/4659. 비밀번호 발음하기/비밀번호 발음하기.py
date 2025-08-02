#백준, 4659 비밀번호 발음하기

import sys
input = sys.stdin.readline

zaeum = ['b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z']
moeum = ['a', 'e', 'i', 'o', 'u']

while True:
    string = input().strip()
    flag = False

    if string == "end":
        break
    if all(c not in moeum for c in string):
        print("<{}> is not acceptable.".format(string))
        continue

    fakeString = string + "0"
    for i in range(len(fakeString)-1):
        if fakeString[i] == fakeString[i+1] and (fakeString[i] != 'e' and fakeString[i] != 'o'):
            print("<{}> is not acceptable.".format(string))
            flag = True
            break
    if flag:
        continue
    
    n = len(string)
    if n < 3:
        pass
    else:
        for i in range(n-2):
            window = string[i:i+3]
            if all(c in moeum for c in window) or all(c in zaeum for c in window):
                print("<{}> is not acceptable.".format(string))
                flag = True
                break
    if flag:
        continue

    print("<{}> is acceptable.".format(string))