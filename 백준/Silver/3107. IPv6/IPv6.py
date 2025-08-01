#백준 3107, IPv6

IPV6 = input().split(":")
blankCnt = [s for s in IPV6 if s != '']
flag = False

result = '' 
for string in IPV6:
    if string == '' and not flag:
        result += '0000:' * (8 - len(IPV6) + 1)
        flag = True
    else:
        result += '0'*(4-len(string)) + string + ':'

print(result[:-1])