cash = int(input())

stock = list(map(int, input().split()))

def joon():
    Jsto = 0
    JCASH = cash
    for s in stock:
        if JCASH // s != 0:
            Jsto += JCASH // s
            JCASH = JCASH - ((JCASH // s)*s)
    return JCASH + Jsto * stock[len(stock)-1]


def seong():
    upp = 0
    low = 0
    Ssto = 0
    SCASH = cash
    before = stock[0]
    for s in stock:
        if s > before:
            upp += 1
            low = 0
        if s < before:
            upp = 0
            low += 1
        if SCASH // s != 0:
            if upp >= 3:
                SCASH += Ssto*s
                Ssto = 0                
            elif low >= 3:
                Ssto += SCASH // s
                SCASH = SCASH - ((SCASH // s)*s)

        before = s
    return SCASH + Ssto * stock[len(stock)-1]

j = joon()
s = seong()

if j > s:
    print("BNP")
elif j < s:
    print("TIMING")
else:
    print("SAMESAME")