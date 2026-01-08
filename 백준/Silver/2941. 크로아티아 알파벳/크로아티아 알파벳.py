string = input()

crotia = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]


for ch in crotia:
  string = string.replace(ch, '#')

print(len(string))
