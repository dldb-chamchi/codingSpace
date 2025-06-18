N = int(input())

dict = {}
li = []
ans = 0
for _ in range(N):
    name, ring = input().split()

    if ring == '-': 
        continue

    if ring in dict:
        dict[ring] += [name]
    else:
        dict[ring] = [name]

for ring, names in dict.items():
    if len(names) == 2:
        ans += 1
        li.append(names)

print(ans)

for one, two in li:
    print(one, two)