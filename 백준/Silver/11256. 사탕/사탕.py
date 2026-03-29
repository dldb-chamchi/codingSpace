for _ in range(int(input())):
  candy, box = map(int, input().split())
  boxes = []

  for _ in range(box):
    a, b = map(int, input().split())
    boxes.append(a*b)
  
  boxes.sort(reverse = True)

  sums = 0
  cnt = 0
  for b in boxes:
    cnt += 1
    sums += b
    if sums >= candy:
      print(cnt)
      break