left = []
right = []

string = input()

for i in range(len(string)):
    left.append(string[i])

M = int(input())

for _ in range(M):
    command = input().split()
    if command[0] == 'P':
        left.append(command[1])
    elif command[0] == 'L' and left:
        right.append(left.pop())
    elif command[0] == 'D' and right:
        left.append(right.pop())
    elif command[0] == 'B' and left:
        left.pop()

for l in left:
    print(l, end = '')

for i in range(len(right)-1, -1, -1):
    print(right[i], end='')