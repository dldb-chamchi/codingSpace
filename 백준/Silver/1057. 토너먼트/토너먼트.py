N, jimin, hansu = map(int, input().split())

rounds = 0
while jimin != hansu:
    jimin = (jimin+1)//2
    hansu = (hansu+1)//2
    rounds += 1

print(rounds)