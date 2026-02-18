N = int(input())

outCar = {}
cars = []
cnt = 0

for idx in range(N):
  car = input()
  cars.append(car)

for idx in range(N):
  car = input()
  outCar[car] = idx

#idx = 들어올 때 몇번째 차
for idx in range(1, N): #첫번째 차는 추월이 불가능
  carNumber = cars[idx] #들어올 떄 차
  for i in range(idx):
    bCarNumber = cars[i]
    if outCar[bCarNumber] > outCar[carNumber]:
      cnt += 1
      break

print(cnt)