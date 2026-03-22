import datetime

Y, M, D = map(int, input().split())
y, m, d = map(int, input().split())

today = datetime.date(Y, M, D)
target = datetime.date(y, m, d)

diff = target - today

if (y > Y + 1000) or (y == Y + 1000 and (m, d) >= (M, D)):
  print("gg")
else:
  print("D", diff.days, sep='-')