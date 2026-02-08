N = int(input())
M = int(input())

like = list(map(int, input(). split()))
frame = []

# [추천횟수, 시간, 번호]

frame.append([1, M, like[0]])

cnt = M-1

for j in range(1, len(like)):
    found = False
    for i in range(len(frame)):
        if like[j] == frame[i][2]:
            frame[i][0] += 1
            found = True
            break

    if not found:    
        if len(frame) >= N:
            frame.sort(key = lambda x:(-x[0], x[1]))
            frame.pop()
        frame.append([1, cnt, like[j]])
        
    cnt -= 1

frame.sort(key= lambda x:x[2])

for n in frame:
    print(n[2], end=' ')
