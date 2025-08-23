N = input()
i = 0
while True:
    i+=1
    num = str(i)
    while len(num) and len(N):
        if num[0] == N[0]:
            N = N[1:]
        num = num[1:]
        
    if not N:
        print(i)
        break
