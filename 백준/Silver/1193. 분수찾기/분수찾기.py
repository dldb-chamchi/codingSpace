X = int(input())

num = 1

while X > num:
  X -= num
  num += 1
  
if num % 2 == 0: print(f"{X}/{num+1-X}")
else : print(f"{num+1-X}/{X}")