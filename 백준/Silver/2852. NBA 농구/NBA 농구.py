N = int(input().strip())

def toTime(time):
    m = time//60
    s = time%60
    print(f"{m:02d}:{s:02d}")

team1 = []
team2 = []
for _ in range(N):
    team, time = input().split()
    m, s = map(int, time.split(':'))
    if team == '1':
        team1.append((m, s))
    else:
        team2.append((m, s))

events = []
for m, s in team1:
    events.append((m*60+s, 1))
for m, s in team2:
    events.append((m*60+s, 2))
events.sort()

score1 = 0; score2 = 0
winTime1 = 0; winTime2 = 0
lastTime = 0
END = 48*60

for  currTime, team in events:
    if score1 > score2:
        winTime1 += currTime-lastTime
    elif score2 > score1:
        winTime2 += currTime-lastTime

    if team == 1:
        score1 += 1
    else:
        score2 += 1

    lastTime = currTime

if score1 > score2:
    winTime1 += END-lastTime
elif score2 > score1:
    winTime2 += END-lastTime

toTime(winTime1)
toTime(winTime2)
