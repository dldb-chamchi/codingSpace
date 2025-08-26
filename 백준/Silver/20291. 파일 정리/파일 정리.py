N = int(input())

dic = {}
for i in range(N):
    _, fileExt = input().split('.')

    if fileExt in dic:
        dic[fileExt] += 1
    else:
        dic[fileExt] = 1

sortedDic = sorted(dic.items())

for fileExt, cnt in sortedDic:
    print(fileExt, cnt)
