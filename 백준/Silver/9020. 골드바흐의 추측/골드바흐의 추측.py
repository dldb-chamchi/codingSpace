T = int(input())

def check(num):
  for i in range(2, num):
    if num%i == 0:
      return False
  return True


for _ in range(T):
  n = int(input())

  n1, n2 = n//2, n//2

  while True:
    if check(n1) and check(n2):
      print(n1, n2)
      break
    else:
      n1 -= 1
      n2 += 1